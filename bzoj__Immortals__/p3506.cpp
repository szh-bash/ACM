#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 200000
using namespace std;
struct qlz{
	int v, p;
}q[N];
int n, root, a[N], l[N], r[N], list[N], p[N], size[N], fa[N];
bool cmp(qlz a, qlz b){
	if (a.v<b.v) return 1;
	if (a.v>b.v) return 0;
	return a.p<b.p;
}
int read(){
	int p=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
int build(int le, int ri){
	if (le>ri) return 0;
	int mid=le+ri>>1;
	if (l[mid]=build(le,mid-1)) fa[l[mid]]=mid;
	if (r[mid]=build(mid+1,ri)) fa[r[mid]]=mid;
	size[mid]=size[l[mid]]+size[r[mid]]+1;
	return mid;
}
void pushdown(int t){
	if (!p[t]) return;
	if (l[t]) p[l[t]]^=p[t];
	if (r[t]) p[r[t]]^=p[t];
	swap(l[t],r[t]);
	p[t]=0;
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
	int ri=1, f1=fa[t], f2=fa[f1];
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
int find(int t, int k){
	pushdown(t);
	if (size[l[t]]+1==k) return t;
	if (size[l[t]]+1<k) return find(r[t],k-size[l[t]]-1);
	return find(l[t],k);
}
int main(){
	n=read();
	for (int i=1;i<=n;i++) q[i].v=a[i]=read(),q[i].p=i;
	sort(q+1,q+1+n,cmp);
	root=build(1,n);
	int j=root;
	while (l[j]) size[j]++,j=l[j];
	size[j]++;l[j]=n+1;fa[n+1]=j;size[n+1]=1;
	j=root;
	while (r[j]) size[j]++,j=r[j];
	size[j]++;r[j]=n+2;fa[n+2]=j;size[n+2]=1;
	for (int i=1;i<=n;i++){
		int u=find(root,i), v=q[i].p;
		splay(v);
		printf("%d%c", size[l[v]], i==n?'\n':' ');
		if (size[l[v]]==i) continue;
		v=r[v];
		pushdown(v);
		while (l[v]) v=l[v], pushdown(v);
		splay(u);
		fa[r[u]]=0;
		splay(v);
		fa[r[u]=v]=root=u;
		p[l[v]]^=1;
	}
	return 0;
}
