#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define mo 1000000007
typedef long long ll;
using namespace std;
ll power(ll a, ll b){
	ll c=1;
	while (b){
		if (b&1) c=c*a%mo;
		a=a*a%mo;
		b>>=1;
	}
	return c;
}
int main(){
	ll n, m, k, ans;
	cin>>n>>m>>k;
	if (k==-1 && ((n&1)^(m&1))){
		cout<<0<<endl;
		return 0;
	}
	ans=power(2,n-1);
	ans=power(ans,m-1)%mo;
	cout<<ans<<endl;
	return 0;
}
