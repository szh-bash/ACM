#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
int main(){
	int n, T, ans, a[100001], v[100001];
	long long p[100001];
	scanf("%d%d", &n, &T);ans=n;
	for (int i=1;i<=n;i++){
		scanf("%I64d%d", &p[i], &v[i]);
		p[i]+=(long long)v[i]*T;
	}
	for (int i=n-1;i;i--)
		if (p[i]>=p[i+1]) p[i]=p[i+1],ans--;
	cout<<ans<<endl;
	return 0;
}
