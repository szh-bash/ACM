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
#define num(x) (x>='0' && x<='9')
#define N 1000000
#define M 3000000
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int n, m, nex[M], nu[M], st[M], top, flag[N], d[N], fa[N];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
ll readll(){
    ll p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
inline void push(int x){
	nex[x]=0;
	st[++top]=x;
}
inline int get(){
	return st[top--];
}
inline void add(int u, int v){
	int cnt=get();
	nex[cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;
}
struct node{
	int n, v;
	node (){}
	node (int n, int v): n(n), v(v){}
	bool operator <(const node &o) const {return this->v<o.v;}
	bool operator >(const node &o) const {return this->v>o.v;}
};
int father(int x){return fa[x]==x?x:fa[x]=father(fa[x]);}
inline node merge(node x, node y, int tag){
	if (x>y) swap(x,y);
	int v=x.n, u=y.n;
	for (int j=nex[v], nj=nex[j];j;j=nj, nj=nex[j]){
		int fw=father(nu[j]);
		if (flag[fw]!=tag) add(u,nu[j]), y.v++;
		push(j);
	}
	nex[v]=0; //if not, nex[v] will be release twice
	d[u]=y.v;
	fa[v]=u;
	return y;
}
int Q, o[N], co[N];
node l[N];
void solve(){
	n=read(), m=read();
	for (int i=1;i<=n;i++) nex[i]=d[i]=flag[i]=0, fa[i]=co[i]=i;
	for (int i=1;i<=m;i++){
		int u=read()+1, v=read()+1;
		add(u,v);
		add(v,u);
		d[u]++;
		d[v]++;
	}
	Q=read();
	for (int i=1;i<=Q;i++){
		o[i]=read()+1;
		int x=father(o[i]);
		if (co[fa[o[i]]]!=o[i]) continue;
		node nd=node(x, d[x]);
		flag[x]=i;
		int t=0;
		for (int j=nex[x];j;j=nex[j]){
			int y=father(nu[j]);
			if (flag[y]==i) continue;
			flag[y]=i;
			l[++t]=node(y,d[y]);
		}
		for (int j=1;j<=t;j++)
			nd = merge(nd, l[j], i);
		co[father(o[i])]=o[i];
		int tp=fa[o[i]];
		for (int j=nex[tp], nj=nex[j];j;j=nj, nj=nex[j])
			if (father(nu[j])==tp)
				nex[tp]=nj,
				push(j),
				d[tp]--;
			else break;
	}
	for (int i=1;i<=n;i++) printf("%d%s", co[father(i)]-1, (i==n?"\n":" "));
}
int main(){
	for (int i=N+1;i<M;i++) push(i);
	for (int _=read();_;_--) solve();
    return 0;
}
