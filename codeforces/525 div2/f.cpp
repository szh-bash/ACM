#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 500005
#define M (N*3)
typedef long long ll;
using namespace std;
int n, nu[M], nex[M], cnt, fa[N][30], a[N], m;
ll ans;
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') 
		ch=='-'?q=-1:0,
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
void add(int u, int v){
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;
}
void dfs(int u, int ff){
	fa[u][0]=ff;
	for (int j=1;fa[fa[u][j-1]][j-1];j++)
		fa[u][j]=fa[fa[u][j-1]][j-1];
	ll mn=(ll)2000000*2000000000;
	int j=0;
	for (;fa[u][j];j++)
		mn=min(mn,(ll)(j+1)*a[fa[u][j]]+a[u]);
	mn=min(mn,(ll)(j+1)*a[m]+a[u]);
	if (ff) ans+=mn;
	for (int j=nex[u];j;j=nex[j]){
		int v=nu[j];
		if (v==ff) continue;
		dfs(v,u);
	}
}
int main(){
	cnt=n=read();
	m=1;
	for (int i=1;i<=n;i++)
		a[i]=read(),
		(a[i]<a[m]?m=i:0);
	for (int i=1;i<n;i++){
		int u=read(), v=read();
		add(u, v);
		add(v, u);
	}
	dfs(m,0);
	cout<<ans<<endl;
	return 0;
}
