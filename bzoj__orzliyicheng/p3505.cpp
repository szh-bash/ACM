#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int gcd(int a,int b){return b ? gcd(b, a%b) : a;}
int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	n++;m++;
	long long ans=(long long)n*m*(n*m-1)/2*(n*m-2)/3;
	for (int i=3;i<=n;i++)
		for (int j=3;j<=m;j++)
			ans-=(long long)2*(gcd(i-1,j-1)-1)*(n-i+1)*(m-j+1);
	ans-=(long long)m*n*(n-1)*(n-2)/6+(long long)n*m*(m-1)*(m-2)/6;
	printf("%lld", ans);
	return 0;
}
