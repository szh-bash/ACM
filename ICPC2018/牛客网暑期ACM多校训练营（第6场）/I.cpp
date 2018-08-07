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
#define N 800000
#define mo 998244353
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int n, m, x, cnt, countt, root[10], l[N], r[N], g[N], v[N], fa[N], flag[N], ans[N], ansm[N];
ll res;
struct node{
	int v, n;
}p[N];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
void upd(int u){
	if (l[u]) fa[l[u]]=u;
	if (r[u]) fa[r[u]]=u;
}
void insert(int &u, int w){
	if (!u){
		u=++cnt;
		l[u]=r[u]=fa[u]=0;
		v[u]=p[w].v;
		g[u]=p[w].n;
		return;
	}
	if (v[u]<p[w].v) insert(r[u],w);
	else insert(l[u],w);
	upd(u);
}
void zig(int u){
	int f1=fa[u], f2=fa[f1];
	if (f2)
		if (l[f2]==f1) l[f2]=u;else r[f2]=u;
	fa[fa[f1]=u]=f2;
	l[f1]=r[u];
	r[u]=f1;
	upd(f1);
	upd(u);
}
void zag(int u){
	int f1=fa[u], f2=fa[f1];
	if (f2)
		if (l[f2]==f1) l[f2]=u;else r[f2]=u;
	fa[fa[f1]=u]=f2;
	r[f1]=l[u];
	l[u]=f1;
	upd(f1);
	upd(u);
}
void splay(int u, int t){
	int f1=fa[u], f2=fa[f1];
	while (f2){
		if (l[f2]==f1)
			if (l[f1]==u) zig(f1), zig(u);
			else zag(u), zig(u);
		else
			if (r[f1]==u) zag(f1), zag(u);
			else zig(u), zag(u);
		f1=fa[u], f2=fa[f1];
	}
	if (f1)
		if (l[f1]==u) zig(u);else zag(u);	
	root[t]=u;
}
void print(int u){
	if (!u) return;
	print(l[u]);
	cout<<v[u]<<' ';
	print(r[u]);
}
void BUILD(){
	cnt=root[0]=root[1]=0;
	for (int i=1;i<=n;i++)
		insert(root[0],i),
		splay(i,0);
//	print(root[0]);cout<<endl;
	for (int i=n+1;i<=2*n;i++)
		insert(root[1],i),
		splay(i,1);
	//print(root[1]);cout<<endl;
}
int queryL(int u){
	//cout<<u<<' '<<v[u]<<' '<<x<<endl;
	if (!u) return 0;
	if (v[u]<=x){
		int p=queryL(r[u]);
		return p?p:u;
	}
	else return queryL(l[u]);
}
int queryR(int u){
	if (!u) return 0;
	if (v[u]<x){
		int p=queryR(r[u]);
		return p?p:u;
	}
	else return queryR(l[u]);
}
void del(int u, int t){
	if (!u) return;
	flag[g[u]]--;
	if(!flag[g[u]])
		//cout<<g[u]<<' '<<t<<' '<<x<<endl;
		ans[g[u]]=t,
		res=res*g[u]%mo,
		countt++;
	del(l[u], t);
	del(r[u], t);
}
void workL(int t){
	if (!root[0]) return;
	int u=queryL(root[0]);
	//cout<<"Find "<<u<<' '<<g[u]<<' '<<v[u]<<' '<<x<<endl;
	if (!u) return;
	splay(u,0);
	if (!r[u]){
		del(root[0], t);
		root[0]=0;
	}
	else{
		fa[root[0]=r[u]]=0;
		del(l[u], t);
		if (!(--flag[g[u]])){
			res=res*g[u]%mo;
			ans[g[u]]=t;
			countt++;
		}
	}
}
void workR(int t){
	if (!root[1]) return;
	int u=queryR(root[1]);
	if (!u){
	//	cout<<"lyksb"<<endl;
		del(root[1], t);
		root[1]=0;
		return;
	}
	splay(u,1);
	if (!r[u]) return;
	del(r[u],t);
	r[u]=0;
	upd(u);
}
int main(){
	for (int _=read(), __=1;_;_--, __++){
		n=read();m=read();
		for (int i=1;i<=n;i++)
			p[i].v=read(),
			p[i+n].v=read(),
			p[i].n=p[i+n].n=i,
			flag[i]=2,
			ans[i]=0;
		BUILD();
		res=0;
		for (int i=1;i<=m;i++){
			x=read()^res;
			//cout<<"LYK "<<' '<<x<<endl;
			countt=0;
			res=1;
			workL(i);
			workR(i);
			if (!countt) res=0;
			ansm[i]=countt;
			//print(root[0]);cout<<endl;
			//print(root[1]);cout<<endl;
			//cout<<"LYK said: "<<countt<<endl;
		}
		cout<<"Case #"<<__<<":"<<endl;
		for (int i=1;i<=m;i++)
			printf("%d\n", ansm[i]);
		for (int i=1;i<=n;i++)
			printf("%d ", ans[i]);cout<<endl;
	}
    return 0;
}
