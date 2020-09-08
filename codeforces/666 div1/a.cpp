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
#define mo 1000000007
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
int power(ll a, int b){
	ll c=1;
	while (b){
		if (b&1) c=c*a%mo;
		a=a*a%mo;
		b>>=1;
	}
	return c;
}
#define N 200000
int n, a[N];
void solve(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	if (n==1){
		printf("1 1\n%d\n1 1\n0\n1 1\n0\n", -a[1], n);
		return;
	}
	printf("1 1\n%d\n2 %d\n", -a[1], n);
	a[1]=0;
	for (int i=2;i<=n;i++)
		printf("%I64d%s", 1ll*a[i]*(n-1),(i==n?"\n":" "));
	printf("1 %d\n", n);
	for (int i=1;i<=n;i++)
		printf("%I64d%s", -1ll*a[i]*n, (i==n?"\n":" "));
}
int main(){
	solve();
	return 0;
}
