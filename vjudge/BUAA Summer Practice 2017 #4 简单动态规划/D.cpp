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
#define m 100
#define M 500
using namespace std;
int n;
double g[M][M], f[M];
int read(){
	int p=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
void init(){
	n=read();
	for (int i=1;i<=m;i++)
		for (int j=0;j<=m;j++) g[i][j]=0;
	for (int i=1;i<=n;i++){
		int u=read(), v=read();
		g[u][u]=1;
		g[u][v]=-1;
	}
}
void Get_Matrix(){
	for (int i=1;i<m;i++){
		if (g[i][i]) continue;
		int k=min(m,i+6);
		g[i][0]=6;
		g[i][i]=k-i;
		for (int j=i+1;j<=k;j++) g[i][j]=-1;
	}
}
void Guass(){
	for (int i=1;i<m;i++){
		if (!g[i][i]){
			for (int j=i+1;j<m;j++)
				if (g[j][i]){
					g[i][0]+=g[j][0];
					for (int k=i;k<=m;k++)
						g[i][k]+=g[j][k];
					break;
				}
		}
		if (!g[i][i]) continue;
		for (int j=i+1;j<m;j++){
			double w=g[j][i]/g[i][i];
			g[j][0]-=g[i][0]*w;
			for (int k=i;k<=m;k++)
				g[j][k]-=g[i][k]*w;
		}
	}
	f[m]=0;
	for (int i=m-1;i;i--){
		for (int j=i+1;j<=m;j++)
			g[i][0]-=g[i][j]*f[j];
		if (!g[i][i]) f[i]=0;
		else f[i]=g[i][0]/g[i][i];
	}
}
int main(){
	for (int t=1, T=read();t<=T;t++){
		init();
		Get_Matrix();
		Guass();
		printf("Case %d: %.7lf\n", t, f[1]);
	}
}
