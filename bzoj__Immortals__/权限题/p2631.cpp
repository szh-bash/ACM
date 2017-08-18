#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define mo 51061
#define N 200000
typedef unsigned int ll;
using namespace std;
int n, q, size[N], l[N], r[N], fa[N], rev[N], list[N];
ll sum[N], f[N], at[N], mt[N];
int read(){
	int p=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
bool isroot(int t){
	return (l[fa[t]]!=t) && (r[fa[t]]!=t);
}
void calc(int u, int m, int a){
	if (!u) return;
	f[u]=(f[u]*m+a)%mo;
	sum[u]=(sum[u]*m+a*size[u])%mo;
	at[u]=(at[u]*m+a)%mo;
	mt[u]=(mt[u]*m)%mo;
}
void update(int t){
	if (l[t]) fa[l[t]]=t;
	if (r[t]) fa[r[t]]=t;
	sum[t]=(f[t]+sum[l[t]]+sum[r[t]])%mo;
	size[t]=1+size[l[t]]+size[r[t]];
}
void pushdown(int t){
	if (rev[t]){
		swap(l[t],r[t]);
		rev[l[t]]^=1;
		rev[r[t]]^=1;
		rev[t]=0;
	}
	int ta=at[t], tm=mt[t];
	if (ta || tm!=1){
		calc(l[t],tm,ta);
		calc(r[t],tm,ta);
	}
	at[t]=0;mt[t]=1;
}
void zig(int t){
	int f1=fa[t], f2=fa[f1];
	if (!isroot(f1))
		if (l[f2]==f1) l[f2]=t;else r[f2]=t;
	fa[t]=f2;
	l[f1]=r[t];
	r[t]=f1;
	update(f1);
	update(t);
}
void zag(int t){
	int f1=fa[t], f2=fa[f1];
	if (!isroot(f1))
		if (l[f2]==f1) l[f2]=t;else r[f2]=t;
	fa[t]=f2;
	r[f1]=l[t];
	l[t]=f1;
	update(f1);
	update(t);
}
void splay(int t){
	int ri=1;
	list[1]=t;
	for (int i=1;!isroot(list[i]);i++) list[++ri]=fa[list[i]];
	for (int i=ri;i;i--){
		pushdown(list[i]);
	}
	int f1=fa[t], f2=fa[f1];
	while (!isroot(t) && !isroot(f1)){
		if (l[f2]==f1)
			if (l[f1]==t) zig(f1), zig(t);
			else zag(t), zig(t);
		else
			if (r[f1]==t) zag(f1), zag(t);
			else zig(t), zag(t);
		f1=fa[t];f2=fa[f1];
	}
	if (!isroot(t))
		if (l[f1]==t) zig(t);else zag(t);
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
void split(int u, int v){
	makeroot(u);
	access(v);
	splay(v);
}
void link(int u, int v){
	makeroot(u);
	fa[u]=v;
}
void cut(int u, int v){
	split(u,v);
	fa[u]=l[v]=0;
	update(v);
}
void modify(int u, int v, int m, int a){
	split(u,v);
	calc(v,m,a);
}
int main(){
	n=read();q=read();
	for (int i=1;i<=n;i++) size[i]=f[i]=sum[i]=mt[i]=1;
	for (int i=1;i<n;i++){
		int u=read(), v=read();
		link(u,v);
	}
	for (int i=1;i<=q;i++){
		char s[2];
		scanf("%s", s);
		int u=read(), v=read();
		if (s[0]=='+'){
			int c=read();
			modify(u,v,1,c);
 		}
		if (s[0]=='-'){
			cut(u,v);
			u=read();v=read();
			link(u,v);
		}
		if (s[0]=='*'){
			int c=read();
			modify(u,v,c,0);
		}
		if (s[0]=='/'){
			split(u,v);
			printf("%d\n", sum[v]);
		}
	}
	return 0;
}
