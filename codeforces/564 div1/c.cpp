#include <map>
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
#define N 100
#define mo 998244353
typedef long long ll;
using namespace std;
int n, m, a[N];
ll w[N];
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
	n=read(), m=read();
	int cnt=0;
	for (int i=1;i<=n;i++) a[i]=read()?1:-1;
	for (int i=1;i<=n;i++) w[i]=read(), cnt+=(a[i]>0)*w[i];
	for (int i=1;i<=m;i++){
		for (int j=0;j<=m*2;j++)
			for (int k=1;k<=n;k++);
				
	}
	for (int i=1;i<=m;i++){
		ll sw=0;
		for (int j=1;j<=n;j++) sw=(sw+w[j])%mo;
		for (int j=1;j<=n;j++)
			w[j]=(w[j]+w[j]*power(sw,mo-2)*a[j])%mo;
	}
	for (int i=1;i<=n;i++) 
		printf("%I64d\n", (w[i]+mo)%mo);
		//printf("%lld\n", (w[i]+mo)%mo);
	return 0;
}
