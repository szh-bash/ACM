#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
typedef long long LL;
using namespace std;
LL L, R, cnt, b[10], a[15], p[15], c[15];
void solve(LL x, int w){
	if (!x) return;
	cnt=0;
	while (x){
		a[++cnt]=x%10;
		x/=10;
	}
	c[0]=1;
	for (int i=1;i<=cnt;i++)
		c[i]=c[i-1]+p[i-1]*a[i];
	LL q=a[cnt];
	for (int j=1;j<q;j++)
		b[j]+=p[cnt-1]*w;
	b[q]+=c[cnt-1]*w;
	for (int i=cnt-1;i;i--){
		if (!a[i])
			b[0]+=(q-1)*p[i-1]*w+c[i-1]*w;
		else
			b[0]+=q*p[i-1]*w;
		for (int j=1;j<10;j++)
			if (j==a[i])
				b[j]+=q*p[i-1]*w,
				b[j]+=c[i-1]*w;
			else
				if (j<a[i])
					b[j]+=(q+1)*p[i-1]*w;
				else
					b[j]+=q*p[i-1]*w;
		q=q*10+a[i];
	}
}
int main(){
	cin>>L>>R;
	p[0]=1;
	for (int i=1;i<=13;i++) p[i]=p[i-1]*10;
	solve(R,1);
	solve(L-1,-1);
	for (int i=0;i<10;i++) printf("%lld%c", b[i], i==9?'\n':' ');
	return 0;
}
