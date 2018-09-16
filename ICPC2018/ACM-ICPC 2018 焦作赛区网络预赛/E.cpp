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
#define N 300050
#define M 1700500
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int n, cnt, fa[N], nex[N], nu[N], dfn[N], lo[N], top[N], son[N], size[N], dep[N];
ull x, g[M], p[M], sum[M];
ull read(){
    ull p=0;
    char ch=getchar();
    while (!num(ch)) ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p;
}
void add(int u, int v){
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;
}
void dfs1(int u){
	size[u]=1;
	son[u]=0;
	for (int j=nex[u];j;j=nex[j]){
		int v=nu[j];
		dep[v]=dep[u]+1;
		dfs1(v);
		size[u]+=size[v];
		if (size[v]>size[son[u]]) son[u]=v;
	}
}
void dfs2(int u){
	if (!u) return;
	dfn[++cnt]=u;
	lo[u]=cnt;
	if (son[fa[u]]==u) top[u]=top[fa[u]];else top[u]=cnt;
	dfs2(son[u]);
	for (int j=nex[u];j;j=nex[j])
	if (nu[j]!=son[u])		dfs2(nu[j]);
}
void pushdown(int t, int l, int r){
	if (l==r) return;
	int mid=l+r>>1;
	p[t<<1]*=p[t];
	p[(t<<1)+1]*=p[t];
	g[t<<1]*=p[t];
	g[(t<<1)+1]*=p[t];
	g[t<<1]+=g[t];
	g[(t<<1)+1]+=g[t];
	sum[t<<1]*=p[t];
	sum[(t<<1)+1]*=p[t];
	sum[t<<1]+=g[t]*(mid-l+1);
	sum[(t<<1)+1]+=g[t]*(r-mid);
	g[t]=0;
	p[t]=1;
}
void upd1(int t, int l, int r, int le, int ri){
	if (le<=l && r<=ri){
		g[t]+=x;
		sum[t]+=x*(r-l+1);
		return;
	}
	int mid=l+r>>1;
	pushdown(t,l,r);
	if (le<=mid) upd1(t<<1,l,mid,le,ri);
	if (ri>mid) upd1((t<<1)+1,mid+1,r,le,ri);
    sum[t]=sum[t<<1]+sum[(t<<1)+1];
}
void upd2(int t, int l, int r, int le, int ri){
	if (le<=l && r<=ri){
		p[t]*=x;
		g[t]*=x;
		sum[t]*=x;
		return;
	}
	int mid=l+r>>1;
	pushdown(t,l,r);
	if (le<=mid) upd2(t<<1,l,mid,le,ri);
	if (ri>mid) upd2((t<<1)+1,mid+1,r,le,ri);
    sum[t]=sum[t<<1]+sum[(t<<1)+1];
}
void upd3(int t, int l, int r, int le, int ri){
	int mid=l+r>>1;
	if (le<=l && r<=ri){
		g[t]=-g[t]-1;
		p[t]=-p[t];
		sum[t]=-sum[t]-(r-l+1);
		return;
	}
	pushdown(t,l,r);
	if (le<=mid) upd3(t<<1,l,mid,le,ri);
	if (ri>mid) upd3((t<<1)+1,mid+1,r,le,ri);
    sum[t]=sum[t<<1]+sum[(t<<1)+1];
}
ull query(int t, int l, int r, int le, int ri){
	if (le<=l && r<=ri) return sum[t];
	int mid=l+r>>1;
	ull p=0;
	pushdown(t,l,r);
	if (le<=mid) p+=query(t<<1,l,mid,le,ri);
	if (ri>mid) p+=query((t<<1)+1,mid+1,r,le,ri);
    sum[t]=sum[t<<1]+sum[(t<<1)+1];
	return p;
}
void re(int t, int l, int r){
	int mid=l+r>>1;
	sum[t]=g[t]=0;
	p[t]=1;
	if (l==r) return;
	re(t<<1,l,mid);
	re((t<<1)+1,mid+1,r);
}
int main(){
	while (~scanf("%d", &n)){
		re(1,1,n);
		cnt=n;
		for (int i=1;i<=n;i++) nex[i]=0;
		for (int i=1;i<n;i++)
			fa[i+1]=read(),
			add(fa[i+1],i+1);
		cnt=0;
		dfs1(1);
		dfs2(1);
		for (int m=read();m;m--){
			int op=read(), u=read(), v=read();
			if (op==1){
				x=read();
				int f1=top[u], f2=top[v];
				while (f1!=f2){
					if (dep[dfn[f1]]<dep[dfn[f2]]) swap(f1,f2), swap(u,v);
					upd2(1,1,n,f1,lo[u]);
					u=fa[dfn[f1]];
					f1=top[u];
				}
				if (lo[u]>lo[v]) swap(u,v);
				upd2(1,1,n,lo[u],lo[v]);
			}
			if (op==2){
				x=read();
				int f1=top[u], f2=top[v];
				while (f1!=f2){
					if (dep[dfn[f1]]<dep[dfn[f2]]) swap(f1,f2), swap(u,v);
					upd1(1,1,n,f1,lo[u]);
					u=fa[dfn[f1]];
					f1=top[u];
				}
				if (lo[u]>lo[v]) swap(u,v);
				upd1(1,1,n,lo[u],lo[v]);
			}
			if (op==3){
				int f1=top[u], f2=top[v];
				while (f1!=f2){
					if (dep[dfn[f1]]<dep[dfn[f2]]) swap(f1,f2), swap(u,v);
					upd3(1,1,n,f1,lo[u]);
					u=fa[dfn[f1]];
					f1=top[u];
				}
				if (lo[u]>lo[v]) swap(u,v);
				upd3(1,1,n,lo[u],lo[v]);
			}
			if (op==4){
				ull ans=0;
				int f1=top[u], f2=top[v];
				while (f1!=f2){
					if (dep[dfn[f1]]<dep[dfn[f2]]) swap(f1,f2), swap(u,v);
					ans+=query(1,1,n,f1,lo[u]);
					u=fa[dfn[f1]];
					f1=top[u];
				}
				if (lo[u]>lo[v]) swap(u,v);
				ans+=query(1,1,n,lo[u],lo[v]);
				printf("%llu\n",ans);
			}
		}
	}
    return 0;
}
