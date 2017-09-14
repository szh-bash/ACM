#include <map>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 80010
#define M 80010*160 
#define S 1000000
using namespace std;
int n, m, T, x, cnt, DFN, LSH, ct_in, ct_out, cnt_tree;
int f[M], ls[M], rs[M];
int fa[N][21], dep[N], trans[N*2], lsh[N*2], a[N], nex[N*3], nu[N*3], bit[N], b1[N*2], b2[N*2], dfn[N][2];
map<int,int> mp;
char s[S+100];
struct qlz_ques{
	int k, u, v;
}l[N];
int read(){
	int p=0;
	while (s[x]<'0' || s[x]>'9') x++;
	while (s[x]>='0' && s[x]<='9') p=p*10+s[x++]-'0';
	return p;
}
void add_edge(int u, int v){
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;
}
void dfs(int u, int father){
	fa[u][0]=father;
	for (int i=1;fa[fa[u][i-1]][i-1];i++)
		fa[u][i]=fa[fa[u][i-1]][i-1];
	dfn[u][0]=++DFN;
	//cout<<DFN<<' '<<u<<endl;
	for (int j=nex[u];j;j=nex[j]){
		int v=nu[j];
		if (v==father) continue;
		dep[v]=dep[u]+1;
		dfs(v,u);
	}
	dfn[u][1]=DFN+1;
}
void add_b1(int u, int &ct1){
	for (int i=dfn[u][0];i;i-=i&(-i)) b1[++ct1]=bit[i];
}
void add_b2(int u, int &ct2){
	for (int i=dfn[u][0];i;i-=i&(-i)) b2[++ct2]=bit[i];
}
int LCA(int u, int v){
	if (dep[u]<dep[v]) swap(u,v);
	//cout<<u<<' '<<v<<endl;
	for (int i=20;i>=0;i--)
		if (dep[fa[u][i]]>=dep[v]) u=fa[u][i];
	if (u==v) return u;
	for (int i=20;i>=0;i--)
		if (fa[u][i]!=fa[v][i]) u=fa[u][i], v=fa[v][i];
	return fa[u][0];
}
void solve(int u, int v, int k){
	int ct1=0, ct2=0, l=0, r=T, lca=LCA(u,v);
	add_b1(u,ct1);
	add_b1(v,ct1);
	add_b2(lca,ct2);
	add_b2(fa[lca][0],ct2);
	//cout<<u<<' '<<v<<' '<<k<<' '<<lca<<endl;
	//for (int i=1;i<=ct1;i++) cout<<b1[i]<<' ';cout<<endl;
	//for (int i=1;i<=ct2;i++) cout<<b2[i]<<' ';cout<<endl;
	while (l<r){
		int mid=l+r>>1, p=0;
		for (int i=1;i<=ct1;i++) p+=f[rs[b1[i]]];
		for (int i=1;i<=ct2;i++) p-=f[rs[b2[i]]];
		//cout<<l<<' '<<r<<' '<<mid<<' '<<p<<' '<<k<<endl;
		if (p<k){
			for (int i=1;i<=ct1;i++) b1[i]=ls[b1[i]];
			for (int i=1;i<=ct2;i++) b2[i]=ls[b2[i]];
			k-=p;
			r=mid;
		}
		else{
			for (int i=1;i<=ct1;i++) b1[i]=rs[b1[i]];
			for (int i=1;i<=ct2;i++) b2[i]=rs[b2[i]];
			l=mid+1;
		}
	}
	if (l) printf("%d\n", trans[l]);
	else printf("invalid request!\n");
}
void update(int x, int y, int z){
	int ct=0, l=0, r=T;
	for (int i=x;i<=DFN;i+=i&(-i)){
		if (!bit[i]) bit[i]=++cnt_tree;
		f[b1[++ct]=bit[i]]+=z;
	}
	while (l<r){
		int mid=l+r>>1;
		if (y<=mid){
			r=mid;
			for (int i=1;i<=ct;i++){
				if (!ls[b1[i]]) ls[b1[i]]=++cnt_tree;
				f[b1[i]=ls[b1[i]]]+=z;
			}
		}
		else{
			l=mid+1;
			for (int i=1;i<=ct;i++){
				if (!rs[b1[i]]) rs[b1[i]]=++cnt_tree;
				f[b1[i]=rs[b1[i]]]+=z;
			}
		}
	}
}
int main(){
	freopen("data_0.in","r",stdin);
	freopen("p1146_主席树非建树优化.out","w",stdout);
//read
	fread(s,1,S,stdin);
	cnt=n=read();m=read();
	for (int i=1;i<=n;i++)
		lsh[++LSH]=a[i]=read();
	for (int i=1;i<n;i++){
		int u=read(), v=read();
		add_edge(u,v);
		add_edge(v,u);
	}
	for (int i=1;i<=m;i++)
		l[i].k=read(),
		l[i].u=read(),
		l[i].v=read(),
		(!l[i].k?lsh[++LSH]=l[i].v:0);
//lsh
	sort(lsh+1,lsh+1+LSH);
	trans[mp[0]=++T]=0;
	for (int i=1;i<=LSH;i++)
		if (lsh[i]!=lsh[i-1]) trans[mp[lsh[i]]=++T]=lsh[i];
	for (int i=1;i<=n;i++) a[i]=mp[a[i]];
//build		
	dfs(dep[1]=1,0);
	for (int i=1;i<=n;i++)
		update(dfn[i][0],a[i],1),
		update(dfn[i][1],a[i],-1);
//work
	for (int i=1;i<=m;i++)
		if (l[i].k)
			solve(l[i].u,l[i].v,l[i].k);
		else{
			int u=l[i].u, v=mp[l[i].v];
			update(dfn[u][0],a[u],-1);
			update(dfn[u][1],a[u],1);
			update(dfn[u][0],a[u]=v,1);
			update(dfn[u][1],a[u],-1);
		}
	return 0;
}
