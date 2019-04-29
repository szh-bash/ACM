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
#define N 200000
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
int dist[N][20][20];
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
void add2(int u, int v, int fr, int too){
	nex2[++cnt]=nex2[u];nex2[u]=cnt;nu2[cnt]=v;fr2[cnt]=fr;to2[cnt]=too;
}
void tarjan(int u){
	dfn [u]=low[u]=++cnt;
	flag[u]=1;
	stack[++top]=u;
	for (int j=nex[u];j;j=nex[j]){
		int v=nu[j];
		if (!dfn[v]){
			tarjan(v);
			low[u]=min(low[u], low[v]); 
		}
		else if (flag[v]) low[u]=min(low[u], dfn[v]);
	}
	if (dfn[u]==low[u]){
		co[stack[top]]=++tot;
		flag[stack[top]]=0;
		tag[stack[top]]=numm[tot]++;
		while (stack[top--]!=u)
			flag[stack[top]]=0,
			co[stack[top]]=tot,
			tag[stack[top]]=numm[tot]++;
	}
}
void dfs(int st, int x, int p){
	flag[x]=1;
//	cout<<st<<' '<<x<<' '<<dist[co[st]][tag[st]][tag[x]]<<endl;
	for (int j=nex[x];j;j=nex[j]){//可能TLE (并不) 
		int v=nu[j];
		if (co[v]!=co[st] || flag[v]) continue; 
		if (dist[co[st]][tag[st]][tag[v]]<p+1)
			dist[co[st]][tag[st]][tag[v]]=p+1;
		dfs(st,v,p+1); 
	}
	flag[x]=0;
}
void dp(int x){
	flag[x]=1;
	int len=numm[x];
	for (int i=0;i<len;i++)
		for (int j=0;j<len;j++)
			f[x][i]=max(f[x][i],dist[x][i][j]+1);
	for (int j=nex2[x];j;j=nex2[j]){
		int v=nu2[j];
		if (!flag[v]) dp(v);
		for (int i=0;i<len;i++)
			f[x][i]=max(f[x][i],1+dist[x][i][tag[fr2[j]]]+f[v][tag[to2[j]]]);
	}
}
int main(){
	//freopen("b.in","r",stdin);
	//freopen("b.ans","w",stdout);
	cnt=n=read();m=read();
	for (int i=1;i<=m;i++){
		int u=read(), v=read();
		add(u,v);
	}
	cnt=0;
	for (int i=1;i<=n;i++) if (!dfn[i]) tarjan(i);
	cnt=n;
	for (int i=1;i<=n;i++){
		int u=co[i];
		for (int j=nex[i];j;j=nex[j]){
			int v=co[nu[j]];
			if (v==u) continue;
			add2(u,v,i,nu[j]);
		}
		dfs(i,i,0); 
	}
/*	for (int i=1;i<=tot;i++){
		int len=numm[i];
		for (int j=0;j<len;j++)
			for (int k=0;k<len;k++)
				cout<<i<<' '<<j<<' '<<k<<' '<<dist[i][j][k]<<endl; 
	}*/
	for (int i=1;i<=tot;i++)
		if (!flag[i]) dp(i);
	int ans=0;
	for (int i=1;i<=tot;i++){
		int len=numm[i];
		for (int j=0;j<len;j++)
			ans=max(ans,f[i][j]);
	}
	cout<<ans<<endl;
    return 0;
}
