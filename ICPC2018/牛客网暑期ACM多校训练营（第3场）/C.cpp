#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 200000
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int n, m, root, cnt, l[N], r[N], fa[N], size[N], va[N];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
void upd(int t){
	if (l[t]) fa[l[t]]=t;
	if (r[t]) fa[r[t]]=t;
	size[t]=size[l[t]]+size[r[t]]+1;
}
void build(int &t, int le, int ri){
	if (le>ri) return;
	int mid=le+ri>>1;
	va[t=++cnt]=mid;
	build(l[t],le,mid-1);
	build(r[t],mid+1,ri);
	upd(t);
}
void zig(int u){
	int f1=fa[u], f2=fa[f1];
	if (f2)
		if (l[f2]==f1) l[f2]=u;else r[f2]=u;
	fa[u]=f2;
	l[f1]=r[u];
	r[u]=f1;
	upd(f1);
	upd(u);
}
void zag(int u){
	int f1=fa[u], f2=fa[f1];
	if (f2)
		if (l[f2]==f1) l[f2]=u;else r[f2]=u;
	fa[u]=f2;
	r[f1]=l[u];
	l[u]=f1;
	upd(f1);
	upd(u);
}
void splay(int u){
	int f1=fa[u], f2=fa[f1];
	while (f2){
		if (l[f2]==f1) 
			if (l[f1]==u) zig(f1), zig(u);else zag(u), zig(u);
		else
			if (r[f1]==u) zag(f1), zag(u);else zig(u), zag(u);
		f1=fa[u], f2=fa[f1];
	}
	if (f1)
		if (l[f1]==u) zig(u);else zag(u);
	root=u;
}
int query(int u, int x){
	if (size[l[u]]+1==x) return u;
	if (size[l[u]]>=x) return query(l[u],x);
	return query(r[u],x-size[l[u]]-1);
}
void work(int x, int y){
	int u=query(root,x), v=query(root,y+2);
	//cout<<va[u]<<' '<<va[v]<<endl;
	splay(u);
	fa[r[u]]=0;
	splay(v);
	int w=l[v];
	r[fa[v]=u]=v;
	size[u]-=size[w];
	size[v]-=size[w];
	l[v]=fa[w]=0;
	root=u;
	
	splay(u=query(root,1));
	v=query(root,2);
	fa[r[u]]=0;
	splay(v);
	l[r[u]=v]=w;
	upd(v);
	upd(u);
	root=u;
}
void print(int u){
	if (!u) return;
	print(l[u]);
	if (va[u]>1 && va[u]<n+2) printf("%d ", va[u]-1);
	print(r[u]);
}
int main(){
	n=read();m=read();
	build(root,1,n+2);
	//for (int i=1;i<=n+2;i++) cout<<i<<' '<<l[i]<<' '<<r[i]<<' '<<size[i]<<endl;
	for (int i=1;i<=m;i++){
		int le=read(), ri=le+read()-1;
		work(le,ri);
	}
	print(root);
    return 0;
}
