#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define M 20010
#define N 60
#define LL long long
#define INF (LL) 1000000000*100000
using namespace std;
int n, m, o, S, g[M][N], a[M];
char s[M];
LL f[3][M], v[M][N];
int main(){
	freopen("14-popeala.in","r",stdin);
	cin>>n>>m>>S;
	for (int i=1;i<=m;i++) cin>>a[i], a[i]+=a[i-1];
	for (int i=0;i<n;i++){
		scanf("%s", s+1);
		for (int j=1;j<=m;j++)
			if (s[j]=='0') g[j][i]=j;
			else g[j][i]=g[j-1][i];
	}
	for (int i=1;i<=m;i++)
		sort(g[i],g[i]+n), f[o][i]=INF;
	while (S--){
		for (int i=0;i<=n;i++)
			v[0][i]=f[o][0];
		f[o^=1][0]=INF;
		for (int i=1;i<=m;i++){
			LL t=v[i-1][n]+n*a[i];
			for (int j=0;j<n;j++)
				if (g[i][j])
					t=min(t, v[g[i][j]-1][j]+j*a[i]);
			f[o][i]=t;
			t=f[o^1][i];
			for (int j=0;j<=n;j++)
				v[i][j]=min(v[i-1][j],t-a[i]*j);
		}
		cout<<f[o][m]<<endl;
	}
	return 0;
}
