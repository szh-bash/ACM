#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int main(){
	scanf("%d%d", &n, &m);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) dist[i][j]=1000000000;
	for (int i=1;i<=m;i++){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		dist[u][v]=dist[v][u]=a[u][v]=a[v][u]=w;
	}
	memset(g,1,sizeof(g));
	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				if (f[i][k]+f[k][j]<f[i][j]) f[i][j]=f[i][k]+f[k][j],g[i][j]=g[i][k]+g[k][j];
	
	return 0;
}
