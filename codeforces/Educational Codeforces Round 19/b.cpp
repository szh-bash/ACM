#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int ans,ans0,n, a[110000];
int main(){
	cin>>n;
	for (int i=1;i<=n;i++) scanf("%d", &a[i]);
	sort(a+1,a+1+n);
	int i;
	for (i=n;i && a[i]>0;i--)
		ans+=a[i];
	if (ans%2) {cout<<ans<<endl;return 0;}
	ans0=-1000000001;
	for (int j=i;j;j--)
		if (abs(a[j])%2) {ans0=max(ans0,ans+a[j]);break;}
	for (int j=i+1;j<=n;j++)
		if (a[j]%2) {ans0=max(ans0,ans-a[j]);break;}
	cout<<ans0<<endl;
	return 0;
}
