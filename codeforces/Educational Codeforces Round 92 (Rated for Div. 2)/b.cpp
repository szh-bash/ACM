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
#define N 400000
int n, k, z, q[N], a[N], pre[N];
void solve(){
	n=read(), k=read()+1, z=read();
	for (int i=1;i<=n;i++) a[i]=read(); 
	for (int i=1;i<=k;i++){
		for (int j=0;j<=z;j++)
			f[i][j][0]=max(f[i-1][j][0],f[i-1][j][1]);
	}
	printf("%I64d\n", ans);
}
int main(){
	for (int _=read();_;_--) solve();
	return 0;
}
