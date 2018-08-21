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
#define INF 1000000000
#define N 505
#define M 500*500+500
#define mo 998244353
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
using namespace std::tr1;
struct zsa{
	short x, y;
	int w;
}l[M];
int cnt, a[N][N];
short n,tag[N][N], f[N][N][N];
ll dis[N][N];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
bool cmp(zsa a, zsa b){return a.w<b.w;}
int add(int a, int b){return a+b>=mo?a+b-mo:a+b;}
int pwd(ll a, int b){
	ll c=1;
	while (b){
		if (b&1) c=c*a%mo;
		a=a*a%mo;
		b>>=1;
	}
	return c;
}
int main(){
	freopen("f.in","r",stdin);
	for (int _=read();_;_--){
		n=read();	
		cnt=0;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				a[i][j]=read(),
				dis[i][j]=a[i][j]<<1;
		for (int k=1;k<=n;k++)
			for (int i=1;i<=n;i++)
				for (int j=1;j<=n;j++)
					if (dis[i][k]+dis[k][j]<dis[i][j])
						dis[i][j]=dis[i][k]+dis[k][j];
/*		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++){
				dis[i][j]=(dis[i][j]<<1);
				dis[i][j]=add(dis[i][j],0);
				dis[i][j]=add(dis[i][j],0);
			}*/
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++)
				l[++cnt].x=i,
				l[cnt].y=j,
				l[cnt].w=dis[i][j]%=mo;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				a[i][j]=add(a[i][j],0);
		memset(tag,0,sizeof(tag));
		sort(l+1,l+1+cnt,cmp);
		int ans=0;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				if (i!=j)
				for (int k=1;k<=n;k++)
					if (k!=i && k!=j)
					ans=add(ans,add(a[i][j],a[i][k]));
		ans=(ll)ans*pwd(2,mo-2)%mo;
		//cout<<ans<<endl;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				for (int k=1;k<=n;k++)
					f[i][j][k]=n-3,
					f[i][k][j]=n-3;
		cout<<cnt<<endl;
		for (int k=1;k<=cnt;k++){
			int u=l[k].x, v=l[k].y;
			for (int i=1;i<=n;i++)
				if (i!=u && i!=v){
					int t0=i, t1=u;
					if (t0>t1) swap(t0,t1);
					if (f[t0][t1][v]-tag[t0][t1]>0)
						ans=add(ans,(ll)(f[t0][t1][v]-tag[t0][t1])*(a[t0][t1]+dis[u][v])%mo);
					f[t0][t1][v]=0;
					tag[t0][t1]++;
				}
			for (int i=1;i<=n;i++)
				if (i!=u && i!=v){
					int t0=i, t1=v;
					if (t0>t1) swap(t0,t1);
					if (f[t0][t1][u]-tag[t0][t1]>0)
						ans=add(ans,(ll)(f[t0][t1][u]-tag[t0][t1])*a[t0][t1]%mo);
					f[t0][t1][u]=0;
					tag[t0][t1]++;
				}
		}
		cout<<ans<<endl;
	}
    return 0;
}
/*
3
2
0 1
1 0
3
0 1 1
1 0 1
1 1 0
4
0 1 1 1
1 0 2 2
1 2 0 3
1 2 3 0
*/
