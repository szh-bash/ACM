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
#include <tr1/unordered_map>
#define mo 1000000007
typedef long long ll;
using namespace std;
using namespace std::tr1;
ll k, l, r, t, x, y;
unordered_map<ll, int> f;
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
void solve(){
}
int main(){
	cin>>k>>l>>r>>t>>x>>y;
	if (k+y<=r) k+=y;
	if (k-x<l){
		puts("No");
		return 0;
	}
	if (x>y){
		ll dl = x-y;
		ll d = (k-(l+x-1)-1)/dl+1;
		if (d+1>t) puts("Yes");
		else puts("No");
		return 0;
	}
	else if (x==y){
		if (k-x>=l) puts("Yes");
		else puts("No");
		return 0;
	}
	for (ll i=1, d=0;i<=x && d<t && !(f[k%x]);i++){
		f[k%x]=1;
		d+=(k-l)/x;
		k-=(k-l)/x*x;
		if (d>=t) break;
		if (k+y<=r) k+=y;
		if (k-x<l){
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	return 0;
}
