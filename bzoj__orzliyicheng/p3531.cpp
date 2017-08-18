#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define N 110000
using namespace std;
int cnt, sz, q, n, c[N], w[N], id[N], dep[N], fa[N], son[N], bl[N],
	root[N], lc[N*20], rc[N*20], sum[N*20], maxx[N*20],
	next[N*3], nu[N*3];
void add(int u, int v){
	next[++cnt]=next[u];next[u]=cnt;nu[cnt]=v;
}
void dfs1(int x){
	son[x]++;
	for (int j=next[x];j;j=next[j]){
		if (fa[x]==nu[j]) continue;
		fa[nu[j]]=x;
		dep[nu[j]]=dep[x]+1;
		dfs1(nu[j]);
		son[x]+=son[nu[j]];
	}
}
void dfs2(int x,int chain){
	sz++;int y=0;
	id[x]=sz;
	bl[x]=chain;
	for (int j=next[x];j;j=next[j]){
		if (fa[x]==nu[j]) continue;
		if (son[nu[j]]>son[y]) y=nu[j];
	}
	if (!y) return;
	dfs2(y,chain);
	for (int j=next[x];j;j=next[j]){
		if (fa[x]==nu[j] || y==nu[j]) continue;
		dfs2(nu[j],nu[j]);
	}
}
void up(int k){
	sum[k]=sum[lc[k]]+sum[rc[k]];
	maxx[k]=max(maxx[lc[k]],maxx[rc[k]]);
}
void change(int &y, int l, int r, int x, int w){
	if (!y) y=++cnt;
	if (l==r) {sum[y]=maxx[y]=w;return;}
	int mid=l+r>>1;
	if (x<=mid) change(lc[y],l,mid,x,w);
	else change(rc[y],mid+1,r,x,w);
	up(y);	
}
int work(int k, int l, int r, int opl, int opr, bool p){
	if (l>=opl && r<=opr) return p?maxx[k]:sum[k];
	int mid=l+r>>1, a=0, b=0;
	if (mid>=opl) a=work(lc[k],l,mid,opl,opr,p);
	if (mid<opr) b=work(rc[k],mid+1,r,opl,opr,p);
	return p?max(a,b):a+b;
}
void operation(int q, int u, int v, bool p){
	int ans=0;
	while (bl[u]!=bl[v]){
		if (dep[bl[u]]<dep[bl[v]]) swap(u,v);
		if (!p) ans+=work(root[q],1,n,id[bl[u]],id[u],p);
		else ans=max(ans,work(root[q],1,n,id[bl[u]],id[u],p));
		u=fa[bl[u]];
	}
	if (id[u]>id[v]) swap(u,v);
	if (!p) ans+=work(root[q],1,n,id[u],id[v],p);
	else ans=max(ans,work(root[q],1,n,id[u],id[v],p));
	printf("%d\n", ans);
}
void solve(){
	for (int i=1;i<=n;i++)
		change(root[c[i]],1,n,id[i],w[i]);
	for (int i=1;i<=q;i++){
		char C[3];int x, y;
		scanf("%s%d%d", C, &x, &y);
		if (C[0]=='C'){
			if (C[1]=='C'){
				change(root[c[x]],1,n,id[x],0);
				c[x]=y;
				change(root[c[x]],1,n,id[x],w[x]);
			}
			else{
				change(root[c[x]],1,n,id[x],y);
				w[x]=y;
			}
		}
		else{
			if (C[1]=='S') operation(c[x],x,y,0);
			else operation(c[x],x,y,1);
		}
	}
}
int main(){
	cin>>n>>q;
	for (int i=1;i<=n;i++)
		scanf("%d%d", &w[i], &c[i]);
	cnt=n;
	for (int i=1;i<n;i++){
		int u, v;
		scanf("%d%d", &u, &v);
		add(u,v);add(v,u);
	}
	dfs1(1);
	dfs2(1,1);
	solve();
	return 0;
}
