#include <map>
#include <cmath>
#include <ctime>
#include <queue>
#include <bitset>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 200000
#define M 500000
#define mo 1000000007
typedef long long ll;
using namespace std;
int n, root, sum, cnt;
int nex[M], nu[M], va[M], co[M], size[N], f[N], flag[N], r[N], b[N];
ll ans=1, g[N], q[N*10][5];
int read(){
	int p=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
void add(int u, int v, int w, int c){
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;va[cnt]=w;co[cnt]=c;
}
void getroot(int u, int fa){
	size[u]=1;f[u]=0;
	for (int j=nex[u];j;j=nex[j]){
		int v=nu[j];
		if (flag[v] || v==fa) continue;
		getroot(v,u);
		size[u]+=size[v];
		if (size[v]>f[u]) f[u]=size[v];
	}
	if (sum-size[u]>f[u]) f[u]=sum-size[u];
	if (f[u]<f[root]) root=u;
}
int power(ll a, int b){
	ll c=1;
	while (b){
		if (b&1){
			c=c*a;
			if (c>mo) c%=mo;
		}
		a=a*a;
		if (a>mo) a%=mo;
		b>>=1;
	}
	return c;
}
void getans(int u){
	int count=0;
	ll s1=1, s2=1;
	for (int j=2*r[u]-b[u]+2*n;j;j-=j&(-j)) count+=q[j][0];	
	for (int j=2*r[u]-b[u]+2*n;j;j-=j&(-j)){
		s1=s1*q[j][1];
		if (s1>mo) s1%=mo;
	}
	for (int j=r[u]-2*b[u]+2*n-1;j;j-=j&(-j)) count-=q[j][2];
	for (int j=r[u]-2*b[u]+2*n-1;j;j-=j&(-j)){
		s2=s2*q[j][3];
		if (s2>mo) s2%=mo;
	}
	s1=s1*power(s2,mo-2);
	if (s1>mo) s1%=mo;
	s1=s1*power(g[u],count);
	if (s1>mo) s1%=mo;
	ans=ans*s1;
	if (ans>mo) ans%=mo;
}
void dfs(int u, int fa){
	size[u]=1;
	for (int j=nex[u];j;j=nex[j]){
		int v=nu[j];
		if (flag[v] || v==fa) continue;
		g[v]=g[u]*va[j];
		if (g[v]>mo) g[v]%=mo;
		r[v]=r[u]+co[j];
		b[v]=b[u]+(!co[j]);
		getans(v);
		dfs(v,u);
		size[u]+=size[v];
	}
}
void modi_(int u){
	for (int j=b[u]-2*r[u]+2*n;j<=4*n;j+=j&(-j)){
		q[j][0]++,
		q[j][1]=q[j][1]*g[u];
		if (q[j][1]>mo) q[j][1]%=mo;
	}
	for (int j=2*b[u]-r[u]+2*n;j<=4*n;j+=j&(-j)){
		q[j][2]++,
		q[j][3]=q[j][3]*g[u];
		if (q[j][3]>mo) q[j][3]%=mo;
	}
}
void modify(int u, int fa){
	for (int j=nex[u];j;j=nex[j]){
		int v=nu[j];
		if (flag[v] || v==fa) continue;
		modi_(v);
		modify(v,u);
	}
}
void calc(int u, int w, int c){
	g[u]=w;r[u]=c;b[u]=!c;
	getans(u);
	dfs(u,0);
	modi_(u);
	modify(u,0);
}
void clear(int u, int fa){
	for (int j=nex[u];j;j=nex[j]){
		int v=nu[j], ct=power(g[v],mo-2);
		if (flag[v] || v==fa) continue;
		for (int k=b[v]-2*r[v]+2*n;k<=4*n;k+=k&(-k)){
			q[k][0]--,
			q[k][1]=q[k][1]*ct;
			if (q[k][1]>mo) q[k][1]%=mo;
		}
		for (int k=2*b[v]-r[v]+2*n;k<=4*n;k+=k&(-k)){
			q[k][2]--,
			q[k][3]=q[k][3]*ct;
			if (q[k][3]>mo) q[k][3]%=mo;
		}
		clear(v,u);
	}
}
void solve(int u){
	flag[u]=1;
	for (int j=nex[u];j;j=nex[j]){
		int v=nu[j];
		if (flag[v]) continue;
		calc(v,va[j],co[j]);
	}
	clear(u,0);
	for (int j=nex[u];j;j=nex[j]){
		int v=nu[j];
		if (flag[v]) continue;
		root=0;sum=size[v];
		getroot(v,0);
		solve(root);
	}
}
void pre(){
	f[0]=n*2;
	for (int j=2*n;j<=4*n;j+=j&(-j)) q[j][0]=q[j][2]=1;
	for (int i=1;i<=4*n;i++) q[i][1]=q[i][3]=1;
}
int main(){
	for (int i=(cnt=sum=n=read())-1;i;i--){
		int u=read(), v=read(), w=read(), c=read();
		add(u,v,w,c);
		add(v,u,w,c); 
	}
	pre();
	getroot(1,0);
	solve(root);
	cout<<ans<<endl;
	return 0;
}
