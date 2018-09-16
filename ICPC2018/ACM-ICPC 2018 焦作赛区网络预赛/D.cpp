#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
typedef long long ll;
typedef long double ld;
using namespace std;
ll n, m;
ld c(ll n, ll m){
	if (n<m) return 0;
	if (n-m<m) return c(n,n-m);
	ld ans=1;
	for (ll i=0;i<m;i++) ans*=(n-i);
	for (ll i=1;i<=m;i++) ans/=i;
	return ans;
}
ld f(ll m, ll n, ll k){
	if (n*(k-1)<m) return 0;
	ld ans=0;
	for (ll i=0, u=1;i<=n && i*k<=m;i++, u=-u)
		ans+=u*c(m+n-1-i*k,m-i*k)*c(n,i);
	return ans;
}
int main(){
	while (~scanf("%lld%lld", &m, &n)){
		ld ans=0;
		for (ll i=1;i<=m;i++)
			ans+=i*(f(m,n,i+1)-f(m,n,i));
		printf("%.4Lf\n", ans/f(m,n,m+1));
	}
	return 0;
}
