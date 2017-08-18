#include <cstdio>
#include <cstdlib>
#include <cstdlib>
#include <iostream>
typedef long long LL;
using namespace std;
LL n, m, g[10000000], p, ans;
int main(){
	scanf("%lld%lld", &n, &m);
	for (int i=0;i<=m;i++) g[i]=1;
	p=m;
	for (int i=m+1;g[i-1]<n;i++)
		g[i]=g[i-1]+g[i-m], p=i;
	while (n){
		while (g[p]>n) p--;
		n-=g[p];
		ans+=g[--p];
	}
	printf("%lld\n", ans);
	return 0;
}
