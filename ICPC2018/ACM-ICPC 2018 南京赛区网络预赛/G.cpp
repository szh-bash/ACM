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
#define N 200000
#define Q 200000
#define INF 2000000
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int n, m, q, root, f[N], fa[N], r[N], l[N], k[N];
struct question{
	int d, n, ans_0, ans_1;
}qu[Q];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
bool cmp(question a, question b){ return a.d<b.d;}
bool cmpn(question a, question b){ return a.n<b.n;}
void upd(int u){
	if (l[u]) fa[l[u]]=u;
	if (r[u]) fa[r[u]]=u;
	f[u]=min(k[u],min(f[l[u]],f[r[u]]));
}
void zig(int u){
	int f1=fa[u], f2=fa[f1];
	if (f2)
		if(l[f2]==f1) l[f2]=u;else r[f2]=u;
	fa[u]=f2;
	l[f1]=r[u];
	r[u]=f1;
	upd(f1);
	upd(u);
}
void zag(int u){
	int f1=fa[u], f2=fa[f1];
	if (f2)
		if(l[f2]==f1) l[f2]=u;else r[f2]=u;
	fa[u]=f2;
	r[f1]=l[u];
	l[u]=f1;
	upd(f1);
	upd(u);
}
void splay(int u){
	int f1=fa[u], f2=fa[f1];
	//cout<<u<<" lyk ";print(root);cout<<endl;
	while (f2){
		if (l[f2]==f1)
			if (l[f1]==u) zig(f1), zig(u);
			else zag(u), zig(u);
		else
			if (r[f1]==u) zag(f1), zag(u);
			else zig(u), zag(u);
		f1=fa[u];f2=fa[f1];
		//cout<<u<<' '<<f1<<' '<<f2<<endl;
	}
	if (f1)
		if (l[f1]==u) zig(u);else zag(u);
	root=u;
}
void insert(int &u, int v){
	//cout<<u<<endl;
	if (!u) {u=v;f[v]=k[v];return;}
	if (v>u) insert(r[u],v);
	else insert(l[u],v);
	upd(u);
}
int get(int u, int w){
	if (l[u] && f[l[u]]<=w) return get(l[u],w);
	if (k[u]<=w) return u;
	return get(r[u],w);
}
void del(int u){
	splay(u);
	//cout<<u<<endl;
	if (!r[u]) fa[l[u]]=0, root=l[u];
	else{
		int v=r[u];
		fa[v]=0;
		while (l[v]) v=l[v];
		splay(v);
		l[v]=l[u];
		upd(v);
	}
}
int main(){
	n=read();m=read();
	for (int i=1;i<=n;i++) k[i]=read();
	q=read();
	for (int i=1;i<=q;i++) qu[i].d=read(), qu[i].n=i;
	sort(qu+1,qu+1+q,cmp);
	int cot=0, mon=0, money=0;
	f[0]=INF;
	for (int i=1;i<=n;i++){
		//cout<<i<<' '<<root<<endl;
		insert(root,i),
		splay(i);
	}
	//cout<<endl;
	int r=1;
	while (cot<n){
		int tmp=(f[root]-money)/m;
		int new_mon=mon+tmp+(tmp*m!=(f[root]-money));
		//cout<<cot<<' '<<f[root]<<' '<<new_mon<<endl;
		//printf("%d %d %d\n", cot, f[root], new_mon);
		while (r<=q && qu[r].d<new_mon)
			qu[r].ans_1=money+(qu[r].d-mon)*m,
			qu[r].ans_0=cot,
			r++;
		money+=(tmp+(tmp*m!=(f[root]-money)))*m;
		while (cot<n && money>=f[root]){
			int v=get(root, money);
			money-=k[v];
			del(v);
			cot++;
			//cout<<cot<<' '<<money<<" "<<f[root]<<endl;
		}
		while (r<=q && qu[r].d==new_mon)
			qu[r].ans_1=money,
			qu[r].ans_0=cot,
			r++;
		mon=new_mon;
	}
	//printf("%d %d %d\n", r, cot, money);
	for (;r<=q;r++) qu[r].ans_0=cot, qu[r].ans_1=money;
	sort(qu+1,qu+1+q,cmpn);
	//cout<<endl;
	for (int i=1;i<=q;i++){
		printf("%d %d\n", qu[i].ans_0, qu[i].ans_1);
		//cout<<qu[i].ans_0<<' '<<qu[i].ans_1<<endl;
	}
	//cout<<qu[q].ans_0<<' '<<qu[q].ans_1;
    return 0;
}
