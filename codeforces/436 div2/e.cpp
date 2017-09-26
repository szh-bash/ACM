#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 3000
using namespace std;
int n, M, f[200][N], t[N], num[N], d[N], p[N], q[200][N], ans[110][2100][110];
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') (ch=='-'?q=-1:0), ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
int main(){
	n=read();
	for (int i=1;i<=n;i++) num[i]=i, t[i]=read(), d[i]=read(), p[i]=read(), M=max(M,d[i]);
	for (int i=1;i<=n;i++)	
		for (int j=i+1;j<=n;j++)
			if (d[i]>d[j])
				swap(t[i],t[j]),
				swap(d[i],d[j]),
				swap(p[i],p[j]),
				swap(num[i],num[j]);
	for (int i=1;i<=n;i++)
		for (int j=0;j<=M;j++){
			if (t[i]+j<d[i]){
				f[i][j+t[i]]=f[i-1][j]+p[i];
				ans[i][j+t[i]][0]=ans[i-1][j][0]+1;
				for (int k=1;k<=ans[i-1][j][0];k++) ans[i][j+t[i]][k]=ans[i-1][j][k];
				ans[i][j+t[i]][ans[i][j+t[i]][0]]=i;
			}
			if (f[i-1][j]>f[i][j]){
				ans[i][j][0]=ans[i-1][j][0];
				for (int k=1;k<=ans[i-1][j][0];k++) ans[i][j][k]=ans[i-1][j][k];
				f[i][j]=f[i-1][j];
			}
			if (j && f[i][j-1]>f[i][j]){
				ans[i][j][0]=ans[i][j-1][0];
				for (int k=1;k<=ans[i][j-1][0];k++) ans[i][j][k]=ans[i][j-1][k];
				f[i][j]=f[i][j-1];
			}
		}
	cout<<f[n][M]<<endl;
	cout<<ans[n][M][0]<<endl;
	for (int i=1;i<=ans[n][M][0];i++)
		printf("%d ",num[ans[n][M][i]]);
	return 0;
}
