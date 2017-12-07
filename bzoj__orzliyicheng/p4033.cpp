#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 5000
#define M 200000
typedef long long ll;
int  n, m, cnt, next[M], nu[M], va[M], size[N];
ll f[N][N], g[N];
using namespace std;
int read(){
	int p=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
void add(int u, int v, int w){
	next[++cnt]=next[u];next[u]=cnt;nu[cnt]=v;va[cnt]=w;
}
void solve(int u, int v, ll w){
	int k=min(size[u]+size[v],m);
	for (int i=0;i<=k;i++) g[i]=0;
	for (int i=0;i<=min(size[u],m);i++)
		for (int j=0;j<=min(size[v],m-i);j++)
			g[i+j]=max(g[i+j],f[u][i]+f[v][j]+w*((m-j)*j+(n-m-size[v]+j)*(size[v]-j)));
	for (int i=0;i<=k;i++) f[u][i]=max(f[u][i],g[i]);
}
void dfs(int u, int fa){
	size[u]=1;
	for (int j=next[u];j;j=next[j])
		if (nu[j]!=fa){
			int v=nu[j];
			dfs(v,u);
			solve(u,v,va[j]);
			size[u]+=size[v];
		}
}
int main(){
	cnt=n=read();m=read();
	for (int i=1;i<n;i++){
		int u=read(), v=read(), w=read();
		add(u,v,w);
		add(v,u,w);
	}
	dfs(1,0);
	cout<<f[1][m]<<endl;
	return 0;
}
