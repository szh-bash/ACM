#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define eps 1e-5
#define N 500000
typedef long long ll;
int n, m, cnt, b[N], d[N], le[N], ri[N], next[N], nu[N];
ll a[N], A[N];
using namespace std;
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9'){
		if (ch=='-') q=-1;
		ch=getchar();
	}
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
void add(int u, int v){
	next[++cnt]=next[u];next[u]=cnt;nu[cnt]=v;
}
void dfs(int u, int fa){
	le[u]=++cnt;
	for (int j=next[u];j;j=next[j])
		if (nu[j]!=fa)
			d[nu[j]]=d[u]+1, dfs(nu[j],u);
	ri[u]=cnt;
}
void addin(ll *a, int i, ll x){
	for (;i<=n;i+=i&(-i)) a[i]+=x;
}
ll calc(ll *a, int i){
	ll ans=0;
	for (;i;i-=i&(-i)) ans+=a[i];
	return ans;
}
int main(){
	cnt=n=read();m=read();
	for (int i=1;i<=n;i++) b[i]=read();
	for (int i=1;i<n;i++){
		int u=read(), v=read();
		add(u,v);
		add(v,u);
	}
	dfs(1,cnt=0);
	for (int i=1;i<=n;i++){
		addin(a,le[i],b[i]);
		addin(a,ri[i]+1,-b[i]);
	}
	for (int i=1;i<=m;i++){
		int op=read(), x=read();
		if (op==1){
			ll y=read();
			addin(a,le[x],y);
			addin(a,ri[x]+1,-y);
		}
		if (op==2){
			ll y=read();
			addin(a,le[x],y*(-d[x]+1));
			addin(a,ri[x]+1,y*(d[x]-1));
			addin(A,le[x],y);
			addin(A,ri[x]+1,-y);
		}
		if (op==3){
			printf("%lld\n", calc(a,le[x])+calc(A,le[x])*d[x]);
		}
	}
	return 0;
}
