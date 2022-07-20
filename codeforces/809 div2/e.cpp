#include <map>
#include <set> 
#include <ctime>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define mo 1000000007
typedef long long ll;
using namespace std;
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=='-'?q=-1:0, ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
ll readll(){
	ll p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=='-'?q=-1:0, ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
int power(ll a, int b){
	ll c=1;
	while (b){
		if (b&1) c=c*a%mo;
		a=a*a%mo;
		b>>=1;
	}
	return c;
}
#define N 200005
#define M 200005
#define D 20
int n, m, q, f[N];
int fa[N];
int g[D][N];
struct edge{
	int u, v;
}l[M];
struct node{
	int nxt, tail, len;
}link[N];
int father(int x){ return fa[x]==x?x:fa[x]=father(fa[x]);}
int ans[M];
int pw[D];
int lg[N];
int calc(int le, int ri){
	if (le==ri) return 0;
	int d=lg[ri-le];
	return max(g[d][le], g[d][ri-pw[d]]);
}
void solve(){
	n=read(), m=read(), q=read();
	for (int i=1;i<=m;i++){
		l[i].u = read();
		l[i].v = read();
	}
	for (int i=1;i<=n;i++)
		fa[i]=link[i].tail=i,
		link[i].nxt=0,
		link[i].len=1,
		f[i]=m+1;
	f[n]=0;
	for (int i=1;i<=m;i++){
		int u=l[i].u, v=l[i].v;
		if (father(u)==father(v)) continue;
		if (link[fa[u]].len>link[fa[v]].len) swap(u,v);
		int fu=fa[u], fv=fa[v];
		fa[fv]=fu;
		for (int j=fu;j;j=link[j].nxt){
			if (j<n && father(j+1)==fu)
				f[j]=min(f[j], i);
			if (j>1 && father(j-1)==fu)
				f[j-1]=min(f[j-1], i);
		}
		link[link[fu].tail].nxt=fv;
		link[fu].len+=link[fv].len;
		link[fu].tail=link[fv].tail;
	}
	for (int i=n;i;i--){
		g[0][i]=f[i];
		for (int j=1;j<D;j++)
			if (i+pw[j-1]>n)
				g[j][i]=g[j-1][i];
			else
				g[j][i]=max(g[j-1][i],g[j-1][i+pw[j-1]]);
	}
	for (int i=1;i<=q;i++){
		int le=read(), ri=read();
		ans[i]=calc(le,ri);
	}
	for (int i=1;i<=q;i++){
		printf("%d%s", ans[i], i==q?"\n":" ");
	}
}
int main(){
	pw[0]=1;
	for (int i=1;i<D;i++) pw[i]=pw[i-1]<<1;
	for (int i=2;i<N;i++) lg[i]=lg[i>>1]+1;
	for (int _=read();_;_--) solve();
	return 0;
}
