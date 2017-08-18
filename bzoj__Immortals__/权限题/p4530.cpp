#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define N 200000
using namespace std;
int n, l[N], r[N], fa[N], list[N], sum[N];
bool rev[N];
int read(){
	int p=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
bool isroot(int u){
	return l[fa[u]]!=u && r[fa[u]]!=u;
}
void update(int u){
	if (l[u]) fa[l[u]]=u;
	if (r[u]) fa[r[u]]=u;
}
void pushdown(int u){
	if (rev[u]){
		swap(l[u],r[u]);
		rev[u]^=1;rev[l[u]]^=1;rev[r[u]]^=1;
	}
}
void zig(int u){
	int f1=fa[u], f2=fa[f1];
	if (!isroot(f1))
		if (l[f2]==f1) l[f2]=u;else r[f2]=u;
	fa[u]=f2;
	sum[f1]-=sum[u];
	sum[u]-=sum[r[u]];
	sum[f1]+=sum[r[u]];
	sum[u]+=sum[f1];
	l[f1]=r[u];
	r[u]=f1;
	update(f1);
	update(u);
}
void zag(int u){
	int f1=fa[u], f2=fa[f1];
	if (!isroot(f1))
		if (l[f2]==f1) l[f2]=u;else r[f2]=u;
	sum[f1]-=sum[u];
	sum[u]-=sum[l[u]];
	sum[f1]+=sum[l[u]];
	sum[u]+=sum[f1];
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
int main(){
	n=read();
	for (int i=1;i<=n;i++) sum[i]=1;
	for (int m=read();m;m--){
		char s[2];scanf("%s", s);
		int u=read(), v=read();
		if (s[0]=='A'){
			makeroot(u);
			makeroot(v);
			fa[u]=v;
			sum[v]+=sum[u];
		}
		if (s[0]=='Q'){
			makeroot(u);
			access(v);
			splay(v);
			printf("%d\n", (sum[v]-sum[u])*sum[u]);
		}
	}
	return 0;
}
