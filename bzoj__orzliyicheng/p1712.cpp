#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define mo 98765431
using namespace std;
long long T, a[3], d[3][3], b;
int n, cc, c[10000000];
int main(){
	cin>>n>>T;T--;
	if (T&1) cc=1;else cc=-1;
	for (int i=1;i<=n;i++) scanf("%d", &c[i]), b+=c[i];
	b%=mo;
	a[2]=d[1][1]=n-1;
	d[2][1]=1;d[2][2]=-1;
	while (T){
		if (T&1){
			a[1]=(a[1]*d[1][1]+a[2]*d[2][1])%mo;
			a[2]*=d[2][2];
		}
		long long tp1, tp2, tp3;
		tp1=d[1][1]*d[1][1]%mo;
		tp2=(d[2][1]*d[1][1]+d[2][2]*d[2][1])%mo;
		tp3=d[2][2]*d[2][2];
		d[1][1]=tp1;d[2][1]=tp2;d[2][2]=tp3;
		T/=2;
	}
	a[1]-=cc;
	for (int i=1;i<n;i++) printf("%lld\n", (a[1]*b+cc*c[i]+mo)%mo);
	printf("%lld", (a[1]*b+cc*c[n]+mo)%mo);
	return 0;
}
