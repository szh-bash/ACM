#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 100000
#define M 200000
#define mo 201314
using namespace std;
struct qlz{
	int x, w, f, n;
}ques[M];
bool rev[N];
int n, q, cnt, fa[N], l[N], r[N], size[N], list[N];
int f[N], g[N], sum[N], ans[N];
int read(){
	int p=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
void add(int x, int w, int f, int n){
	ques[++cnt].x=x;
	ques[cnt].w=w;
	ques[cnt].f=f;
	ques[cnt].n=n;
}
bool cmp(qlz a, qlz b){return a.x<b.x;}
bool isroot(int u){return l[fa[u]]!=u && r[fa[u]]!=u;}
void update(int u){
	if (l[u]) fa[l[u]]=u;
	if (r[u]) fa[r[u]]=u;
	sum[u]=f[u]+sum[l[u]]+sum[r[u]];
	size[u]=1+size[l[u]]+size[r[u]];
}
void pushdown(int u){
	if (rev[u]){
		swap(l[u],r[u]);
		rev[u]^=1;rev[l[u]]^=1;rev[r[u]]^=1;
	}
	if (g[u]){
		g[l[u]]+=g[u];
		g[r[u]]+=g[u];
		f[l[u]]+=g[u];
		f[r[u]]+=g[u];
		sum[l[u]]+=g[u]*size[l[u]];
		sum[r[u]]+=g[u]*size[r[u]];
		g[u]=0;
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
void makeroot(int u){
	access(u);
	splay(u);
	rev[u]^=1;
}
void link(int u, int v){
	makeroot(u);
	fa[u]=v;
}
void modify(int u, int v, int w){
	makeroot(u);
	access(v);
	splay(v);
	g[v]+=w;
	f[v]+=w;
	sum[v]+=w*size[v];
}
int calc(int u, int v){
	makeroot(u);
	access(v);
	splay(v);
	return sum[v];
}
int main(){
	n=read();q=read();
	for (int i=1;i<=n;i++) size[i]=1;
	for (int i=1;i<n;i++)
		link(i+1,read()+1);
	for (int i=1;i<=q;i++){
		int l=read()+1, r=read()+1, z=read()+1;
		add(l-1,z,-1,i);
		add(r,z,1,i);
	}
	sort(ques+1,ques+cnt+1,cmp);
	int j=1;
	while (!ques[j].x) j++;
	for (int i=1;i<=n;i++){
		modify(1,i,1);
		while (ques[j].x==i){
			ans[ques[j].n]+=calc(1,ques[j].w)*ques[j].f;
			j++;
		}
	}
	for (int i=1;i<=q;i++) printf("%d\n", ans[i]%mo);
	return 0;
}
