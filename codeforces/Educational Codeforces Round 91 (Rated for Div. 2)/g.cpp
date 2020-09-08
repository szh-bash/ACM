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
bool cmp(int x, int y){return x>y;}
#define mo 998244353
int power(ll a, int b){
	ll c=1;
	while (b){
		if (b&1) c=c*a%mo;
		a=a*a%mo;
		b>>=1;
	}
	return c;
}
#define N 300005
int n, a[N], pre[N];
int main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n,cmp);
	for (int i=1;i<=n;i++) pre[i]=(pre[i-1]+a[i])%mo;
	for (int k=1;k<=n;k++){
		int low=(n-k)/k;
		ll ans=0;
		for (int j=1;j<=low;j++)
			ans=(ans+1ll*(pre[(j+1)*k]-pre[j*k])*j)%mo;
		ans=(ans+1ll*(pre[n]-pre[low*k+k])*(low+1))%mo;
		printf("%I64d%s", (ans*power(n,mo-2)%mo+mo)%mo, k==n?"\n":" ");
	}
	return 0;
}
