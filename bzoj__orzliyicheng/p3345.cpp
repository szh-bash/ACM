#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define INF 999999999
using namespace std;
int n, m, p[501], q[501], f[501][501];
int read(){
	char ch=getchar();
	int p=0;
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
void contract(int a, int b){
	for (int i=1;i<=n;i++)
		f[a][i]=f[i][a]=f[a][i]+f[b][i];
	for (int i=1;i<n;i++)
		f[b][i]=f[i][b]=f[n][i];
	f[a][a]=f[b][b]=0;
	n--;
}
int query(){
	int ans=INF, tp1, tp;
for (;n>1;){
	memset(q,1,sizeof(q[0])*(n+1));
	memset(p,0,sizeof(p[0])*(n+1));
	q[1]=0;
	for (int i=2;i<=n;i++)
		p[i]=f[1][i];
	for (int i=1;i<n;i++){
		int MAX=0;
		for (int j=1;j<=n;j++)
			if (q[j] && p[j]>MAX){
				MAX=p[j];
				tp=j;
			}
		q[tp]=0;
		for (int j=1;j<=n;j++)
			if (q[j]) p[j]+=f[tp][j];
		if (i==n-2) tp1=tp;
			
	}
	ans=min(ans,p[tp]);
	contract(tp1,tp);
}
	return ans;
}
int main(){
	n=read();m=read();
	int x, y, z;
	for (int i=1;i<=m;i++){
		x=read();y=read();
		f[y][x]=f[x][y]=read();
	}
	cout<<query()<<endl;
	return 0;
}
