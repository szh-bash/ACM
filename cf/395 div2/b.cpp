#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, a[300000];
int main(){
	cin>>n;
	for (int i=1;i<=n;i++) scanf("%d", &a[i]);
	for (int i=1;i<=n/2;i++)
		if (i&1) swap(a[i],a[n-i+1]);
	for (int i=1;i<=n;i++) printf("%d ", a[i]);
	return 0;
}
