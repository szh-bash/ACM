#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define N 200
#define M 100000
using namespace std;
int n, ma, cnt, next[M], nu[M], va[M], num[N];
double ans, a[N][N], f[N];
int read(){
	int p=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
void add(int u, int v, int w){
	next[++cnt]=next[u];next[u]=cnt;nu[cnt]=v;va[cnt]=w;num[u]++;
}
void build(int x){
	for (int i=0;i<=n;i++)
		for (int j=0;j<=n;j++) a[i][j]=0;
	for (int u=1;u<n;u++){
		a[u][u]=num[u];
		for (int j=next[u];j;j=next[j]){
			int v=nu[j], w=va[j];
			if (w&x){
				a[u][v]++;
				a[u][0]--;
			}
			else{
				a[u][v]--;
			}
		}
	}
	a[n][n]=1;
}
void guass(int x){
	for (int i=1;i<n;i++){
		if (!a[i][i]){
			for (int j=i+1;j<=n;j++)
				if (a[j][i]){
					for (int k=i;k<=n;k++)
						a[i][k]+=a[j][k];
					a[i][0]+=a[j][0];
					break;
				}
		}
		for (int j=i+1;j<=n;j++){
			double p=a[j][i]/a[i][i];
			for (int k=i;k<=n;k++)
				a[j][k]-=a[i][k]*p;
			a[j][0]-=a[i][0]*p;
		}
	}
	if (!a[n][0] && !a[n][n]) f[n]=1;
	else f[n]=-a[n][0]/a[n][n];
	for (int i=n-1;i;i--){
		f[i]=-a[i][0];
		for (int j=i+1;j<=n;j++)
			f[i]-=a[i][j]*f[j];
		if (!a[i][i] && !f[i]) f[i]=1;
		else f[i]/=a[i][i];
	}
	ans+=x*f[1];
}
int main(){
	cnt=n=read();
	for (int m=read();m;m--){
		int u=read(), v=read(), w=read();
		add(u,v,w);
		if (u!=v) add(v,u,w);
		if (w>ma) ma=w;
	}
	for (int i=1;i<=ma;i<<=1){
		build(i);
		guass(i);
	}
	printf("%.3lf\n", ans);
	return 0;
}
