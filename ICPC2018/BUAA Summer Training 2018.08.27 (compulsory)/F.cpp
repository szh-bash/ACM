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
#define N 500000
#define INF (ll) 200000*200000
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
struct zkjnb{
	int u, v, w, bridge;
}l[N];
int n, m, cnt, top, list[N*5], dfn[N], low[N], flag[N], stack[N], ff[N], nex[N], va[N], nu[N];
ll dis[N][3];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
void add(int u, int v, int w){
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;va[cnt]=w;
}
void spfa(int s, int t, int k){
	int le=0, ri=1;
	for (int i=1;i<=n;i++) dis[i][k]=INF;
	dis[s][k]=0;
	flag[list[1]=s]=1;
	while (le<ri){
		int u=list[++le];
		flag[u]=0;
		for (int j=nex[u];j;j=nex[j]){
			int v=nu[j], w=va[j];
			if (dis[u][k]+w<dis[v][k]){
				dis[v][k]=dis[u][k]+w;
				if (!flag[v]){
					list[++ri]=v;
					flag[v]=1;
				}
			}
		}
	}
}
void tarjan(int u, int fr){
	ff[u]=1;
	dfn[u]=low[u]=++cnt;
	stack[++top]=u;
	flag[u]=1;
	for (int j=nex[u];j;j=nex[j]){
		if (j==(fr^1)) continue;
		int v=nu[j];
		if (!dfn[v])
			tarjan(v,j),
			low[u]=min(low[u],low[v]);
		else
			if (flag[v]) low[u]=min(low[u],dfn[v]);
		if (low[v]>dfn[u]) l[va[j]].bridge=1;
	}
	if (low[u]==dfn[u]){
		while (stack[top]!=u) flag[stack[top--]]=0;
		flag[stack[top--]]=0;
	}
}
int main(){
	cnt=n=read();m=read();
	for (int i=1;i<=m;i++)
		l[i].u=read(),
		l[i].v=read(),
		l[i].w=read(),
		add(l[i].u, l[i].v, l[i].w);
	spfa(1,2,0);
	cnt=n;
	for (int i=1;i<=n;i++) nex[i]=0;
	for (int i=1;i<=m;i++)
		add(l[i].v, l[i].u, l[i].w);
	spfa(2,1,1);
	//cout<<dis[2][0]<<' '<<dis[1][1]<<endl;
	cnt=n+((n+1)&1);
	for (int i=1;i<=n;i++) nex[i]=0;
	for (int i=1;i<=m;i++)
		if (dis[l[i].u][0]+l[i].w+dis[l[i].v][1]==dis[2][0]){
			add(l[i].u,l[i].v,i),
			add(l[i].v,l[i].u,i);
			//cout<<"lyk "<<i<<endl;
		}
	cnt=0;
	for (int i=1;i<=n;i++)
		if (!ff[i]) tarjan(i,0);
	for (int i=1;i<=m;i++)
		if (l[i].bridge) printf("SAD\n");
		else
			if (dis[l[i].v][0]+l[i].w+dis[l[i].u][1]<dis[2][0]) printf("HAPPY\n");
			else printf("SOSO\n");
    return 0;
}
