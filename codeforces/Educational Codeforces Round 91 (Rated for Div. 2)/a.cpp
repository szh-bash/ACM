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
#define N 20000
int n, a[N], pa[N], pb[N], pre[N], nex[N];
void solve(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	pre[0]=nex[n+1]=n+1;
	for (int i=1;i<=n;i++){
		pre[i]=min(pre[i-1],a[i]);
		if (a[i]<pre[i-1]) pa[i]=i;else pa[i]=pa[i-1];
	}
	for (int i=n;i;i--){
		nex[i]=min(nex[i+1],a[i]);
		if (a[i]<nex[i+1]) pb[i]=i;else pb[i]=pb[i+1];
	}
	int flag=0;
	for (int i=2;i<n;i++)
		if (pre[i]<a[i] && a[i]>nex[i]){
			flag=i;
			break;
		}
	if (!flag) puts("NO");
	else printf("YES\n%d %d %d\n", pa[flag-1], flag, pb[flag+1]);
}
int main(){
	for (int _=read();_;_--) solve();
	return 0;
}
