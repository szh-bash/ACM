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
int pre[N], a[N], n, g[N], f[N*20];
char s[N];
void solve(){
	n=read();
	scanf("%s", s);
	for (int i=1;i<=n;i++) a[i]=s[i-1]-'0';
	for (int i=1;i<=20*n;i++) f[i]=0;
	f[10*n]=1;
	ll ans=0;
	for (int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
//		pre[i]-pre[j]==i-j (0<=j<i)
		g[i]=pre[i]-i;
		ans+=f[g[i]+10*n];
		f[g[i]+10*n]++;
	}
	printf("%I64d\n", ans);
}
int main(){
	for (int _=read();_;_--) solve();
	return 0;
}
