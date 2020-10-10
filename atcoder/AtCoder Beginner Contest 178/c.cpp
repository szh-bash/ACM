#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <tr1/unordered_map>
#define mo 1000000007
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
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
#define N 1000006
ll dex[N], f[N];
ll C(int n, int m){
	return f[n]*power(f[n-m],mo-2)%mo*power(f[m],mo-2)%mo;
}
int main(){
	ll n=read();
	ll ans=1, p=1;
	dex[0]=f[0]=1;
	for (int i=1;i<=n;i++) dex[i]=dex[i-1]*8%mo, f[i]=f[i-1]*i%mo;
	ans=(power(10,n)-power(8,n))%mo;
	for (int i=1;i<=n;i++)
		ans=(ans-2ll*C(n,i)*dex[n-i])%mo;
	ans=(ans+mo)%mo;
	cout<<ans<<endl;
    return 0;
}
