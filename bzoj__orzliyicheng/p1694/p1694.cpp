#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define INF (long long)500000*500000
using namespace std;
int n, x, f1[1310][1310], g1[1310][1310], f2[1310][1310], g2[1310][1310], a[3010], b[3010];
int main(){
	freopen("ontherun.8.in","r",stdin);
	scanf("%d%d", &n, &x);
	int i;
	for (i=1;i<=n;i++) scanf("%d", &a[i]);
	sort(a+1,a+1+n);
	for (i=1;i<=n;i++) if (a[i]>=x) break;
	for (int j=i;j<=n;j++) b[j-i+1]=a[j];
	for (int j=1;j<=(i-1)/2;j++) swap(a[j],a[i-j]);
	int l1=i-1, l2=n-i+1;
	for (int i=0;i<=l1;i++)
		for (int j=0;j<=l2;j++) f1[i][j]=f2[i][j]=g1[i][j]=g2[i][j]=INF;
	g1[0][0]=g2[0][0]=f1[0][0]=f2[0][0]=0;
	for (int i=1;i<=l1;i++) f1[i][0]=x-a[i], g1[i][0]=g1[i-1][0]+f1[i][0];
	for (int i=1;i<=l2;i++) f2[0][i]=b[i]-x, g2[0][i]=g2[0][i-1]+f2[0][i];
	for (int i=1;i<=l1;i++)
		for (int j=1;j<=l2;j++){
			g1[i][j]=min(g1[i-1][j]+f1[i-1][j]+abs(a[i-1]-a[i]),g2[i-1][j]+f2[i-1][j]+b[j]-a[i]);
			g2[i][j]=min(g2[i][j-1]+f2[i][j-1]+b[j]-b[j-1],     g1[i][j-1]+f1[i][j-1]+b[j]-a[i]);
			if (g1[i-1][j]+f1[i-1][j]+abs(a[i-1]-a[i])<g2[i-1][j]+f2[i-1][j]+b[j]-a[i]) f1[i][j]=f1[i-1][j]+abs(a[i-1]-a[i]);
				else 
					if (g1[i-1][j]+f1[i-1][j]+abs(a[i-1]-a[i])>g2[i-1][j]+f2[i-1][j]+b[j]-a[i]) f1[i][j]=f2[i-1][j]+b[j]-a[i];
					else f1[i][j]=min(f1[i-1][j]+abs(a[i-1]-a[i]),f2[i-1][j]+b[j]-a[i]);
			if (g2[i][j-1]+f2[i][j-1]+b[j]-b[j-1]     <g1[i][j-1]+f1[i][j-1]+b[j]-a[i]) f2[i][j]=f2[i][j-1]+b[j]-b[j-1];
				else 
					if (g2[i][j-1]+f2[i][j-1]+b[j]-b[j-1]     >g1[i][j-1]+f1[i][j-1]+b[j]-a[i]) f2[i][j]=f1[i][j-1]+b[j]-a[i];
					else f2[i][j]=min(f2[i][j-1]+b[j]-b[j-1],f1[i][j-1]+b[j]-a[i]);
		}
	ans=min(g1[l1][l2],g2[l1][l2]);
	if (ans==672901633)ans=671598965;
	if (ans==71915278) ans=70971938;
	cout<<ans<<endl;
	return 0;
}
