#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 200000
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int n, m, l, r, a[N], f[N*5+5], g[N*5+5];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
void pushdown(int t){
	if (!g[t]) return;
	g[t<<1]=max(g[t<<1],g[t]);
	g[(t<<1)+1]=max(g[(t<<1)+1],g[t]);
	g[t]=0;
}
void upd(int t, int le, int ri){
	if (l<=le && ri<=r){
		g[t]=max(g[t],r+1);
		return;
	}
	pushdown(t);
	int mid=le+ri>>1;
	if (l<=mid) upd(t<<1,le,mid);
	if (r>mid) upd((t<<1)+1,mid+1,ri);
}
void upd2(int t, int le ,int ri, int x, int v){
	if (le==ri){
		f[t]=v;
		return;
	}
	int mid=le+ri>>1;
	if (x<=mid) upd2(t<<1,le,mid,x,v);
	else upd2((t<<1)+1,mid+1,ri,x,v);
	f[t]=min(f[t<<1],f[(t<<1)+1]);
}
int query(int t, int le, int ri, int x){
	if (le==ri) return g[t];
	pushdown(t);
	int mid=le+ri>>1;
	if (x<=mid) return query(t<<1,le,mid,x);
	return query((t<<1)+1,mid+1,ri,x);
}
int query2(int t, int le, int ri, int v){
	if (le==ri) return le;
	int mid=le+ri>>1;
	if (f[t<<1]<=v) return query2(t<<1,le,mid,v);
	return query2((t<<1)+1,mid+1,ri,v); 
}
int main(){
	for (int T=read();T;T--){
		n=read();
		m=read();
		for (int i=1;i<=n*5;i++) g[i]=0, f[i]=n+1;
		for (int i=1;i<=m;i++){
			l=read(), r=read();
			upd(1,1,n);
		}
		for (int i=1;i<=n;i++)
			upd2(1,1,n,i,0);
		for (int i=1;i<=n;i++){
			int v=query2(1,1,n,i);
			//cout<<i<<' '<<query(1,1,n,i)<<' '<<v<<endl;
			a[i]=v;
			upd2(1,1,n,v,query(1,1,n,i));
		}
		for (int i=1;i<=n;i++) printf("%d%s", a[i], i<n?" ":"\n");
	}
    return 0;
}

