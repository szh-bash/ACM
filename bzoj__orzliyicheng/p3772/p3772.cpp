#include<set>
#include<map>
#include<ctime>
#include<queue>
#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define inf (9000000000000000000LL)
#define mp make_pair
#define pli pair<ll,int>
#define pii pair<int,int>
#define ll long long 
#define N 100005
#define M 300005
#define NLGN (180000*18)
using namespace std;
int read(){
	int x=0,p=1;char ch=getchar();
	while(ch<'0' || ch>'9') ch=='-'?p=-1:0, ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0', ch=getchar();
	return x*p;
}
ll gcd(ll a, ll b){ return !b?a:gcd(b,a%b);}
int n, cnt, ct, m, nex[M], nu[M];
int dfn_in[N], dfn_out[N], fa[N], fa_tree[N];
int root[N], f[NLGN], rs[NLGN], ls[NLGN], tag[NLGN];
ll ans;
void link(int u, int v){
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;
}
void dfs_sort(int u, int fat){
	dfn_in[u]=++cnt;
	for (int j=nex[u];j;j=nex[j]){
		int v=nu[j];
		if (v==fat) continue;
		dfs_sort(v,u);
	}
	dfn_out[u]=++cnt;
}
vector<int> go[N];
void newnd(int &x, int y, int tg){
	x=++ct;
	f[x]=f[y];
	tag[ct]=tg;
}
void insert(int u, int v, int x, int y){
	int up=root[u], vp=root[v];
	int le=1, ri=cnt;
	while (le<ri){
		f[vp]+=y;
		int mid=le+ri>>1;
		if (x<=mid){
			if (!ls[vp] || tag[ls[vp]]!=v) newnd(ls[vp], ls[up], v);
			if (!rs[vp]) rs[vp]=rs[up];
			ri=mid;
			up=ls[up];
			vp=ls[vp];
		}
		else{
			if (!rs[vp] || tag[rs[vp]]!=v) newnd(rs[vp], rs[up], v);
			if (!ls[vp]) ls[vp]=ls[up];
			le=mid+1;
			up=rs[up];
			vp=rs[vp];
		}
	}
	f[vp]+=y;
}
int father(int x){ return fa[x]==x?x:fa[x]=father(fa[x]);}
int calc(int u, int x){
	if (!x || !u) return 0;
	int res=0;
	int le=1, ri=cnt;
	while (le<ri){
		int mid=le+ri>>1;
//		cout<<le<<' '<<ri<<' '<<x<<endl;
		if (x>mid) res+=f[ls[u]], le=mid+1, u=rs[u];
		else ri=mid, u=ls[u];
	}
	return res+f[u];
}
int sum(int u, int v, int w, int le){
	int up=root[u], vp=root[v];
	int ri=dfn_in[v];
	if (u==v) return 0;
	int res=(calc(vp,ri)-calc(vp,le-1))-(calc(up,ri)-calc(up,le-1));
//	cout<<u<<' '<<v<<' '<<le<<' '<<ri<<' '<<w<<' '<<res<<endl;
	if (!w) return res;
	ri=dfn_in[w];
	res+=(calc(vp,ri)-calc(vp,le))-(calc(up,ri)-calc(up,le));
//	cout<<ri<<' '<<res<<' '<<calc(vp,ri)<<' '<<calc(vp,le)<<endl;
	return res;
}
void solve(int u, int fat){
	fa[u]=u;
	fa_tree[u]=fat; 
	int num=go[u].size();
	if (num) 
		f[root[u]=++ct]=f[root[fat]],
		tag[root[u]]=u;
	else root[u]=root[fat];
//	cout<<u<<' '<<fat<<' '<<num<<' '<<ct<<endl;
	for (int j=0;j<num;j++){ //insert
		int v=go[u][j];
		insert(fat,u,dfn_in[v],1);
		insert(fat,u,dfn_out[v],-1);
//		cout<<"Insert: "<<u<<' '<<v<<' '<<ct<<' '<<dfn_in[v]<<' '<<dfn_out[v]<<endl;
	}
	for (int j=0;j<num;j++){ //calc
		int v=go[u][j];
		int lca=father(v);
		int le=dfn_in[lca];
		if (lca==v || lca==u) ans+=sum(fa_tree[lca],lca^u^v,0,le)-1;
		else ans+=sum(fa_tree[lca],u,v,le)+sum(lca,v,0,le)-1;
//		cout<<"Calc: "<<u<<' '<<v<<' '<<lca<<' '<<ans<<endl;
	}
	for (int j=nex[u];j;j=nex[j]){ //deeper
		int v=nu[j];
		if (v==fat) continue;
		solve(v,u);
		fa[v]=u;
	}
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("data.in","r",stdin);
	freopen("my.out","w",stdout);
#endif
	cnt=n=read();m=read();
	for (int i=1;i<n;i++){
		int u=read(), v=read();
		link(u,v);
		link(v,u);
	}
	dfs_sort(1,cnt=0);
	for (int i=1;i<=m;i++){
		int st=read(), ed=read();
		if (dfn_in[st]>dfn_in[ed]) swap(st,ed);
		go[ed].push_back(st);
	}
	solve(1,0);
	ll counts=1ll*m*(m-1)/2;
	ll gys=gcd(counts,ans);
	cout<<ans/gys<<'/'<<counts/gys<<endl;
	return 0;
}

/*
5 4
1 2
2 3
3 4
2 5
3 5
2 5
1 4
1 1
*/
