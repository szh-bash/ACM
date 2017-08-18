#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define max(a,b) ((a)>(b)?a:b)
#define min(a,b) ((a)<(b)?a:b)
using namespace std;
int n, f[2][1100000][2], a[110000], u, v;
int read(){
	int p=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
int main(){
	int T=read();
	while (T--){
		n=read();
		for (int i=1;i<=n;i++) a[i]=read();
		for (int i=0;i<=a[1];i++)
			f[0][i][0]=f[0][i][1]=1000000;
		f[0][a[1]][0]=0;
		for (int i=0;i<=a[2];i++)
			f[1][i][0]=f[1][i][1]=1000000;
		u=0;v=1;
		for (int i=1;i<n;i++){
			for (int j=0;j<=min(a[i],a[i+1]);j++)
				f[v][a[i+1]-j][0]=min(f[u][j][1],f[u][j][0])+j;
			int p=f[u][a[i]][0];
			for (int j=a[i+1]+1;j<=a[i];j++) p=min(p,f[u][j][0]);
			for (int j=min(a[i]-1,a[i+1]);j>=0;j--){
				f[v][a[i+1]-j][1]=p+j;
				p=min(p,f[u][j][0]);
			}
			for (int j=0;j<=a[i+2];j++)
				f[u][j][0]=f[u][j][1]=1000000;
			u^=1;v^=1;
		}
		int ans=min(f[(n+1)&1][0][1],f[(n+1)&1][0][0]);
		for (int i=1;i<=a[n];i++) ans=min(ans,f[(n+1)&1][i][0]);
		printf("%d ", ans);
		u=0,v=1;
		for (int i=0;i<=a[1];i++)
			f[0][i][0]=f[0][i][1]=-1000000;
		for (int i=0;i<=a[2];i++)
			f[1][i][0]=f[1][i][1]=-1000000;
		f[0][a[1]][0]=0;
		for (int i=1;i<n;i++){
			for (int j=0;j<=min(a[i],a[i+1]);j++)
				f[v][a[i+1]-j][0]=max(f[u][j][1],f[u][j][0])+j;
			int p=f[u][a[i]][0];
			for (int j=a[i+1]+1;j<=a[i];j++) p=max(p,f[u][j][0]);
			for (int j=min(a[i]-1,a[i+1]);j>=0;j--){
				f[v][a[i+1]-j][1]=p+j;
				p=max(p,f[u][j][0]);
			}
			for (int j=0;j<=a[i+2];j++)
				f[u][j][0]=f[u][j][1]=-1000000;
			u^=1, v^=1;
		}
		ans=max(f[(n+1)&1][0][1],f[(n+1)&1][0][0]);
		for (int i=1;i<=a[n];i++) ans=max(ans,f[(n+1)&1][i][0]);
		printf("%d\n", ans);
	}
	return 0;
}
