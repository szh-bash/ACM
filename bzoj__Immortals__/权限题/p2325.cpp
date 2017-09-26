#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
typedef long long ll;
using namespace std;
int read(){
	int p=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
void add(int u, int v){
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;
}
void dfs1(int u, int father){
	son[u]=1;
	for (int j=nex[u];j;j=nex[j]){
		int v=nu[j];
		if (v==father) continue;
		dep[v]=dep[u]+1;
		dfs1(v,fa[v]=u);
		son[u]+=son[v];
		if (son[v]>son[pre[u]]) pre[u]=v;
	}
}
void dfs2(int u, int father){
	if (!u) return;
	dfn[u]=++DFN;
	top[u]=pre[father]==u?top[father]:u;
	dfs2(pre[u],u);
	for (int j=nex[u];j;j=nex[j]){
		int v=nu[j];
		if (v==father || v==pre[u]) continue;
		dfs2(v,u);
	}
}
int func(char ch){return ch=='.';}
void pushup(int t){
	int ls=t<<1, rs=(t<<1)+1;
	f[t][0][0]=max(f[ls][0][0]+f[rs][0][0],f[ls][0][1]+f[rs][1][0]);
	f[t][0][1]=max(f[ls][0][0]+f[rs][0][1],f[ls][0][1]+f[rs][1][1]);
	f[t][1][0]=max(f[ls][1][0]+f[rs][0][0],f[ls][1][1]+f[rs][1][0]);
	f[t][1][1]=max(f[ls][1][0]+f[rs][0][1],f[ls][1][1]+f[rs][1][1]);
	//fl[t][0]
	fl[t][0]=fl[ls][0];
	if (f[ls][0][0]>0) fl[t][0]=max(fl[t][0],f[ls][0][0]+fl[rs][0]);
	if (f[ls][0][1]>0) fl[t][0]=max(fl[t][0],f[ls][0][1]+fl[rs][1]);
	//fl[t][1]
	fl[t][1]=fl[ls][1];
	if (f[ls][1][0]>0) fl[t][1]=max(fl[t][1],f[ls][1][0]+fl[rs][0]);
	if (f[ls][1][1]>0) fl[t][1]=max(fl[t][1],f[ls][1][1]+fl[rs][1]);
	//fr[t][0]
	fr[t][0]=fr[rs][0];
	if (f[rs][0][0]>0) fr[t][0]=max(fr[t][0],f[rs][0][0]+fr[ls][0]);
	if (f[rs][1][0]>0) fr[t][0]=max(fr[t][0],f[rs][1][0]+fr[ls][1]);
	//fr[t][1]
	fr[t][1]=fr[rs][1];
	if (f[rs][0][1]>0) fr[t][1]=max(fr[t][1],f[rs][0][1]+fr[ls][0]);
	if (f[rs][1][1]>0) fr[t][1]=max(fr[t][1],f[rs][1][1]+fr[ls][1]);
}
void update(int t, int l, int r, int x, int u, int v){
	if (l==r){
		if (u)
			if (v)
				f[t][0][0]=f[t][0][1]=f[t][1][0]=f[t][1][1]=1,
				fl[t][0]=fl[t][1]=fr[t][0]=fr[t][1]=2;
			else
				f[t][0][0]=1,f[t][0][1]=f[t][1][0]=f[t][1][1]=-INF,
				fl[t][0]=fr[t][0]=1,fl[t][1]=fr[t][1]=0;
		else
			if (v)
				f[t][1][1]=1,f[t][0][0]=f[t][0][1]=f[t][1][0]=-INF,
				fl[t][0]=fr[t][0]=0,fl[t][1]=fr[t][1]=1;
			else
				f[t][0][0]=f[t][0][1]=f[t][1][0]=f[t][1][1]=-INF,
				fl[t][0]=fl[t][1]=fr[t][0]=fr[t][1]=0;
		return;
	}
	int mid=l+r>>1;
	if (x<=mid) update(t<<1,l,mid,x,u,v);
		   else update((t<<1)+1,mid+1,r,x,u,v);
	pushup(t);
}
void solve(int u, int v){
	int f1=top[u], f2=top[v];
	int p0=0, p1=0, q0=0, q1=0;
	while (f1!=f2)
		if (dep[f1]>f2){
			
			f1=top[u=fa[f1]];
		}
		else{
			f2=top[v=fa[f2]];
		}
	
} 
int main(){
	cnt=n=read();m=read();
	for (int i=1;i<n;i++){
		int u=read(), v=read();
		add(u,v);
		add(v,u);
	}
	dfs1(1,0);
	dfs2(1,0);
	for (int i=1;i<=n;i++){
		int u=a[i][0]=func(getchar()), v=a[i][1]=func(getchar());getchar();
		update(1,1,n,i,u,v);
	}
	for (int i=1;i<=m;i++){
		char ch=getchar();
		if (ch=='Q'){
			int u=read(), v=read();
			solve(u,v);
		}
		if (ch=='C'){
			int x=read(), u=a[x][0]=func(getchar()), v=a[x][1]=func(getchar());getchar();
			update(1,1,n,i,u,v);
		}
	}
	return 0;
}
