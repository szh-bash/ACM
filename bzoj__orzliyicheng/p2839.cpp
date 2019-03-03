#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 2000000
#define mo 1000000007
typedef long long ll;
using namespace std;
int n, k;
ll f[N], g[N], q[N];
ll power(ll a, int b){
	ll c=1;
	while (b){
		if (b&1) c=c*a%mo;
		a=a*a%mo;
		b>>=1;
	}
	return c;
}
ll C(int n, int k){
	return (f[n]*power(f[k],mo-2)%mo)*power(f[n-k],mo-2)%mo;
}
int main(){
	cin>>n>>k;
	f[0]=1;
	for (int i=1;i<=n;i++) f[i]=f[i-1]*i%mo;
	g[0]=1;
	q[0]=1;
	for (int i=1;i<=n;i++)
		g[i]=(g[i-1]+q[i-1])%mo,
		q[i]=(q[i-1]*2+g[i-1])%mo;
	cout<<C(n,k)*g[n-k]%mo<<endl;
	for (int i=1;i<=n;i++){
		
	}
	return 0;
}
