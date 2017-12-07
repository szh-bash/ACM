#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define N 2000000
typedef long long LL;
using namespace std;
int n, q, a[N];
LL f[N];
LL read(){
	LL p=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
int main(){
	n=read();q=read();
	LL sum=0;
	for (int i=0;i<n;i++) a[i]=read(), sum+=(LL)a[i]*i;
	sum%=n-1;
	f[1]=a[0];
	for (int i=2;i<=n;i++) f[i]=f[i-1]+((i-1)==sum?a[i-1]-1:a[i-1]);
	while (q--){
		LL k=read()+1;
		if (k>f[n]){
			printf("-1\n");
			continue;
		}
		int le=0, ri=n;
		while (le<ri-1){
			int mid=le+ri>>1;
			if (f[mid]>=k) ri=mid;else le=mid;
		}
		printf("%d\n", ri-1);
	}
	return 0;
}
