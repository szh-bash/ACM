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
#define N 2000
int a[N], b[N], f[N], cnt;
void solve(){
	int n=read(), m=read(), ans=0;
	cnt++;
	for (int i=1;i<=n;i++) a[i]=read(), f[a[i]]=cnt;
	for (int i=1;i<=m;i++) b[i]=read(), (f[b[i]]==cnt?ans=b[i]:0);
	if (ans) printf("YES\n%d %d\n", 1, ans);
	else puts("NO");
}
int main(){
	for (int _=read();_;_--) solve();
	return 0;
}
