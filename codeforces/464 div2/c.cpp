#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 3000
typedef unsigned long long ll;
using namespace std;
int n, a[N], f[N][N][3], g[N][N];
int read(){
	int p=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j++)
			g[i][j]=g[i][j-1]+(a[j]==2);
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j++)
			if (a[j]==2){
				f[i][j][0]=f[i][j-1][0]+1;
				f[i][j][1]=max(f[i][j-1][1],g[i][j]);
			}
			else{
				f[i][j][0]=max(f[i][j-1][0],i-j+1-g[i][j]);
				f[i][j][1]=f[i][j-1][1]+1;
			}
	int ans=1;
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j++){
			ans=max(ans,f[1][i-1][0]+g[i][n]);
			ans=max(ans,i-1-g[1][i-1]+f[i][j][1]+g[j+1][n]);
			ans=max(ans,j-g[1][j]+f[j+1][n][0]);
		}
	cout<<ans<<endl;
	return 0;
}
