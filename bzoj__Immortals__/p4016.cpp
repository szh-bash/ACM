#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 40000
#define M 500000
#define INF 999999999
using namespace std;
int n, m, K, cnt, root, sum;
int u[M], v[M], w[M], l[M], a[M];
int next[M], nu[M], va[M], nex[M], num[M], val[M];
int f[N], dis[N], flag[N], son[N], dep[N], g[N][2], ans[2];
int read(){
	int p=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
void add(int u, int v, int w){
	next[++cnt]=next[u];next[u]=cnt;nu[cnt]=v;va[cnt]=w;
}
void add2(int u, int v, int w){
	nex[++cnt]=nex[u];nex[u]=cnt;num[cnt]=v;val[cnt]=w;
}
void spfa(){
	l[1]=flag[1]=1;
	for (int i=1;i<=n;i++) dis[i]=INF;
	dis[1]=0;
	int le=0, ri=1;
	while (le<ri){
		int u=l[++le];
		flag[u]=0;
		for (int j=next[u];j;j=next[j]){
			int v=nu[j];
			if (dis[u]+va[j]<dis[v]){
				dis[v]=dis[u]+va[j];
				if (!flag[v]){
					l[++ri]=v;
					flag[v]=1;
				}
			}
		}
	}
}
void build_dis_graph(){
	cnt=n;
	for (int i=1;i<=n;i++) next[i]=0;
	for (int i=1;i<=m;i++){
		 if (dis[u[i]]+w[i]==dis[v[i]] || dis[v[i]]+w[i]==dis[u[i]]){
		 	add(u[i],v[i],w[i]);
		 	add(v[i],u[i],w[i]);
		 }
	}
}
void build_dis_tree(int t, int ri){
	int le=ri;
	flag[t]=1;
	for (int j=next[t];j;j=next[j])
		if (!flag[nu[j]] && dis[t]+va[j]==dis[nu[j]]) a[++ri]=nu[j];
	sort(a+le+1,a+1+ri);
	for (int j=le+1;j<=ri;j++){
		if (flag[a[j]]) continue;
		add2(t,a[j],dis[a[j]]-dis[t]);
		add2(a[j],t,dis[a[j]]-dis[t]);
		build_dis_tree(a[j],ri);
	}
}
void getroot(int u, int fa){
	f[u]=0;
	son[u]=1;
	for (int j=nex[u];j;j=nex[j]){
		int v=num[j];
		if (v==fa || !flag[v]) continue;
		getroot(v,u);
		son[u]+=son[v];
		f[u]=max(f[u],son[v]);
	}
	f[u]=max(f[u],sum-son[u]);
	if (f[u]<f[root]) root=u;
}
void getans(int u, int fa, int va, int depth){
	dep[u]=depth;
	son[u]=1;
	if (depth<K)
		if (g[K-depth][0]+va>ans[0])
			ans[0]=g[K-depth][0]+va,
			ans[1]=g[K-depth][1];
		else
			if (g[K-depth][0]+va==ans[0])
				ans[1]+=g[K-depth][1];
	for (int j=nex[u];j;j=nex[j]){
		int v=num[j];
		if (v==fa || !flag[v]) continue;
		getans(v,u,va+val[j],depth+1);
		son[u]+=son[v];
	}
}
void update(int u, int fa, int va){
	if (g[dep[u]+1][0]<va) g[dep[u]+1][0]=va, g[dep[u]+1][1]=1;
	else
		if (g[dep[u]+1][0]==va) g[dep[u]+1][1]++;
	for (int j=nex[u];j;j=nex[j]){
		int v=num[j];
		if (v==fa || !flag[v]) continue;
		update(v,u,va+val[j]);
	}
}
void calc(int u, int va){
	getans(u,0,va,1);
	update(u,0,va);
}
void clear(int u, int fa, int depth){
	g[K-depth][0]=g[depth+1][0]=-INF;
	g[K-depth][1]=g[depth+1][1]=0;
	for (int j=nex[u];j;j=nex[j]){
		int v=num[j];
		if (v==fa || !flag[v]) continue;
		clear(v,u,depth+1);
	}
}
void solve(int u){
	clear(u,0,0);
	flag[u]=g[1][0]=0;
	g[1][1]=1;
	for (int j=nex[u];j;j=nex[j]){
		int v=num[j];
		if (!flag[v]) continue;
		calc(v,val[j]);
	}
	for (int j=nex[u];j;j=nex[j]){
		int v=num[j];
		if (!flag[v]) continue;
		root=0;
		sum=son[v];
		getroot(v,0);
		solve(root);
	}
}
int main(){
	cnt=n=read(), m=read(), K=read();
	for (int i=1;i<=m;i++){
		u[i]=read();v[i]=read();w[i]=read();
		add(u[i],v[i],w[i]);
		add(v[i],u[i],w[i]);
	}
	spfa();
	build_dis_graph();
	cnt=n;
	build_dis_tree(1,0);
	f[root=0]=sum=n;
	getroot(1,0);
	solve(root);
	cout<<ans[0]<<' '<<ans[1]<<endl;
	return 0;
}
