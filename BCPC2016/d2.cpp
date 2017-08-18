#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, m;
double ans, p[1000][1000], q[1000][1000];
int main(){
	int T;
	cin>>T;
	while (T--){
		cin>>n>>m;
		for (int i=1;i<=n;i++) 
			for (int j=1;j<=m;j++) 
				scanf("%lf", &p[i][j]);
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				scanf("%lf", &q[i][j]);
		ans=0;
		for (int i=1;i<=n;i++) p[i][0]=1, q[i][0]=0;
		for (int i=1;i<=m;i++) p[0][i]=0, q[0][i]=1;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
					ans+=(1-p[i-1][j])*(1-q[i][j-1]);
		printf("%.4lf\n", ans);
	}
	return 0;
}
