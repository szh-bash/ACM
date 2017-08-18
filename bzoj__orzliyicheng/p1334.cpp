#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, sum, a[3001], f[200010], ans;
int main(){
	scanf("%d", &n);
	for (int i=1;i<=n;i++) scanf("%d", &a[i]), sum+=a[i];
	m=sum/2;
    sort(a+1,a+1+n,greater<int>());
    f[0]=1;
	for (int i=1;i<=n;i++)
		for (int j=m;j>=0;j--){
			f[j+a[i]]|=f[j];
			if (j+a[i]>m && f[j+a[i]]) ans=max(ans,j+a[i]);
		}
	cout<<ans<<endl;
	return 0;
}
