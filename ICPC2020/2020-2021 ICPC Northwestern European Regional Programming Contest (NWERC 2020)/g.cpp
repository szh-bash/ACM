#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <tr1/unordered_map>
#define mo 1000000007
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
#define N 100
#define T 5005
#define ST 4
int n, m, r, t[N], d[N], dt[N];
double p[N];
double f[N][T][ST], g[N][T][ST];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
int power(ll a, int b){
	ll c=1;
	while (b){
		if (b&1) c=c*a%mo;
		a=a*a%mo;
		b>>=1;
	}
	return c;
}
int main(){
	n=read(), r=read(), m=read();
	for (int i=1;i<=m;i++) {
		t[i]=read(), scanf("%lf", &p[i]), d[i]=read();
		// cout<<t[i]<<' '<<p[i]<<' '<<d[i]<<endl;
	}
	t[m+1]=n;
	for (int i=1;i<=m+1;i++) dt[i]=t[i]-t[i-1];
	for (int i=0;i<=m;i++)
		for (int j=0;j<r;j++)
			for (int k=0;k<2;k++)
				f[i][j][k]=g[i][j][k]=1e9;
	for (int k=0;k<2;k++)
		f[0][0][k]=1,
		g[0][0][k]=t[1];
	// for (int j=t[1];j==t[1];j++)
	// 	f[1][j][0]=(1-p[1]),
	// 	f[1][j][1]=1,
	// 	g[1][j][0]=f[1][j][0]*(t[1]+dt[2]+d[1]),
	// 	g[1][j][1]=(1/p[1])*t[1]+dt[2];
	for (int i=1;i<=m;i++)
		for (int j=t[i];j<r;j++){
			// double q=		((j-dt[i])>=t[i-1]	?f[i-1][j-dt[i]][1]	:0)
			// 		+((j-dt[i]-d[i-1])>=t[i-1]	?f[i-1][j-dt[i]-d[i-1]][0]	:0);
			// double pg=		((j-dt[i])>=t[i-1]	?g[i-1][j-dt[i]][1]:0)
			// 		+((j-dt[i]-d[i-1])>=t[i-1]	?g[i-1][j-dt[i]-d[i-1]][0]	:0);
			// double q=min	(((j-dt[i])>=t[i-1]	?f[i-1][j-dt[i]][1]	:1e9)
			// 		,((j-dt[i]-d[i-1])>=t[i-1]	?f[i-1][j-dt[i]-d[i-1]][0]	:1e9));
			// double pg=min	(((j-dt[i])>=t[i-1]	?g[i-1][j-dt[i]][1] :1e9)
			// 		,((j-dt[i]-d[i-1])>=t[i-1]	?g[i-1][j-dt[i]-d[i-1]][0]	:1e9));
			double q=min	(((j-dt[i])>=t[i-1]	?f[i-1][j-dt[i]][1]	:1e9)
					,((j-dt[i]-d[i-1])>=t[i-1]	?f[i-1][j-dt[i]-d[i-1]][0]	:1e9));
			double pg=min	(((j-dt[i])>=t[i-1]	?g[i-1][j-dt[i]][1] :1e9)
					,((j-dt[i]-d[i-1])>=t[i-1]	?g[i-1][j-dt[i]-d[i-1]][0]	:1e9));
			// if (i==1) q=1, pg=t[1];
			f[i][j][0]=q*(1-p[i]);
			f[i][j][1]=q*p[i]/(1-(1-p[i])*q);
			g[i][j][0]=pg+dt[i+1]+d[i]*(1-p[i]);
			g[i][j][1]=pg*(1/p[i])+dt[i+1];
			cout<<i<<' '<<j<<' '<<g[i][j][0]<<' '<<g[i][j][1]<<endl;
		}
	double ans=1ll*1e9*1e9;
	for (int j=t[m];j<r;j++)
		ans=min(ans, min(g[m][j][0], g[m][j][1]));
	cout<<ans<<endl;
    return 0;
}
