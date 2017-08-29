#include <map>
#include <cmath>
#include <ctime>
#include <queue>
#include <bitset>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define M 810
#define N 4100
#define INF 999999999
using namespace std;
int n, m, dp[M][N], a[N][N], w[N][N], s[M][N];
int read(){
	int p=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
int main(){
	n=read();m=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			a[i][j]=read()+a[i-1][j]+a[i][j-1]-a[i-1][j-1];
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j++)
			w[i][j]=(a[j][j]-a[i-1][j]-a[j][i-1]+a[i-1][i-1])/2;
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++)
			dp[i][j]=INF;
	for (int i=1;i<=n;i++)
		dp[1][i]=w[1][i], s[1][n]=0;
	for (int i=2;i<=m;i++){
		s[i][n+1]=n;
		for (int j=n;j>=i;j--)
			for (int k=s[i-1][j];k<=s[i][j+1];k++)
				if (dp[i][j]>dp[i-1][k]+w[k+1][j])
					dp[i][j]=dp[i-1][k]+w[k+1][j], s[i][j]=k;
	}
	cout<<dp[m][n]<<endl;
	return 0;
}
