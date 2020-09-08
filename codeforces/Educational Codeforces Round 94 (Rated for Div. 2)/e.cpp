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
#define N 5005
int n, a[N], f[N][N], g[N][N];
int main(){
	n=read();
	int mi=n;
	for (int i=1;i<=n;i++) a[i]=read(), mi=min(a[i], mi);
	int inf=999999999;
	for (int i=1;i<=n;i++){
		for (int j=a[i]+1;j<=n+1;j++) f[i][j]=inf;
		for (int j=min(n,a[i]);j>=0;j--)
			f[i][j]=min(g[i-1][j]+(j<a[i]), f[i][j+1]+1);
		g[i][0]=f[i][0];
		for (int j=1;j<=n;j++)
			g[i][j]=min(g[i][j-1],f[i][j]);
	}
	cout<<f[n][0]<<endl;
	return 0;
}
