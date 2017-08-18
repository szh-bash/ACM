#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, f[100001], a[51], ma, ans;
int main(){
	scanf("%d", &n);
	for (int i=1;i<=n;i++) scanf("%d", &a[i]), ma=max(a[i], ma), f[1]+=a[i];
	ans=f[1];
	for (int i=2;i<=ma;i++){
		int p=0;
		for (int k=1;k<=n;k++) p+=a[k]/i;
		f[i]=f[1]-p*(i-1);
		for (int j=2;j<=trunc(sqrt(i))+1;j++)
			if (i%j==0)
				f[i]=min(f[i],f[j]-p*(i/j-1)),
				f[i]=min(f[i],f[i/j]-p*(j-1));
		if (f[i]<ans) ans=f[i];
	}
	cout<<ans<<endl;
	return 0;
}
