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
int cnt;
short n;
char f[N][N][N];
int dis[N][N], a[N][N], tag[N][N];
char s[N*N*3*30+100];
int x;
int read(){
    int p=0;
    while (s[x]<'0' || s[x]>'9') x++;
    while (s[x]>='0' && s[x]<='9') p=p*10+s[x++]-'0';
    return p;
}
bool cmp(zsa a, zsa b){return a.w<b.w;}
int add(int a, int b){
	if (a+b>=mo) return a+b-mo;
	else return a+b;
}
void upd(int &a, int b){
	if (a+b>=mo) a=a+b-mo;
	else a=a+b;
}
int main(){
	freopen("6.in","r",stdin);
	freopen("f.out","w",stdout);
	fread(s,1,N*N*3*20+100,stdin);
	for (int _=read();_;_--){
		//cout<<_<<endl; 
		n=read();	
		cnt=0;
		for (int i=1;i<=n;++i)
			for (int j=1;j<=n;++j)
				a[i][j]=read(),
				dis[i][j]=a[i][j];
		for (int k=1;k<=n;++k)
			for (int i=1;i<=n;++i)
				for (int j=1;j<=n;++j)
					if (dis[i][k]+dis[k][j]<dis[i][j])
						dis[i][j]=dis[i][k]+dis[k][j];
		for (int i=1;i<=n;++i)
			for (int j=i+1;j<=n;++j)
				l[++cnt].x=i,
				l[cnt].y=j,
				l[cnt].w=dis[i][j]<<=1;
		memset(tag,0,sizeof(tag));
		sort(l+1,l+1+cnt,cmp);
		int ans=0;
		for (int i=1;i<=n;++i)
			for (int j=i+1;j<=n;++j)
				upd(ans,((ull)a[i][j]*(n-2)<<1)%mo);
		//cout<<ans<<endl;
		//cout<<cnt<<endl;
		//cnt*=0.9;
		for (int k=1;k<=cnt;++k){
			int u=l[k].x, v=l[k].y;
			for (int i=1;i<=n;++i)
				if (i!=u && i!=v){
					int t0=i, t1=u;
					if (t0>t1) swap(t0,t1);
					if (f[t0][t1][v]!=_ && n-3-tag[t0][t1]>0){
						upd(ans,((ull)a[t0][t1]+dis[u][v])*(n-3-tag[t0][t1])%mo);
					//cout<<ans<<' '<<tag[t0][t1]<<' '<<a[t0][t1]<<' '<<dis[u][v]<<endl;
						f[t0][t1][v]=_;
						tag[t0][t1]++;
					}
					t0=i, t1=v;
					if (t0>t1) swap(t0,t1);
					if (f[t0][t1][u]!=_ && n-3-tag[t0][t1]>0){
						upd(ans,(ull)a[t0][t1]*(n-3-tag[t0][t1])%mo);
						f[t0][t1][u]=_;
						tag[t0][t1]++;
					}
				}
		}
		cout<<ans<<endl;
	}
    return 0;
}
