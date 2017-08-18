#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, k, tot, a[3000];
int main(){
	cin>>n>>k;
	for (int i=1;i<=n;i++)
		cin>>a[i], tot-=a[i];
	for (int i=2;i<=n;i++)
		if ((a[i-1]+a[i])<k)
			a[i]+=k-(a[i]+a[i-1]);
	for (int i=1;i<=n;i++) tot+=a[i];
	cout<<tot<<endl;
	for (int i=1;i<=n;i++)
		cout<<a[i]<<' ';
	return 0;
}
