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
#define N 300000
#define M 2000000
typedef long long ll;
using namespace std;
int n, ans[N];
ll a[N];
ll f[M], g[M], inf;
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
void build(int t, int l, int r){
	if (l==r){
		f[t]=a[l];
		return;
	}
	int mid=l+r>>1;
	build(t<<1, l, mid);
	build((t<<1)+1, mid+1, r);
	f[t]=min(f[t<<1], f[(t<<1)+1]);
}
void pushdown(int t){
	if (g[t]){
		g[t<<1]+=g[t];
		f[t<<1]-=g[t];
		g[(t<<1)+1]+=g[t];
		f[(t<<1)+1]-=g[t];
		g[t]=0;
	}
}
int query(int t, int l, int r){
	if (l==r) return l;
	int mid=l+r>>1;
	pushdown(t);
	if (!f[(t<<1)+1]) return query((t<<1)+1, mid+1, r);
	return query(t<<1, l, mid);
}
void upd(int t, int l, int r, int x, int y){
	if (x<=l){
		f[t]-=y;
		g[t]+=y;
		return; 
	}
	pushdown(t);
	int mid=l+r>>1;
	if (x<=mid) upd(t<<1, l, mid, x, y);
	upd((t<<1)+1, mid+1, r, x, y);
	f[t]=min(f[t<<1], f[(t<<1)+1]);
}
void updp(int t, int l, int r, int x){
	if (l==r){
		f[t]=inf;
		return;
	}
	pushdown(t);
	int mid=l+r>>1;
	if (x<=mid) updp(t<<1, l, mid, x);
	else updp((t<<1)+1, mid+1, r, x);
	f[t]=min(f[t<<1], f[(t<<1)+1]);
}
int main(){
	n=read();
	inf=1ll*n*n+1;
	for (int i=1;i<=n;i++) a[i]=readll();
	build(1,1,n);
	for (int i=1;i<=n;i++){
		int x=query(1,1,n);
		ans[x]=i;
		upd(1,1,n,x+1,i);
		updp(1,1,n,x);
	}
	for (int i=1;i<=n;i++) printf("%d%s", ans[i], i==n?"\n":" ");
	return 0;
}
