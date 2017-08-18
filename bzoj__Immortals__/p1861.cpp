#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 200000
typedef long long LL;
using namespace std;
int root, cnt, n, m, a[N], size[N], l[N], r[N], fa[N], f[N], p[N];
char s[10];
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
	if (size[l[t]]+1==k) return t;
	if (size[l[t]]+1<k) return find(r[t],k-size[l[t]]-1);
	return find(l[t],k);
}
inline void del(int x){
	splay(x);
	if (!l[x]) fa[root=r[x]]=0;
	else{
		int j=l[x];
		fa[root=l[x]]=0;
		while (j && r[j]){
			size[j]+=size[r[x]];
			j=r[j];
		}
		r[j]=r[x];
		size[j]+=size[r[x]];
		if (r[x]) fa[r[x]]=j;
	}
	fa[x]=l[x]=r[x]=0;
	size[x]=1;
}
inline int build(int le, int ri){
	if (le>ri) return 0;
	int mid=le+ri>>1, t=++cnt;
	f[t]=a[mid];
	p[a[mid]]=t;
	if (l[t]=build(le,mid-1)) fa[l[t]]=t;
	if (r[t]=build(mid+1,ri)) fa[r[t]]=t;
	size[t]=size[l[t]]+size[r[t]]+1;
	return t;
}
int main(){
	n=read();m=read();
	for (int i=1;i<=n;i++) a[i]=read();
	build(1,n);
	root=1;
	for (int i=1;i<=m;i++){
		scanf("%s", s);
		int x=read();
		if (s[0]=='T'){
			del(p[x]);
			int u=find(root,1);
			splay(u);
			l[u]=p[x];
			fa[p[x]]=u;
			size[u]++;
		}
		if (s[0]=='B'){
			del(p[x]);
			int u=find(root,n-1);
			splay(u);
			r[u]=p[x];
			fa[p[x]]=u;
			size[u]++;
		}
		if (s[0]=='I'){
			int q=read(), y, u;
			if (!q) continue;
			splay(p[x]);
			y=size[l[p[x]]];
			del(p[x]);
			if (!(y+q)){
				int u=find(root,1);
				splay(u);
				l[u]=p[x];
				fa[p[x]]=u;
				size[u]++;
				continue;
			}
			u=find(root,y+q);
			splay(u);
			size[u]++;
			if (!r[u]){
				r[u]=p[x];
				fa[p[x]]=u;
			}
			else{
				int j=r[u];
				while (j && l[j]) size[j]++,j=l[j];
				size[j]++;
				l[j]=p[x];
				fa[p[x]]=j;
			}
		}
		if (s[0]=='A'){
			splay(p[x]);
			printf("%d\n", size[l[p[x]]]);
		}
		if (s[0]=='Q'){
			printf("%d\n", f[find(root,x)]);
		}
	}
	return 0;
}
