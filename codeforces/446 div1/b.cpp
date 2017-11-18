#include <map>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;
int n, a[100], b[100];
map <int, int> mp;
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9')
		(ch=='-'?q=-1:0),
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
int main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(), mp[a[i]]=i;
	sort(a+1,a+1+n);
	for (int i=1;i<n;i++) b[mp[a[i]]]=a[i+1];
	b[mp[a[n]]]=a[1];
	for (int i=1;i<=n;i++) cout<<b[i]<<' ';cout<<endl;
	return 0;
}
