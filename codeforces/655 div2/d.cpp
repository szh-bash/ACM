#include <map>
#include <set> 
#include <ctime>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=='-'?q=-1:0, ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
ll readll(){
	ll p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=='-'?q=-1:0, ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
#define N 300000
int n;
ll a[N], ans, sum, f[N], g[N];
int main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(), f[i]=f[i-2<0?0:i-2]+a[i];
	for (int i=n;i;i--) g[i]=g[i+2]+a[i];
	ans=g[1];
	for (int i=1;i<n;i++) ans=max(ans,f[i]+g[i+1]);
	cout<<ans<<endl;
	return 0;
}
