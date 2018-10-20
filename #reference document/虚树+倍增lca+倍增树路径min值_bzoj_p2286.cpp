#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define LOGN 30
#define N 500050
#define num(x) ((x)>='0' && (x)<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
const int INF=1999999999;
int _, n, m, cnt, top, stack[N], flag[N], tag[N], lg[N], h[N];
int nex[N*5], nu[N*5], va[N*5];
int dfn[N], dep[N];
int fa[N][LOGN], g[N][LOGN];
ll f[N];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch)) (ch=='-'?q=-1:0), ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
void add(int u, int v, int w){
    nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;va[cnt]=w;
}
void dfs(int u, int dad, int w){
	dfn[u]=++cnt;
	dep[u]=dep[dad]+1;
	fa[u][0]=dad;
	g[u][0]=w;
	for (int j=1;fa[u][j-1];j++)
		fa[u][j]=fa[fa[u][j-1]][j-1],
		g[u][j]=min(g[u][j-1],g[fa[u][j-1]][j-1]);
	for (int j=nex[u];j;j=nex[j]){
		int v=nu[j];
		if (v==dad) continue;
		dfs(v,u,va[j]);
	}
}
void initialize(){
	lg[1]=0;
	for (int i=2;i<=n;i++) lg[i]=lg[i>>1]+1;
	for (int i=1;i<=n;i++)
		for (int j=0;j<=lg[n];j++)
			g[i][j]=INF;
	cnt=0;
    dfs(1,0,INF);
}
int get_lca(int u, int v){
	if (dep[u]<dep[v]) swap(u,v);
	while (dep[u]>dep[v]) u=fa[u][lg[dep[u]-dep[v]]];
	if (u==v) return u;
	for (int j=lg[n];j>=0;j--)
		if (fa[u][j]==fa[v][j]) continue;
		else u=fa[u][j], v=fa[v][j];
	return fa[u][0];
}
int get_min(int u, int v){
	//cout<<u<<' '<<v<<' '; 
	int mi=INF;
	while (u!=v){
		mi=min(mi,g[v][lg[dep[v]-dep[u]]]);
		v=fa[v][lg[dep[v]-dep[u]]];
	}
	//cout<<mi<<endl;
	return mi;
}
void link(int u, int v){
	if (tag[u]!=_) tag[u]=_, nex[u]=0;
	if (tag[v]!=_) tag[v]=_, nex[v]=0;
	add(u,v,get_min(u,v));
}
void pop(){
	int v=stack[top--];
	//cout<<v<<endl;
	if (!top) return;
	int u=stack[top];
	link(u,v);
}
void push(int u){
	stack[++top]=u;
}
void build_vt(){
	cnt=n;
	stack[top=1]=1;
	for (int i=1;i<=m;i++){
		int u=h[i], v=stack[top];
		int LCA=get_lca(u,v);
		//cout<<u<<' '<<v<<' '<<LCA<<' '<<endl;
		while (top>1 && dep[stack[top-1]]>=dep[LCA]) pop();
		if (stack[top]!=LCA){
			link(LCA,stack[top]);
			top--;
			push(LCA);
		}
		push(u);
	}
	while (top) pop();
}
bool cmp(int a, int b) { return dfn[a]<dfn[b];}
void dp(int u){
	f[u]=0;
	for (int j=nex[u];j;j=nex[j]){
		int v=nu[j];
		if (flag[v]==_) f[v]=INF;else dp(v);
		f[u]+=min((ll)va[j],f[v]);
	}
	//cout<<u<<' '<<f[u]<<endl;
}
void solve(){
	m=read();
	for (int i=1;i<=m;i++) h[i]=read(), flag[h[i]]=_;
	sort(h+1,h+1+m,cmp);
	build_vt();
	dp(1);
	printf("%lld\n", f[1]);
}
int main(){
    cnt=n=read();
    for (int i=1;i<n;i++){
        int u=read(), v=read(), w=read();
        add(u,v,w);
        add(v,u,w);
    }
    initialize();
    for (_=read();_;_--) solve();
    return 0;
}
