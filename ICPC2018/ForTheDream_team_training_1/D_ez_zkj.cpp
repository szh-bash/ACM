#include <bits/stdc++.h>
#define dep 200
#define N 21
using namespace std;

int cnt[N];
double p[N],f[N][dep+10];
int n;

double qpow(double a,int b)
{
	double res=1;
	while (b)
	{
		if (b&1) res=res*a;
		a=a*a;
		b>>=1;
	}
	return res;
}

void calc(int x)
{
	double ans=0;
	for (int k=1;k<=dep;k++)
	{
		double now=f[x][k+1]-f[x][k];
		for (int i=1;i<=n;i++) if (x!=i) now*=f[i][k];
		ans=ans+now; 
	} 
	printf("%.6lf",ans+1);
	if (x==n) puts(""); else printf(" ");
}

void work()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d %lf",&cnt[i],&p[i]);
	if (n==1) {puts("1.000000"); return;}
	for (int i=1;i<=n;i++)
	{
		f[i][0]=1; double tmp=1;
		for (int j=1;j<=dep;j++) 
		{
			tmp*=p[i];
		    f[i][j]=qpow(1-tmp,cnt[i]);
		}
	}
	for (int i=1;i<=n;i++) calc(i);
}

int main()
{
	freopen("data.in","r",stdin);
	freopen("std.out","w",stdout); 
	int cas; scanf("%d",&cas);
	for (int i=1;i<=cas;i++) work();
}
