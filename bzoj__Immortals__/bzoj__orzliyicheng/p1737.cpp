#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define INF 999999999
using namespace std;
int n, b, ans, f[3][4000][3], u[4000], x;
int main(){
	scanf("%d%d", &n, &b);
	for (int i=1;i<=n;i++) scanf("%d", &u[i]);
	for (int i=0;i<=1;i++)
		for (int j=0;j<=b;j++) f[i][j][1]=f[i][j][0]=-INF;
	f[0][0][0]=f[0][1][1]=0;
	x=0;
	for (int i=2;i<=n;i++){
		x^=1;f[x][0][0]=0;f[x][0][1]=-INF;
		for (int j=1;j<=b;j++)
			f[x][j][1]=max(f[1^x][j-1][1]+u[i],f[1^x][j-1][0]),
			f[x][j][0]=max(f[1^x][j][1],f[1^x][j][0]);
	}
	ans=max(f[x][b][1],f[x][b][0]);
	for (int i=0;i<=1;i++)
		for (int j=0;j<=b;j++) f[i][j][1]=f[i][j][0]=-INF;
	f[0][1][1]=u[1];
	x=0;
	for (int i=2;i<=n;i++){
		x^=1;
		f[x][1][0]=u[1];f[x][1][1]=-INF;
		for (int j=2;j<=b;j++)
			f[x][j][1]=max(f[1^x][j-1][1]+u[i],f[1^x][j-1][0]),
			f[x][j][0]=max(f[1^x][j][1],f[1^x][j][0]);
	}
	ans=max(ans,f[x][b][1]);
	cout<<ans<<endl;
	return 0;
}
