#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 500000
typedef long long ll;
using namespace std;
int n, k, a[N];
ll sa[N];
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') 
		ch=='-'?q=-1:0,
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
int main(){
	n=read();k=read()-1;
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=n;i;i--) sa[i]=sa[i+1]+a[i];
	sort(sa+2,sa+1+n);
	ll ans=sa[1];
	for (int i=0;i<k;i++)
		ans+=sa[n-i];
	cout<<ans<<endl;
	return 0;
}
