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
#define N 400
int n, k, a[N][N];
int row[N], col[N];
int sqr(int x){return x*x;}
void print(){
	int mar=0, mac=0;
	for (int i=1;i<=n;i++) row[i]=col[i]=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			row[i]+=a[i][j],
			col[j]+=a[i][j];
	int mir=n+1, mic=n+1;
	for (int i=1;i<=n;i++)
		mar=max(mar, row[i]),
		mac=max(mac, col[i]),
		mir=min(mir, row[i]),
		mic=min(mic, col[i]);
	printf("%d\n", sqr(mar-mir)+sqr(mac-mic));
	for (int i=1;i<=n;i++) 
		for (int j=1;j<=n;j++) 
			printf("%d%s", a[i][j], j==n?"\n":"");
}
void solve(){
	n=read(), k=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) a[i][j]=0;
	int i=1, j=n/2+1;
	if (k){
		a[i][j]=1;
		k--;
		while (k){
			int ti=i, tj=j;
			if (i+1>n) i=1;else i++;
			if (j+1>n) j=1;else j++;
			if (a[i][j]) i=ti-1==0?n:ti-1, j=tj;
			a[i][j]=1;
			k--;
		}
	}
	print();
}
int main(){
	for (int _=read();_;_--) solve();
	return 0;
}
