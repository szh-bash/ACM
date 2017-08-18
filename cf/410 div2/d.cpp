#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
int a[1000000], b[1000000], c[1000000];
bool cmp(int x,int y){return a[x]>a[y];}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)
		scanf("%d", &a[i]);
	for (int i=1;i<=n;i++)
		scanf("%d", &b[i]);
	for (int i=1;i<=n;i++)
		c[i]=i;
	sort(c+1,c+1+n,cmp);
	cout<<n/2+1<<endl;
	cout<<c[1]<<' ';
	for (int i=2;i<n;i+=2)
		if (b[c[i]]>b[c[i+1]]) cout<<c[i]<<' ';else cout<<c[i+1]<<' ';
	if (n%2==0) cout<<c[n]<<endl;
	return 0;
}
