#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;
int n, m, l;
int p[100], q[100];
char s[1000];
ll gcd(ll a, ll b){ return !b?a:gcd(b,a%b);}
int main(){
	cin>>n>>l>>m;
	for (int i=0;i<m;i++) cin>>p[i]>>q[i];
	for (int i=1;i<=n;i++){
		cin>>s+1;
		ll u=1, v=1;
		for (int i=1;i<=l;i++) u*=p[s[i]-'A'], v*=q[s[i]-'A'];
		ll gys=gcd(u,v);
		u/=gys;v/=gys;
		printf("%.2lf\n", (double)u/v);
	}
	return 0;
}
