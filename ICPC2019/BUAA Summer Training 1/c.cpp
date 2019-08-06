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
#define N 1000
#define M 3000
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int n, m, cnt, ct, top;
int f[N], g[N], dfn[N], low[N], stack[N], flag[N], co[N], ans[N], fr[N];
int fa[M], tag[M], res[M];
int nex[M], nu[M], num[M], dir[M];
int nex2[M], nu2[M], num2[M], dir2[M];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
void add(int u, int v, int di, int id){
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;dir[cnt]=di;num[cnt]=id;
}
void add2(int u, int v, int di, int id){
	nex2[++cnt]=nex2[u];nex2[u]=cnt;nu2[cnt]=v;dir2[cnt]=di;num2[cnt]=id;
}
void tarjan(int u){
	dfn[u]=low[u]=++cnt;
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
		co[stack[top]]=++ct;
		flag[stack[top]]=0;
		while (stack[top--]!=u) flag[stack[top]]=0, co[stack[top]]=ct;
	}
}
void dfs(int u, int fat){
	f[u]=0;
	int od=0, ev=0;
	for (int j=nex2[u];j;j=nex2[j]){
		int v=nu2[j];
		if (v==fat) continue;
		f[u]++;
		fr[u]=j;
		dfs(v,u);
		if (f[v]&1){
			if (od){
				fa[fr[od]]=num2[j];
				tag[res[fr[od]]]=1;
				ans[u]+=ans[v]+ans[od]-1;
				od=0;
			}
			else
				od=v,
				fa[g[v]]=num2[j],
				tag[j]=0,
				res[num2[j]]=j;
		}
		else{
			if (ev){
				fa[fr[ev]]=num2[j];
				tag[res[fr[ev]]]=1;
				ans[u]+=ans[v]+ans[ev]+1;
				ev=0;
			}
			else 
				ev=v,
				fa[g[v]]=num2[j],
				tag[j]=0,
				res[num2[j]]=j;
		}
	}
	if (od && ev){
		fa[fr[od]]=num2[fa[g[ev]]];
		tag[res[fr[od]]]=1;
		ans[u]+=ans[od]+ans[ev];
		g[u]=0;
	}
	else g[u]=od+ev;
}
int main(){
	while (~scanf("%d%d", &n, &m)){
		cnt=n;
		for (int i=1;i<=n;i++)
			nex[i]=nex2[i]=0,
			dfn[i]=low[i]=0;
		for (int i=1;i<=m;i++){
			int u=read(), v=read();
			add(u,v,1,i);
			add(v,u,-1,i);
			fa[i]=i;
		}
		for (int i=1;i<=n;i++) if (!dfn[i]) tarjan(i);
		cnt=n;
		for (int i=1;i<=n;i++){
			int u=co[i];
			for (int j=nex[i];j;j=nex[j]){
				int v=co[nu[j]];
				if (v==u) continue;
				add2(u,v,dir[j],num[j]);
			}
		}
		dfs(1,0);
		cout<<ans[1]<<endl;
	}
    return 0;
}
