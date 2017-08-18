#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 400000
typedef long long LL;
using namespace std;
int root, cnt, n, m, size[N], l[N], r[N], fa[N], f[N], p[N], list[N];
inline int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9'){
		if (ch=='-') q=-1;
		ch=getchar();
	}
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
inline void pushdown(int t){
	if (!p[t]) return;
	swap(l[t],r[t]);
	if (l[t]) p[l[t]]^=p[t];
	if (r[t]) p[r[t]]^=p[t];
	p[t]=0;
}
inline void pushup(int t){
	if (l[t]) fa[l[t]]=t;
	if (r[t]) fa[r[t]]=t;
	size[t]=size[l[t]]+size[r[t]]+1;
}
inline void insert(int &t, int x){
	if (!t){
		f[t=++cnt]=x;
		size[t]=1;
		return;
	}
	pushdown(t);
	if (f[t]<=x) insert(r[t],x);
	if (f[t]>x) insert(l[t],x);
	pushup(t);
}
inline void zig(int t){
	int f1=fa[t], f2=fa[f1];
	if (f2)
		if (l[f2]==f1) l[f2]=t;else r[f2]=t;
	fa[fa[f1]=t]=f2;
	if (l[f1]=r[t]) fa[l[f1]]=f1;
	r[t]=f1;
	size[t]=size[f1];
	size[f1]=size[l[f1]]+size[r[f1]]+1;
}
inline void zag(int t){
	int f1=fa[t], f2=fa[f1];
	if (f2)
		if (l[f2]==f1) l[f2]=t;else r[f2]=t;
	fa[fa[f1]=t]=f2;
	if (r[f1]=l[t]) fa[r[f1]]=f1;
	l[t]=f1;
	size[t]=size[f1];
	size[f1]=size[l[f1]]+size[r[f1]]+1;
}
inline void splay(int t){
	int f1=fa[t], f2=fa[f1];
	int ri=1;
	list[1]=t;
	for (int i=1;fa[list[i]];i++) list[++ri]=fa[list[i]];
	for (int i=ri;i;i--) pushdown(list[i]);
	while (f2){
		if (l[f2]==f1)
			if (l[f1]==t) zig(f1), zig(t);
			else zag(t), zig(t);
		else
			if (r[f1]==t) zag(f1), zag(t);
			else zig(t), zag(t);
		f1=fa[t];f2=fa[f1];
	}
	if (f1)
		if (l[f1]==t) zig(t);else zag(t);
	root=t;
}
inline int find(int t, int k){
	pushdown(t);
	if (size[l[t]]+1==k) return t;
	if (size[l[t]]+1<k) return find(r[t],k-size[l[t]]-1);
	return find(l[t],k);
}
inline void print(int t){
	if (!t) return;
	pushdown(t);
	print(l[t]);
	if (t>1 && t<=n+1) printf("%d ", f[t]);
	print(r[t]);
}
int main(){
	n=read();m=read();
	insert(root,0);
	for (int i=1;i<=n;i++){
		f[++cnt]=i;
		l[cnt]=cnt-1;
		if (cnt>1) fa[cnt-1]=cnt;
		size[cnt]=cnt;
		root=cnt;
	}
	insert(root,n+1);
	splay(cnt);
	for (int i=1;i<=m;i++){
		int u=find(root,read()), v=find(root,read()+2);
		splay(u);
		fa[r[u]]=0;
		splay(v);
		p[l[v]]^=1;
		root=fa[r[u]=v]=u;
	}
	print(root);
	return 0;
}
