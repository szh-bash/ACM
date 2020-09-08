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
#define N 1005
#define N2 N*N
#define M N*N*(25*2+1)
int n, m, sn, sm, en, em, cnt;
int f[N][N], dist[N2], l[N2];
int nex[M], nu[M];
char a[N][N];
inline bool check(int x, int y){
	return !(!x || x>n || !y || y>m || a[x][y]!='.');
}
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
void dfs(int x, int y, int d){
	f[x][y]=d;
	for (int j=0;j<4;j++)
		if (check(x+dx[j], y+dy[j]) && !f[x+dx[j]][y+dy[j]]) dfs(x+dx[j], y+dy[j], d);
}
void add(int u, int v){
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;
	nex[++cnt]=nex[v];nex[v]=cnt;nu[cnt]=u;
}
int main(){
	n=read(), m=read();
	sn=read(), sm=read();
	en=read(), em=read();
	for (int i=1;i<=n;i++) scanf("%s", a[i]+1);
	cnt=0;
	for (int i=1;i<=n;i++)	
		for (int j=1;j<=m;j++)
			if (!f[i][j]&&a[i][j]=='.') dfs(i,j,++cnt);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (f[i][j])
			for (int x=-2;x<=2;x++)
				for (int y=-2;y<=2;y++)
					if (check(i+x,j+y) && f[i][j]!=f[x+i][y+j]) add(f[i][j], f[i+x][y+j]);
	dist[l[1]=f[sn][sm]]=1;
	for (int le=0, ri=1;le<ri && !dist[f[en][em]];){
		int u=l[++le];
		for (int j=nex[u];j;j=nex[j]){
			int v=nu[j];
			if (!dist[v]){
				dist[v]=dist[u]+1,
				l[++ri]=v;
				if (v==f[en][em]) break;
			}
		}
	}
	cout<<(dist[f[en][em]]?dist[f[en][em]]-1:-1)<<endl;
    return 0;
}
