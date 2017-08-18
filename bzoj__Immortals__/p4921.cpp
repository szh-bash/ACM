#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 110000
#define mo 998244353
typedef long long LL;
using namespace std;
int n, f[N], g[N], a[N], ls[N];
LL ans;
int read(){
	int p=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
int gcd(int a, int b){return !b?a:gcd(b,a%b);}
int main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) f[i]=gcd(a[i],f[i-1]);
	for (int i=n;i;i--) g[i]=gcd(a[i],g[i+1]);
	ls[n+1]=n+1;
	for (int i=n;i;i--)
		if (g[i]==g[i+1]) ls[i]=ls[i+1];
		else ls[i]=i;
	for (int i=0;i<n;i++){
		for (int j=i+2;j<=n+1;j=ls[j]+1)
			ans+=(LL)(ls[j]-j+1)*gcd(f[i],g[j]);
	}
	ans=((ans-a[1]-a[n])%mo+mo)%mo;
	cout<<ans<<endl;
	return 0;
}


