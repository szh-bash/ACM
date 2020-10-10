#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define N 100005
#define M 200005
using namespace std;
int cnt, n, m, top, tot, in[N], out[N], f[N];
int flag[N], dfn[N], low[N], co[N], stack[N];
int nex[M], nu[M];
int nex2[M], nu2[M];
int read(){
	int p=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
void add(int u, int v){
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;
}
void add2(int u, int v){
	nex2[++cnt]=nex2[u];nex2[u]=cnt;nu2[cnt]=v;
}
void tarjan(int u){
	dfn[u]=low[u]=++cnt;
	flag[u]=1;
	stack[++top]=u;
	for (int j=nex[u];j;j=nex[j]){
		int v=nu[j];
		if (!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if (flag[v]) low[u]=min(low[u],dfn[v]);
	}
	if (dfn[u]==low[u]){
		co[stack[top]]=++tot;
		flag[stack[top]]=0;
		while (stack[top--]!=u) flag[stack[top]]=0, co[stack[top]]=tot;
	}
}
int ans=0;
int spe[N], l[N];
int main(){
	cnt=n=read();m=read();
	int s=read()+1;
	for (int i=1;i<=m;i++){
		int u=read()+1, v=read()+1;
		if (u==s) continue;
		if (v==s) spe[u]=1;
		add(v,u);
	}
	for (int i=1;i<=n;i++) if (!dfn[i]) tarjan(i);
	cnt=n;
	for (int i=1;i<=n;i++){
		int u=co[i];
		if (spe[i]) f[u]++;
		for (int j=nex[i];j;j=nex[j]){
			int v=co[nu[j]];
			if (v==u) continue;
			in[v]++;
			out[u]++;
			add2(u,v);
		}
	}
	int le=0, ri=0;
	for (int i=1;i<=tot;i++)
		if (!in[i]) l[++ri]=i;
	while (le<ri){
		int u=l[++le];
		if (f[u]){
			if (f[u]==1) f[u]=n+1, ans++;
			continue;
		}
		for (int j=nex2[u];j;j=nex2[j]){
			int v=nu2[j];
			if (!--in[v]) l[++ri]=v;
		}
	}
	cout<<ans<<endl;
	for (int i=1;i<=n;i++)
		if (spe[i] && f[co[i]]>n) printf("%d\n", i-1);
	return 0;
}
