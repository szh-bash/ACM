#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, m, cnt, next[1000000], nu[1000000], fa[200000][30], dep[200000];
int read(){
	int p=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
void add(int u, int v){
	next[++cnt]=next[u];next[u]=cnt;nu[cnt]=v;
}
void dfs(int u, int father){
	fa[u][0]=father;
	for (int j=1;fa[u][j-1];j++)
		fa[u][j]=fa[fa[u][j-1]][j-1];
	for (int j=next[u];j;j=next[j]){
		int v=nu[j];
		if (v!=father) dep[v]=dep[u]+1, dfs(v,u);
	}
}
int getfather(int u, int v){
	if (dep[u]<dep[v]) swap(u,v);
	for (int j=20;dep[u]>dep[v];j--){
		if (!fa[u][j]) continue;
		if (dep[fa[u][j]]<dep[v]) continue;
		u=fa[u][j]; 
	}
	if (u==v) return u;
	for (int j=20;j>=0;j--){
		if (!fa[u][j]) continue;
		if (fa[u][j]==fa[v][j]) continue;
		u=fa[u][j];
		v=fa[v][j];
	}
	return fa[u][0];
}
int main(){
	n=read();
	m=read();
	cnt=n;
	for (int i=2;i<=n;i++){
		int u=read();
		add(u,i);
		add(i,u);
	}
	dfs(1,0);
	for (int i=1;i<=m;i++){
		int a=read(), b=read(), c=read();
		int f1=getfather(a,b), f2=getfather(b,c), f3=getfather(a,c);
		int af1=dep[a]+dep[b]-dep[f1]*2, af2=dep[b]+dep[c]-dep[f2]*2, af3=dep[a]+dep[c]-dep[f3]*2;
		int a1=af1+af2-af3, a2=af1+af3-af2, a3=af2+af3-af1;
		int ans=max(a1,max(a2,a3))/2+1;
		printf("%d\n", ans);
	}
	return 0;
}
