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
#define N 100005
int n, a[N], f[N];
void solve(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	f[n]=1;
	for (int i=n-1;i;i--)
		if (a[i]==1) f[i]=f[i+1]^1;
		else f[i]=1;
	if (f[1]) puts("First");else puts("Second");
}
int main(){
	for (int _=read();_;_--) solve();
	return 0;
}
