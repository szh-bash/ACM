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
ll readll(){
    ll p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
#define N 300005
#define M N*3
int n, m, cnt, ans[N], nex[M], nu[M], dfn[N], low[N], ed[N];
void add(int u, int v){
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;
}
void dfs(int u, int fa){
	dfn[u]=low[u]=++cnt;
	ans[u]=fa>0;
	for (int j=nex[u];j;j=nex[j])
		if (j^fa^1){
			int v=nu[j];
			if (!dfn[v]){
				dfs(v,j);
				if (low[v]<low[u]) low[u]=low[v];
				if (low[v]>=dfn[u]) ans[u]++;
			}
			else low[u]=min(low[u],dfn[v]);
		}
}
int main(){
	cnt=n=read();m=read();
	cnt+=!(n&1);
	for (int i=1;i<=m;i++){
		int u=read(), v=read();
		add(u,v);
		add(v,u);
		ed[u]++;
		ed[v]++;
	}
	cnt=0;
	int base=0;
	for (int i=1;i<=n;i++)
		if (!dfn[i])
			dfs(i,0),
			base++;
	for (int i=1;i<=n;i++)
		printf("%d%s", base-1+ans[i], (i==n?"\n":" "));
    return 0;
}
