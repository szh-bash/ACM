#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, s, e;
long long f[5010][5010];
int main(){
	cin>>n>>s>>e;
	for (int i=1;i<=n;i++) scanf("%d", &x[i]);
	for (int i=1;i<=n;i++) scanf("%d", &a[i]);
	for (int i=1;i<=n;i++) scanf("%d", &b[i]);
	for (int i=1;i<=n;i++) scanf("%d", &c[i]);
	for (int i=1;i<=n;i++) scanf("%d", &d[i]);
	for (int i=1;i<n;i++)
		for (int j=i+1;j<=n;j++){
			f[i][j]=(long long)d[i]+a[j]+abs(x[i]-x[j]);
			f[j][i]=(long long)c[j]+b[i]+abs(x[i]-x[j]);
		}
	return 0;
}
