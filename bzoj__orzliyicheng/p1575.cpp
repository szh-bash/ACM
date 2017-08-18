#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define INF 499999999
using namespace std;
int n, e, f[200][200], m[200], p[200][200], q1[200], q2[200];
int main(){
	scanf("%d%d", &n, &e);
	for (int i=1;i<=n;i++) scanf("%d", &m[i]);
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			for (int k=i+1;k<j;k++)
				p[i][j]+=abs(2*m[k]-m[i]-m[j]);
	for (int i=1;i<=n;i++){
		for (int j=1;j<i;j++)
			q1[i]+=abs(2*(m[i]-m[j]));
		for (int j=1;j<i;j++)
			q2[n-i+1]+=abs(2*(m[n-j+1]-m[n-i+1]));
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			f[i][j]=INF;
	for (int i=1;i<=n;i++){
		f[i][1]=q1[i]+q2[i];
		for (int j=2;j<=i;j++)
			for (int k=1;k<i;k++)
				f[i][j]=min(f[i][j],q2[i]-q2[k]+p[k][i]+f[k][j-1]);
	}
	for (int i=1;i<=n;i++){
		int ans=INF;
		for (int j=1;j<=n;j++)
			ans=min(ans,f[j][i]);
		if (ans<=e){
			cout<<i<<' '<<ans<<endl;
			break;
		}
	}
	return 0;
}
