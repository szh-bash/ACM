#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 2000000
#define mo 998244353
typedef long long ll;
using namespace std;
int n;
ll f[N], ans, rev[N];
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') 
		ch=='-'?q=-1:0,
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
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
	n=read();
	f[0]=1;
	for (int i=1;i<=n;i++)
		f[i]=f[i-1]*i%mo,
		rev[i]=power(f[i],mo-2);
	ans=f[n];
	for (int i=1;i<n;i++){
		ans=(ans+(f[n]*rev[n-i]%mo)*(f[n-i]-1)%mo)%mo;
	}
	cout<<(ans+mo)%mo<<endl;
	return 0;
}
