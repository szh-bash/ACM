#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int n, a[1000010];
long long p, f1[1000010];
int main(){
	scanf("%d", &n);
	for (int i=1;i<=n;i++) scanf("%d", &a[i]);
	sort(a+1,a+1+n);
	p=-(long long) 50000000*50000000;
	for (int i=1;i<=n;i++){
		f1[i]=max(p,-f1[i-1]+a[i]);
		p=f1[i];
	}
	cout<<f1[n]<<endl;
	return 0;
}
