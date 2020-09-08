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
#define mo 1000000007
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
int power(ll a, int b){
	ll c=1;
	while (b){
		if (b&1) c=c*a%mo;
		a=a*a%mo;
		b>>=1;
	}
	return c;
}
#define N 200005
#define M N*3 
int n, a, b, da, db, d[N], fa[N], flag[N], maxR, p;
int nex[M], nu[M], cnt; 
void add(int u, int v){
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;
}
void dfs(int u, int fat){
	fa[u]=fat;
	for (int j=nex[u];j;j=nex[j]){
		int v=nu[j];
		if (v==fat) continue;
		dfs(v,u);
	}
}
int dfs2(int u, int fat){
	d[u]=d[fat]+1;
	if (d[u]>maxR) maxR=d[u], p=u;
	for (int j=nex[u];j;j=nex[j]){
		int v=nu[j];
		if (v==fat) continue;
		dfs2(v,u);
	}
}
void solve(){
	cnt=n=read();a=read();b=read();da=read();db=read();
	for (int i=1;i<=n;i++) nex[i]=flag[i]=0;
	for (int i=1;i<n;i++){
		int u=read(), v=read();
		add(u,v);
		add(v,u);
	}
	dfs(1,0);
	int ct=0, ori=0, j;
	for (j=a;j;j=fa[j]) flag[j]=++ct;
	for (j=b;j && !flag[j];j=fa[j]) ++ori;
	ori+=flag[j]-1;
	if (ori<=da || db<=2*da){
		puts("Alice");
		return;
	}
	dfs2(1,maxR=0);
	dfs2(p,maxR=0);
	if (maxR-1<=2*da) puts("Alice");else puts("Bob");
}
int main(){
	for (int _=read();_;_--) solve();
	return 0;
}
