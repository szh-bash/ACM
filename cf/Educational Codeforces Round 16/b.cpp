#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
long long n, p, ans, a[300100], ans2=1;
bool cmp(long long a, long long b){return a<b;}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)
		scanf("%I64d", &a[i]);
	sort(a+1,a+1+n, cmp);
	for (int i=1;i<=n;i++) ans=ans+a[i]-a[1];
	p=ans;
	for (long long i=2;i<=n;i++){
		p=p+(i-1)*(a[i]-a[i-1])-(n-i+1)*(a[i]-a[i-1]);
		if (p<ans) {
			ans2=i;
			ans=p;
		}
	}
	cout<<a[ans2]<<endl;
	return 0;
}
