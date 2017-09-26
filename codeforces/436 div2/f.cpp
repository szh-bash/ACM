#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, q, www, le[3005], flag[3005], ri[3005], anss[3005], cnt[3005], a[3005][3005], nex[3005][3005*2], nu[3005][3005*2], ans_final[400005];
bool f[3005][3005];
struct lalala{
	int u, v, n, k;
}l[400005];
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') (ch=='-'?q=-1:0), ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
void add(int x, int u, int v){
	nex[x][++cnt[x]]=nex[x][u];nex[x][u]=cnt[x];nu[x][cnt[x]]=v;
}
int dfs(int u, int x, int v){
	flag[x]=v;
	int ff=0;
	if (v>0)
	for (int i=1;i<=n;i++)
		if (a[x][i]){
			if (!flag[i]){
				add(u,x,i);
				ff=dfs(u,i,v+1);
				if (ff && flag[ff]<=v) break;
			}
			else
				if (flag[i]>0) {
					ff=i;
					break;
				}
		}
	if (ff && flag[ff]<=v || v<0)
		for (int i=1;i<=n;i++)
			if (a[x][i] && !flag[i]) dfs(u,i,-1);
	flag[x]=-1;
	return ff;
}
void dfs2(int u, int x){
	anss[++www]=x;
	if (f[u][x]){
		int lle=le[u]-1, rri=ri[u];
		while (lle<rri-1){
			int mid=lle+rri>>1;
			if (l[mid].v<x) lle=mid;else rri=mid;
		}
		for (int j=rri;j<=ri[u] && l[j].v==x;j++)
			if (l[j].k<=www) ans_final[l[j].n]=anss[l[j].k];else ans_final[l[j].n]=-1;
	}
	for (int j=nex[u][x];j;j=nex[u][j]){
		int v=nu[u][j];
		dfs2(u,v);
	}
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
	for (int i=1;i<=n;i++) cnt[i]=n;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++) flag[j]=0;
		dfs(i,i,1);
	}
	for (int i=1;i<=q;i++) l[i].u=read(), l[i].v=read(), l[i].k=read(), l[i].n=i, f[l[i].u][l[i].v]=1;
	sort(l+1,l+1+q,cmp);
	for (int i=1;i<=q;i++)
		if (l[i].u!=l[i-1].u) le[l[i].u]=i, ri[l[i-1].u]=i-1;ri[l[q].u]=q;
	for (int i=1;i<=n;i++)
		dfs2(i,i);
	for (int i=1;i<=q;i++) printf("%d\n", ans_final[i]?ans_final[i]:-1);
	return 0;
}
