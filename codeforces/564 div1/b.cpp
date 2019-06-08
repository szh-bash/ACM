#include <map>
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
#define N 300000
#define M 800000
#define mo 998244353
typedef long long ll;
using namespace std;
int n, cnt, nex[M], nu[M], son[N];
ll ans=1, f[N];
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
void add(int u, int v){
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;
}
void dfs(int u, int fa){
	for (int j=nex[u];j;j=nex[j]){
		int v=nu[j];
		if (v==fa) continue;
		dfs(v,u);
		son[u]++;
	}
//	ans=ans*(u==1?f[son[u]]:f[son[u]+1])%mo;
	ans=ans*f[son[u]+1]%mo;
}
ll power(ll a, int b){
	ll c=1;
	while (b){
		if (b&1) c=c*a%mo;
		a=a*a%mo;
		b>>=1;
	}
	return c;
}
int main(){
	cnt=n=read();
	for (int i=1;i<n;i++){
		int u=read(), v=read();
		add(u,v);
		add(v,u);
	}
	f[0]=1;
	for (int i=1;i<=n+1;i++) f[i]=f[i-1]*i%mo;
	dfs(1,0);
	ans=ans*power(son[1]+1, mo-2)%mo;
	cout<<(ans*n%mo)<<endl;
	return 0;
}
