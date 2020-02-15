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
