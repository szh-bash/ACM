#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define INF 999999999
using namespace std;
int n, m, K, c[500], d[500], b[500], f[500], q[500][500], a[500][500];
bool cmp(int aa, int b){return c[aa]<c[b];}
int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	cin>>n>>m>>K;
	for (int i=1;i<=n;i++) cin>>c[i], b[i]=i;
	sort(b+1,b+1+n,cmp);
	for (int i=1;i<=n;i++)	f[b[i]]=i, d[i]=c[b[i]];
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (i!=j)	a[i][j]=INF;
	for (int i=1;i<=m;i++){
		int u, v, w;
		cin>>u>>v>>w;
		w=min(w,a[f[u]][f[v]]);
		a[f[u]][f[v]]=a[f[v]][f[u]]=w;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (i!=j)	q[i][j]=a[i][j]+d[max(i,j)];
			else q[i][j]=d[i];
	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				q[i][j]=min(q[i][j],q[i][k]+q[k][j]-d[max(i,k)]-d[max(j,k)]+d[max(i,max(j,k))]);
	for (int i=1;i<=K;i++){
		int u, v;
		cin>>u>>v;
		cout<<q[f[u]][f[v]]<<endl;
	}
	return 0;
}
