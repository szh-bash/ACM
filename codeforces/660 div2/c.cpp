#include <map>
#include <set> 
#include <ctime>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=='-'?q=-1:0, ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
ll readll(){
	ll p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=='-'?q=-1:0, ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
#define N 200005
#define M (N*4)
int ans;
int n, m, cnt;
int f[N], p[N], h[N];
int nex[M], nu[M];
void add(int u, int v){
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;
}
void dfs0(int u, int fa){
	f[u]=p[u];
	for (int j=nex[u];j;j=nex[j]){
		int v=nu[j];
		if (v==fa) continue;
		dfs0(v, u);
		f[u]+=f[v];
	}
}
void dfs1(int u, int fa){
	int sum=p[u];
	for (int j=nex[u];j;j=nex[j]){
		int v=nu[j];
		if (v==fa) continue;
		dfs1(v, u);
		sum+=h[v];
	}
	if (sum<h[u]) ans=0;
}
void solve(){
	cnt=n=read(), m=read();
	for (int i=1;i<=n;i++) p[i]=read(), nex[i]=0;
	for (int i=1;i<=n;i++) h[i]=read();
	for (int i=1;i<n;i++){
		int u=read(), v=read();
		add(u, v);
		add(v, u);
	}
	dfs0(1,0);
	for (int i=1;i<=n;i++)
		if (f[i]<h[i] || ((f[i]-h[i])&1)){
			puts("NO");
			return;
		}
		else h[i]=(f[i]-h[i])>>1;
	ans=1;
	dfs1(1,0);
	if (ans) puts("YES");
	else puts("NO");
}
int main(){
	for (int _=read();_;_--) solve();
	return 0;
}
