#include <cstdio>
#include <iostream>
#include <bitset>
using namespace std;
int n, x;
bitset<2000000>a;
int main(){
	a[0]=1;
	scanf("%d", &n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d", &x);
		a^=a<<x;
	}
	int ans=0;
	for (int i=1;i<=2000000;i++)
		if (a[i]) ans^=i;
	printf("%d\n", ans);
}
