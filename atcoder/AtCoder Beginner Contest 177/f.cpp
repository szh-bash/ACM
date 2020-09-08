#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <tr1/unordered_map>
#define mo 1000000007
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
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
#define M N*8
int n, m, a[N], b[N];
int f[M], g[M], flag[M], sum[M], p[M];
void pushup(int t){
	f[t]=min(f[t<<1], f[(t<<1)+1]);
	if (p[t<<1]+g[t<<1]<p[(t<<1)+1]+g[(t<<1)+1])
		p[t]=p[t<<1],
		g[t]=g[t<<1];
	else
		p[t]=p[(t<<1)+1],
		g[t]=g[(t<<1)+1];
}
void build(int t, int l, int r){
	if (l==r){
		f[t]=p[t]=-l;
		g[t]=l;
		return;
	}
	int mid=l+r>>1;
	build(t<<1,l,mid);
	build((t<<1)+1,mid+1,r);
	pushup(t);
}
void pushdown(int t, int l, int r){
	if (flag[t]){
		int mid=l+r>>1;
		f[t<<1]=f[(t<<1)+1]=f[t];
		p[t<<1]=p[(t<<1)+1]=f[t];
		g[t<<1]=l;
		g[(t<<1)+1]=mid+1;
		sum[t<<1]=sum[(t<<1)+1]=0;
		flag[t<<1]=flag[(t<<1)+1]=1;
		flag[t]=sum[t]=0;
	}
	if (sum[t]){
		f[t<<1]+=sum[t];
		p[t<<1]+=sum[t];
		sum[t<<1]+=sum[t];
		f[(t<<1)+1]+=sum[t];
		p[(t<<1)+1]+=sum[t];
		sum[(t<<1)+1]+=sum[t];
		sum[t]=0;
	}
}
void add(int t, int l, int r, int le, int ri){
	if (le<=l && r<=ri){
		f[t]++;
		p[t]++;
		sum[t]++;
		return;
	}
	pushdown(t, l, r);
	int mid=(l+r)>>1;
	if (le<=mid) add(t<<1, l, mid, le, ri);
	if (ri>mid) add((t<<1)+1, mid+1, r, le, ri);
	pushup(t);
}
void upd(int t, int l, int r, int le, int ri, int x){
	if (le<=l && r<=ri){
		flag[t]=1;
		f[t]=p[t]=x;
		g[t]=l;
		return;
	}
	pushdown(t, l, r);
	int mid=(l+r)>>1;
	if (le<=mid) upd(t<<1, l, mid, le, ri, x);
	if (ri>mid) upd((t<<1)+1, mid+1, r, le, ri, x);
	pushup(t);
}
int query(int t, int l, int r, int x){
	if (r<=x) return f[t];
	pushdown(t,l,r);
	int mid=l+r>>1;
	int mi=9999999;
	if (x>mid) mi=min(query((t<<1)+1, mid+1, r, x), mi);
	mi=min(query(t<<1,l,mid,x), mi);
	return mi;
}
int main(){
	n=read(), m=read();
	for (int i=1;i<=n;i++) a[i]=read(), b[i]=read();
	build(1,1,m);
	for (int i=1;i<=n;i++){
		int mi=a[i]>1?query(1,1,m,a[i]-1):999999;
		upd(1,1,m,a[i],b[i],mi+1);
		if (a[i]>1) add(1,1,m,1,a[i]-1);
		if (b[i]<m) add(1,1,m,b[i]+1,m);
		if (f[1]>=999999) puts("-1");
		else printf("%d\n", p[1]+g[1]);
	}
    return 0;
}
