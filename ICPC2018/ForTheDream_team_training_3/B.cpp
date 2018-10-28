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
#define dd 0
#define n0 1
#define n1 2
#define s0 3
#define s1 4
#define PAR 5
#define mo 1000000007
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
struct node{
	int bit;
	int d;
	int n0, n1;
	int s0, s1;
	int par[PAR];
	//int f;
	md p[2];
}nd[N];
struct md{
	int pd;
	int pn0, pn1;
	int ps0, ps1;
	int par[PAR];
	//int pf;
};
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
bool isroot(int t){
	return (l[fa[t]]!=t) && (r[fa[t]]!=t);
}
void update(int t){
	if (l[t]) fa[l[t]]=t;
	if (r[t]) fa[r[t]]=t;
	size[t]=size[l[t]]+size[r[t]]+1;
}
void pushdown(int t){
	for (int i=0;i<2;i++){
		int o=i?-1:1, oo, v;
		if (l[t]){
			v=l[t];
			oo=(nd[t].bit==nd[v].bit)?1:-1;
			for (int j=0;j<PAR;j++)
				nd[v].par[j]+=
		}
		if (r[t]){
			v=r[t];
			oo=(nd[t].bit==nd[v].bit)?1:-1;
		}

	}
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
	for (int i=1;!isroot(list[i]);i++) list[++ri] fa[list[i]];
	for (int i=ri;i;i--) pushdown(list[i]);

	int f1=fa[t], f2=fa[f1];
	while (!isroot(t) && !isroot(f1))
		if (l[f2]==f1)
			if (l[f1]==t) zig(f1), zig(t);
			else zag(t), zig(t);
		else
			if (r[f1]==t) zag(f1), zag(t);
			else zig(t), zag(t);
	if (!isroot(t))
		if (l[f1]==t) zig(t);else zag(t);
	
}
void access(int u){
	for (int v=0;u;v=u, u=fa[u]){
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
void add_tree(int u, int v, int type){//insert v into u
	//type 0 -> ls
	//type 1 -> rs
}
void remove_tree(int u){
	
}
void cut_point(int u){
	access(u);
	splay(u);
	if (!l[u]) return;
	fa[l[u]]=0;
	remove_tree(l[u],u);
}
void modify_point(int u, int d){
	access(u);
	int dt=d-nd[u].w;
	nd[u].p[0].pw+=dt;
}
void modify_tree(){
}
int getroot(int u){
	access(u);
	splay(u);
	int p=u;
	while (l[p]) pushdown(p=l[p]);
	return p;
}
bool isancestor(int u, int v){
	access(u);
	splay(u);
	int depu=size[l[u]];
	acces(v);
	splay(v);
	int depv=size[r[u]];
	return getroot(u)==getroot(v) && depu<depv;
}
void initital(){
}
int main(){
	while (~scanf("%d", &n)){
		initial();
		for (int i=1;i<=n;i++){
		}
		for (int m=read();m;m--){
			int op=read(), u, v, dd;
			if (op==1){
				u=read();v=read();
				if (ls[v] || isancestor(u,v)){
					puts("F");
					continue;
				}
				add_tree(v,u,0);
				puts("S");
			}
			if (op==2){
				u=read();v=read();
				if (rs[v] || isancestor(u,v)){
					puts("F");
					continue;
				}
				add_tree(v,u,1);
				puts("S");
			}
			if (op==3){
				v=read();
				if (!ls[v] || !rs[v]){
					puts("F");
					continue;
				}
				access(v);
				splay(v);
				
				puts("S");
			}
			if (op==4){
				v=read();d=read();
				int dt=d-nd[v].w;
				access(v);
				splay(v);
			//	nd[v].s0+=dt;
			//	nd[v].p[0].ps0+=dt;
				nd[v].par[s0]+=dt;
				nd[v].p[0].par[s0]+=dt;
				pushdown(v);
				puts("S");
			}
			if (op==5){
				v=read();d=read();
				access(v);
				splay(v);
				nd[v].par[dd]+=d;
				nd[v].par[s0]+=nd[v].par[n0]*d;
				nd[v].par[s1]+=nd[v].par[n1]*d;
				nd[v].p
				pushdown(v);
				puts("S");
			}
			if (op==6){
				v=read();
				access(v);
				splay(v);

			}
		}
	}
    return 0;
}
