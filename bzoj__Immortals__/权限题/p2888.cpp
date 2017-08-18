#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 200000
using namespace std;
int n, m, ans, fa[N], l[N], r[N], size[N], next[N], nu[N];
int read(){
	int p=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
void update(int u){
	if (l[u]) fa[l[u]]=u;
	if (r[u]) fa[r[u]]=u;
	size[u]=1+size[l[u]]+size[r[u]];
}
void pushdown(int u){
	if (tag[u]{){
		add1(l[u],tag[u]);
		add1(r[u],tag[u]);
		tag[u]=0;
	}
	if (td[u]){
		add2(l[u],(ts[u]+size[r[u]]+1)*td[u],td[u]);
		add2(r[u],ts[u],td[u]);
		ts[u]=td[u]=0;
	}
}
void zig(int u){
	int f1=fa[u], f2=fa[f1];
	if (!isroot(f1))
		if (l[f2]==f1) l[f2]=u;else r[f2]=u;
	fa[u]=f2;
	l[f1]=r[u];
	r[u]=f1;
	update(f1);
	update(u);
}
void zag(int u){
	int f1=fa[u], f2=fa[f1];
	if (!isroot(f1))
		if (l[f2]==f1) l[f2]=u;else r[f2]=u;
	fa[u]=f2;
	r[f1]=l[u];
	l[u]=f1;
	update(f1);
	update(u);
}
void splay(int u){
	int ri=1, f1=fa[u], f2=fa[f1];
	for (int i=list[1]=u;!isroot(i);) list[++ri]=i=fa[i];
	for (int i=ri;i;i--) pushdown(list[i]);
	while (!isroot(u) && !isroot(f1)){
		if (l[f2]==f1)
			if (l[f1]==u) zig(f1), zig(u);
			else zag(u), zig(u);
		else
			if (r[f1]==u) zag(f1), zag(u);
			else zig(u), zag(u);
		f1=fa[u];f2=fa[f1];
	}
	if (!isroot(u))
		if (l[f1]==u) zig(u);else zag(u);
}
void access(int u){
	for (int v=0;u;v=u,u=fa[u]){
		splay(u);
		r[u]=v;
		update(u);
	}
}
int root (int u){
	access(u);
	splay(u);
	while (l[u]) u=l[u];
	return u;
}
void add(int u, int v){
	next[++cnt]=next[u];next[u]=cnt;nu[cnt]=v;
}
void addleaf(int u, int v){
	fa[v]=u;l[v]=r[v]=val[v]=tag[v]=sum[v]=ts[v]=td[v]=0;size[v]=1;
	u=root(u);access(v);splay(u);add1(u,1);add2(u,0,1);
	for (
}
void dfs(int u, int v){
	addleaf(v,u);
	for (int j=next[u];j;j=next[j])
		if (nu[j]!=v) dfs(nu[j],u);
}
void link(int u, int v){
	int U=root(u), V=root(v);
	ans-=sum[U]+sum[V];
	if (val[U]<val[V]) swap(u,v);
	dfs(v,u);add(u,v);add(v,u);
	ans+=sum[root(u)];
}
int main(){
	cnt=n=read();
	for (int T=0;T;T--){
		char s[3];scanf("%s", s);
		if (s[0]=='A'){
			int u=read(), v=read();
			link(u,v);
		}
		else printf("%d\n", ans);
	}
	return 0;
}
