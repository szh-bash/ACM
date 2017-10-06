#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, q, www, ff, le[3005], flag[3005], ri[3005], anss[3005], cnt[3005], a[3005][3005], nex[3005][3005*2], nu[3005][3005*2], ans_final[400005];
int f[3005][3005];
struct lalala{
	int u, v, n, k;
}l[400005];
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') (ch=='-'?(q=-1):0), ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
inline void add(int x, int u, int v){
	nex[x][++cnt[x]]=nex[x][u];nex[x][u]=cnt[x];nu[x][cnt[x]]=v;
}
inline void dfs(int u, int x, int v){
	flag[x]=v;
	int i=1;
	if (!ff)
		for (;i<=a[x][0];i++)
			if (!flag[a[x][i]]){
				add(u,x,a[x][i]);
				dfs(u,a[x][i],v+1);
				if (ff) break;
			}
			else
				if (flag[a[x][i]]>0) {
					ff=a[x][i];
					break;
				}
	if (ff)
		for (;i<=a[x][0];i++)
			if (!flag[a[x][i]]) dfs(u,a[x][i],-1);
			else
				if (flag[a[x][i]]>0 && flag[a[x][i]]<flag[ff]) ff=a[x][i];
	flag[x]=-1;
	if (ff==x) ff=0;
}
void dfs2(int u, int x){
	anss[++www]=x;
	if (f[u][x]){
		for (int j=f[u][x];l[j].v==x && l[j].u==u;j++)
			if (l[j].k<=www) ans_final[l[j].n]=anss[l[j].k];
	}
	for (int j=nex[u][x];j;j=nex[u][j])	dfs2(u,nu[u][j]);
	--www;
}
bool cmp(lalala a, lalala b){
	if (a.u<b.u) return 1;
	if (a.u>b.u) return 0;
	if (a.v<b.v) return 1;
	return 0;
}
int main(){
	n=read();m=read();q=read();
	for (int i=1;i<=m;i++){
		int u=read(), v=read();
		a[u][v]=1;
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++)
			if (a[i][j]) a[i][++a[i][0]]=j;
	}
	for (int i=1;i<=n;i++) cnt[i]=n;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++) flag[j]=0;
		dfs(i,i,1);
	}
	for (int i=1;i<=q;i++) l[i].u=read(), l[i].v=read(), l[i].k=read(), l[i].n=i;
	sort(l+1,l+1+q,cmp);
	for (int i=1;i<=q;i++)
		if (!f[l[i].u][l[i].v]) f[l[i].u][l[i].v]=i;
	for (int i=1;i<=n;i++)
		dfs2(i,i);
	for (int i=1;i<=q;i++) printf("%d\n", ans_final[i]?ans_final[i]:-1);
	return 0;
}
