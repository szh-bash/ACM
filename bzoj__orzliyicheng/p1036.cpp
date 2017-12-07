#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 31000
#define M 100000
#define INF 999999
typedef long long ll;
using namespace std;
int n, cnt, son[N], sum[N*4], dep[N], fa[N], f[N*4], nex[M], nu[M], dfn[N], pre[N], top[N];
char s[10];
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9'){
		if (ch=='-') q=-1;
		ch=getchar();
	}
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
void add(int u, int v){
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;
}
void dfs1(int u, int father){
	son[u]=1;
	int p=0;
	for (int j=nex[u];j;j=nex[j]){
		int v=nu[j];
		if (v==father) continue;
		fa[v]=u;
		dep[v]=dep[u]+1;
		dfs1(v,u);
		son[u]+=son[v];
		if (son[v]>son[p]) p=v;
	}
	pre[u]=p;
}
void dfs2(int u, int father){
	if (!u) return;
	if (pre[father]==u) top[u]=top[father];else top[u]=u;
	dfn[u]=++cnt;
	dfs2(pre[u],u);
	for (int j=nex[u];j;j=nex[j]){
		int v=nu[j];
		if (v==father || v==pre[u]) continue;
		dfs2(v,u);
	}
}
void update(int t, int l, int r, int x, int y){
	if (l==r){
		f[t]=sum[t]=y;
		return;
	}
	int mid=l+r>>1;
	if (x<=mid) update(t<<1,l,mid,x,y);else update((t<<1)+1,mid+1,r,x,y);
	sum[t]=sum[t<<1]+sum[(t<<1)+1];
	f[t]=max(f[t<<1],f[(t<<1)+1]);
}
int get_max(int t, int l, int r, int le, int ri){
	if (le<=l && r<=ri) return f[t];
	int mid=l+r>>1, p=-INF;
	if (le<=mid) p=max(p,get_max(t<<1,l,mid,le,ri));
	if (ri>mid) p=max(p,get_max((t<<1)+1,mid+1,r,le,ri));
	return p;
}
void query_max(int u, int v){
	int f1=top[u], f2=top[v], ans=-INF;
	while (f1!=f2)
		if (dep[f1]<dep[f2])
			ans=max(ans,get_max(1,1,n,dfn[f2],dfn[v])),
			v=fa[f2],
			f2=top[v];
		else
			ans=max(ans,get_max(1,1,n,dfn[f1],dfn[u])),
			u=fa[f1],
			f1=top[u];
	ans=max(ans,get_max(1,1,n,min(dfn[u],dfn[v]),max(dfn[u],dfn[v])));
	printf("%d\n", ans);
}
int get_sum(int t, int l, int r, int le ,int ri){
	if (le<=l && r<=ri) return sum[t];
	int mid=l+r>>1, p=0;
	if (le<=mid) p+=get_sum(t<<1,l,mid,le,ri);
	if (ri>mid) p+=get_sum((t<<1)+1,mid+1,r,le,ri);
	return p;
}
void query_sum(int u, int v){
	int f1=top[u], f2=top[v], ans=0;
	while (f1!=f2)
		if (dep[f1]<dep[f2])
			ans+=get_sum(1,1,n,dfn[f2],dfn[v]),
			v=fa[f2],
			f2=top[v];
		else
			ans+=get_sum(1,1,n,dfn[f1],dfn[u]),
			u=fa[f1],
			f1=top[u];
	ans+=get_sum(1,1,n,min(dfn[u],dfn[v]),max(dfn[u],dfn[v]));
	printf("%d\n", ans);
}
int main(){
	cnt=n=read();
	for (int i=1;i<n;i++){
		int u=read(), v=read();
		add(u,v);
		add(v,u);
	}
	dfs1(1,0);
	dfs2(1,cnt=0);
	for (int i=1;i<=n;i++)
		update(1,1,n,dfn[i],read());
	for (int q=read();q;q--){
		scanf("%s", s);
		int u=read(), v=read();
		if (s[0]=='C') update(1,1,n,dfn[u],v);
		if (s[1]=='M') query_max(u,v);
		if (s[1]=='S') query_sum(u,v);
	}
	return 0;
}
