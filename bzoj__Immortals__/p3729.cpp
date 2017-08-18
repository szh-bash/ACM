#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define INF 99999999
#define N 300000
using namespace std;
int n, cnt, L, root, ans, dfn[N], g[N], fa[N], size[N], v[N], f[N][3], l[N], r[N], dep[N], next[N], nu[N];
int read(){
	int p=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
void add(int u, int v){
	next[++cnt]=next[u];next[u]=cnt;nu[cnt]=v;
}
void dfs(int t, int fa){
	g[dfn[t]=++cnt]=t;
	for (int j=next[t];j;j=next[j]){
		int v=nu[j];
		if (v==fa) continue;
		dep[v]=dep[t]+1;
		dfs(v,t);
	}
}
void update(int t){
	if (l[t]) fa[l[t]]=t;
	if (r[t]) fa[r[t]]=t;
	f[t][0]=f[l[t]][0]^f[r[t]][0]^(((dep[g[t]]&1)^1)*v[g[t]]);
	f[t][1]=f[l[t]][1]^f[r[t]][1]^((dep[g[t]]&1)*v[g[t]]);
	f[t][2]=min(dep[g[t]],min(f[l[t]][2], f[r[t]][2]));
	size[t]=size[l[t]]+size[r[t]]+1;
}
int build(int le, int ri){
	if (le>ri) return 0;
	int mid=le+ri>>1;
	l[mid]=build(le,mid-1);
	r[mid]=build(mid+1,ri);
	update(mid);
	return mid;
}
void insert(int &t, int k, int p){
	if (!t){
		size[t=++n]=1;
		f[t][0]=((dep[p]&1)^1)*v[p];
		f[t][1]=(dep[p]&1)*v[p];
		f[t][2]=dep[p];
		g[dfn[p]=n]=p;
		return;
	}
	if (size[l[t]]+1<=k) insert(r[t],k-size[l[t]]-1,p);
	else insert(l[t],k,p);
	update(t);
}
void zig(int t){
	int f1=fa[t], f2=fa[f1];
	if (f2)
		if (l[f2]==f1) l[f2]=t;else r[f2]=t;
	fa[fa[f1]=t]=f2;
	if (l[f1]=r[t]) fa[l[f1]]=f1;
	r[t]=f1;
	update(f1);
	update(t);
}
void zag(int t){
	int f1=fa[t], f2=fa[f1];
	if (f2)
		if (l[f2]==f1) l[f2]=t;else r[f2]=t;
	fa[fa[f1]=t]=f2;
	if (r[f1]=l[t]) fa[r[f1]]=f1;
	l[t]=f1;
	update(f1);
	update(t);
}
void splay(int t){
	int f1=fa[t], f2=fa[f1];
	while (f2){
		if (l[f2]==f1)
			if (l[f1]==t) zig(f1), zig(t);
			else zag(t), zig(t);
		else
			if (r[f1]==t) zag(f1), zag(t);
			else zig(t), zag(t);
		f1=fa[t];f2=fa[f1];
	}
	if (f1)
		if (l[f1]==t) zig(t);else zag(t);
	root=t;
}
int find(int t, int depth){
	while (1)
		if (f[l[t]][2]<=depth) t=l[t];
		else
			if (dep[g[t]]<=depth) break;
			else t=r[t];
	return t;
}
int main(){
	cnt=n=read();L=read()+1;
	f[0][2]=INF;
	for (int i=1;i<=n;i++) v[i]=read()%L;
	for (int i=1;i<n;i++){
		int u=read(), v=read();
		add(u,v);
		add(v,u);
	}
	dfs(dep[1]=1,cnt=0);
	root=build(1,n);
	insert(root,0,N-3);
	insert(root,n+1,N-2);
	for (int m=read();m;m--){
		int op=read(), x=read()^ans, y, tx;
		if (op==1){
			x=dfn[tx=x];
			splay(x);
			int u=l[x], v=find(r[x],dep[tx]);
			while (r[u]) u=r[u];
			splay(u);
			fa[r[u]]=0;
			splay(v);
			root=fa[r[u]=v]=u;
			printf("%s\n", f[l[v]][(dep[tx]&1)^1]?"MeiZ":"GTY");
			ans+=f[l[v]][(dep[tx]&1)^1]>0;
		}
		if (op==2){
			splay(dfn[x]);
			v[x]=(read()^ans)%L;
			update(dfn[x]);
		}
		if (op==3){
			dep[y=read()^ans]=dep[x]+1;
			v[y]=(read()^ans)%L;
			splay(dfn[x]);
			insert(root,size[l[dfn[x]]]+1,y);
			splay(dfn[y]);
		}
	}
	return 0;
}
