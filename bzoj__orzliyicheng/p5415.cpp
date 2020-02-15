#include <queue>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define inf 2000000100
#define N 400005
#define M N*3
#define NLGN N*31
typedef long long ll;
using namespace std;
int n, m, cnt, root[N];
int size[NLGN], fa[NLGN], ls[NLGN], rs[NLGN], tag[NLGN], g[NLGN];
struct edge{
	int u, v, w, a;
	bool operator <(const edge &o) const {return this->a>o.a;}
	bool operator >(const edge &o) const {return this->a<o.a;}
}l[N];
int nex[M], nu[M], va[M];
struct node{
	int n, dist;
	node (int n, int dist): n(n), dist(dist){}
	bool operator <(const node &o) const {return this->dist<o.dist;}
	bool operator >(const node &o) const {return this->dist>o.dist;} 
};
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=='-'?q=-1:0, ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
void link(int u, int v, int w){
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;va[cnt]=w;
}
int flag[N], dist[N];
priority_queue<node, vector<node>, greater<node> > q;
void dijkstra(int st){
	for (int i=1;i<=n;i++) dist[i]=inf, flag[i]=0;
	dist[st]=0;
	q.push(node(st,0));
	while (!q.empty()){
		node curNode=q.top();
		q.pop();
		int u=curNode.n;
		flag[u]=1;
		for (int j=nex[u];j;j=nex[j]){
			int v=nu[j];
			if (!flag[v] && dist[u]+va[j]<dist[v])
				dist[v]=dist[u]+va[j],
				q.push(node(v,dist[v]));
		}
		while (!q.empty() && flag[q.top().n]) q.pop();
	}
}
int query(int t, int l, int r, int x){
	if (l==r) return t;
	int mid=l+r>>1;
	if (x<=mid) return query(ls[t],l,mid,x);
	return query(rs[t],mid+1,r,x);
}
int find(int t, int x){ //t is root_address
	int v=query(t,1,n,x);
	if (x==fa[v]) return v;
	return find(t,fa[v]);
}
int new_node(){ //multi_test
	++cnt;
	fa[cnt]=size[cnt]=g[cnt]=ls[cnt]=rs[cnt]=tag[cnt]=0;
	return cnt;
}
void build(int &t, int l, int r){
	t=new_node();
	if (l==r){
		fa[t]=l;
		size[t]=1;
		g[t]=dist[l];
		return;
	}
	int mid=l+r>>1;
	build(ls[t],l,mid);
	build(rs[t],mid+1,r);
}
void insert(int u, int v, int x, int y, int z, int dis){
	int tv=v;
	int le=1, ri=n;
	while (le<ri){
		int mid=le+ri>>1;
		if (x<=mid){
			if (!rs[v]) rs[v]=rs[u];
			if (!ls[v] || tag[ls[v]]!=tv) ls[v]=new_node(), tag[cnt]=tv;
			v=ls[v],
			u=ls[u],
			ri=mid;
		}
		else{
			if (!ls[v]) ls[v]=ls[u];
			if (!rs[v] || tag[rs[v]]!=tv) rs[v]=new_node(), tag[cnt]=tv;
			v=rs[v],
			u=rs[u],
			le=mid+1;
		}
	}
	fa[v]=y;
	size[v]=z;
	g[v]=dis;
}
int get(int p){
	int le=0, ri=m+1;
	while (le<ri-1){
		int mid=le+ri>>1;
		if (l[mid].a>p) le=mid;
		else ri=mid;
	}
	return le;
}
void solve(){
	cnt=n=read();m=read();
	for (int i=1;i<=n;i++) nex[i]=0;
	for (int i=1;i<=m;i++){
		int u=read(), v=read(), w=read(), a=read();
		l[i]=edge{u,v,w,a};
		link(u,v,w);
		link(v,u,w);
	}
	dijkstra(1);
	cnt=0;
	build(root[0],1,n);
	sort(l+1,l+1+m);
	for (int i=1;i<=m;i++){
		int u=l[i].u, v=l[i].v;
		u=find(root[i-1],u);
		v=find(root[i-1],v);
		root[i]=root[i-1];
		if (fa[u]==fa[v]) continue;
		root[i]=new_node();
		if (size[u]>size[v]) swap(u,v);
		insert(root[i-1], root[i], fa[u], fa[v], size[u], g[u]);
		insert(root[i-1], root[i], fa[v], fa[v], size[u]+size[v], min(g[u], g[v]));
	}
	int ans=0;
	int Q=read(), K=read(), S=read();
	for (int i=1;i<=Q;i++){
		int v=(read()+1ll*K*ans-1)%n+1;
		int p=(read()+1ll*K*ans)%(S+1);
		int rt=get(p);
		int par=find(root[rt],v);
		printf("%d\n", ans=g[find(root[get(p)],v)]);
	}
}
int main(){
	for (int _=read();_;_--) solve();
	return 0;
}
