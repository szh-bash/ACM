#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 2000
typedef long long ll;
using namespace std;
int n, a[N], b[N], f[N][N];
int read(){
	int p=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
int main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) b[i]=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++){
			if (abs(a[i]-b[j])<=4) f[i][j]=f[i-1][j-1]+1;
			f[i][j]=max(f[i][j],max(f[i-1][j],f[i][j-1]));
		}
	cout<<f[n][n]<<endl;
	return 0;
}
