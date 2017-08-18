#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 100000
using namespace std;
int n, ans, cnt, sum, t[2][3], va[N], nu[N], next[N], son[N], f[N], root;
bool vis[N];
int rd(){
	int p=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
void add(int u, int v, int w){
	next[++cnt]=next[u];next[u]=cnt;nu[cnt]=v;va[cnt]=w;
}
void read(){
	cnt=n=rd();
	for (int i=1;i<n;i++){
		int u=rd(), v=rd(), w=rd()%3;
		add(u,v,w);
		add(v,u,w);
	}
}
void getroot(int t, int fa){
	son[t]=1;f[t]=0;
	for (int j=next[t];j;j=next[j]){
		int v=nu[j];
		if (vis[v] || v==fa) continue;
		getroot(v,t);
		son[t]+=son[v];
		f[t]=max(son[v],f[t]);
	}
	f[t]=max(f[t],sum-son[t]);
	if (f[t]<f[root]) root=t;
}
void getdeep(int u, int fa, int f){
	t[1][f]++;
	son[u]=1;
	for (int j=next[u];j;j=next[j]){
		int v=nu[j];
		if (vis[v] || v==fa) continue;
		getdeep(v,u,(f+va[j])%3);
		son[u]+=son[v];
	}
}
void calc(int x, int va){
	t[1][0]=t[1][1]=t[1][2]=0;
	getdeep(x,0,va);
	ans+=t[0][1]*t[1][2]+t[0][2]*t[1][1]+t[0][0]*t[1][0]+t[1][0];
	t[0][0]+=t[1][0];
	t[0][1]+=t[1][1];
	t[0][2]+=t[1][2];
}
void solve(int x){
	vis[x]=1;
	t[0][0]=t[0][1]=t[0][2]=0;
	for (int j=next[x];j;j=next[j]){
		int v=nu[j];
		if (vis[v]) continue;
		calc(v, va[j]);
	}
	for (int j=next[x];j;j=next[j]){
		int v=nu[j];
		if (vis[v]) continue;
		root=0;sum=son[v];
		getroot(v,0);
		solve(root);
	}
}
int gcd(int a, int b){return !b?a:gcd(b,a%b);}
int main(){
	read();
	sum=n;
	f[0]=n;
	getroot(1,0);
	solve(root);
	ans=ans*2+n;
	int gys=gcd(ans,n*n);
	cout<<ans/gys<<'/'<<n*n/gys;
	return 0;
}
