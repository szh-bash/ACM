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
#define N 500000
#define M (N*3)
typedef long long ll;
using namespace std;
int n, ct;
int cnt, nex[M], nu[M], g[N], ans_t;
ll f[N], a[N], ans_max;
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
void dfs(int u, int fa){
	f[u]=a[u];
	g[u]=0;
	for (int j=nex[u];j;j=nex[j]){
		int v=nu[j];
		if (v==fa) continue;
		ll tmp=ans_max;
		dfs(v, u);
		if (ans_max>tmp) tmp=ans_max, g[u]=0;
		if (f[v]>0){
			g[u]|=g[v];
			f[u]+=f[v];
		}
	}
	if (f[u]>ans_max) ans_max=f[u], ans_t=1, g[u]=1;
	else
		if (f[u]==ans_max && !g[u]) ans_t++, g[u]=1;
}
int main(){
	cnt=n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<n;i++){
		int u=read(), v=read();
		add(u,v);
		add(v,u);
	}
	ans_max=-1000000100;
	ans_t=0;
	dfs(1,0);
	cout<<ans_max*ans_t<<' '<<ans_t<<endl;
	return 0;
}
