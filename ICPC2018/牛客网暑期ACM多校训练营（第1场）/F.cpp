#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 1110
#define mo 1000000007
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int n;
ll ans, c[N+5][N+5], b[N+5], e[N+5], f[N+5], g[N+5], a[N+5], p[N+5], q[N+5];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
ll power(ll x, int y){
	ll c=1;
	while (y){
		if (y&1) c=c*x%mo;
		x=x*x%mo;
		y>>=1;
	}
	return c;
}
ll S(ll n, int k){
	ll p=0, q=n+1;
	for (int i=1;i<=k+1;i++, q=q*(n+1)%mo)
		p=(p+(c[k+1][i]*b[k+1-i]%mo)*q)%mo;
	return p*power(k+1,mo-2)%mo;
}
int main(){
	c[0][0]=1;
	for (int i=1;i<=N;i++){
		c[i][0]=1;
		for (int j=1;j<=i;j++)
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mo;
	}
	b[0]=1;
	for (int i=1;i<=N;i++){
		for (int j=0;j<i;j++)
			b[i]=(b[i]+c[i+1][j]*b[j])%mo;
		b[i]=-b[i]*power(i+1,mo-2)%mo;
	}
	while (~scanf("%d", &n)){
		ans=0;
		for (int i=1;i<=n;i++) scanf("%d", &a[i]);//a[i]=read();
		sort(a+1,a+1+n);
		for (int i=1;i<=n;i++){
			f[i]=S(a[i]-1,n-i+2),
			g[i]=S(a[i]-1,n-i+1),
			e[i]=S(a[i]-1,n-i),
			p[i]=S(a[i],n-i+2),
			q[i]=S(a[i],n-i+1);
		}
		ll k=1;
		for (int j=1;j<=n;j++){
			ans=(ans+k*(p[j]-q[j-1]-(f[j]-g[j-1]+g[j]-e[j-1])))%mo;
			k=(k*a[j])%mo;
		}
		printf("%lld\n", (ans+mo)%mo);
	}
    return 0;
}
