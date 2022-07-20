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
int n, a[N];
ll f[N], g[N];
void solve(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	g[n]=f[1]=1ll*99999999;
	f[0]=g[n+1]=0;
	if (n&1){
		ll ans=0;
		for (int i=2;i<n;i+=2) ans+=max(0,max(a[i+1]-a[i]+1, a[i-1]-a[i]+1));
		cout<<ans<<endl;
	}
	else{
		for (int i=2;i<n;i+=2) f[i] = f[i-2] + max(0,max(a[i+1]-a[i]+1, a[i-1]-a[i]+1));
		for (int i=n-1;i>1;i-=2) g[i] = g[i+2] + max(0,max(a[i+1]-a[i]+1, a[i-1]-a[i]+1));
		ll ans=min(f[n-2], g[3]);
		for (int i=3;i<n;i+=2) ans=min(ans, f[i-1]+g[i+2]);
		cout<<ans<<endl;
	}
}
int main(){
	for (int _=read();_;_--) solve();
	return 0;
}
