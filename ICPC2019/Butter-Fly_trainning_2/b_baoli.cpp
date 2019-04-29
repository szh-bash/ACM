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
#define N 200
#define M 2000000
#define mo 1000000007
#define INF N
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int n, m, cnt;
int nex[M], nu[M], f[N][20], nex2[M], nu2[M], to2[M], fr2[M]; 
int dfn[N], low[N], stack[N], co[N], tag[N], top, tot, flag[N], numm[N];
int dist[N][N];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
void add(int u, int v){
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;
}
void dfs(int st, int x, int p){
	flag[x]=1;
//	cout<<st<<' '<<x<<' '<<dist[co[st]][tag[st]][tag[x]]<<endl;
	for (int j=nex[x];j;j=nex[j]){//¿ÉÄÜTLE 
		int v=nu[j];
		if (flag[v]) continue;
		if (dist[st][v]<=p+1)
			dist[st][v]=p+1;
		dfs(st,v, p+1);
	}
	flag[x]=0;
}
int main(){
	freopen("b.in","r",stdin);
	//freopen("b.out","w",stdout);
	cnt=n=read();m=read();
	for (int i=1;i<=m;i++){
		int u=read(), v=read();
		add(u,v);
	}
	int ans=0;
	for (int i=1;i<=n;i++){
		dfs(i,i, 0);
		for (int j=1;j<=n;j++){
			ans=max(ans,dist[i][j]+1);
		}
	}
	for (int i=1;i<=1;i++)
		for (int j=1;j<=n;j++)
			cout<<i<<' '<<j<<' '<<dist[i][j]<<endl;
	cout<<ans<<endl;
    return 0;
}
