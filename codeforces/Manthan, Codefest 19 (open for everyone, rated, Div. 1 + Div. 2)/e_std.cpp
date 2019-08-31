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
#define N 6000000
typedef long long ll;
using namespace std;
int n, w;
int s[N];
ll f[N], g[N];
struct njh{
	int x, pos;
	int le, ri;
}l[N];
ll tag[N];
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
bool cmp(njh x, njh y){
	if (x.x>y.x) return 1;
	if (x.x<y.x) return 0;
	return x.pos>y.pos;
}
void pushdown(int t){
	if (g[t]){
		g[t<<1]=g[(t<<1)+1]=g[t];
		f[t<<1]=f[(t<<1)+1]=g[t];
		g[t]=0;
	}
}
void upd(int t, int l, int r, int le, int ri, int x){
	if (le<=l && r<=ri){
		g[t]=f[t]=x;
		return;
	}
	pushdown(t);
	int mid=l+r>>1;
	if (le<=mid) upd(t<<1, l, mid, le, ri, x);
	if (ri>mid) upd((t<<1)+1, mid+1, r, le, ri, x);
	f[t]=min(f[t<<1], f[(t<<1)+1]);
}
int queryL(int t, int l, int r, int le, int ri, int x){
	if (l==r) return l;
	int mid=l+r>>1;
	int p0=0;
	pushdown(t);
	if (le<=mid && f[t<<1]<x) p0=queryL(t<<1, l, mid, le, ri, x);
	if (p0) return p0;
	if (ri>mid && f[(t<<1)+1]<x) return queryL((t<<1)+1, mid+1, r, le, ri, x);
	return 0;
}
int queryR(int t, int l, int r, int le, int ri, int x){
	if (l==r) return l;
	int mid=l+r>>1;
	int p0=0;
	pushdown(t);
	if (ri>mid && f[(t<<1)+1]<x) p0=queryR((t<<1)+1, mid+1, r, le, ri, x);
	if (p0) return p0;
	if (le<=mid && f[t<<1]<x) return queryR(t<<1, l, mid, le, ri, x);
	return 0;
}
int main(){
	n=read();w=read();
	for (int i=1;i<=n;i++){
		s[i]=read();
		for (int j=1;j<=s[i];j++) l[j].x=read(), l[j].pos=j;
		sort(l+1, l+1+s[i], cmp);
		for (int j=1, flag=1;j<=s[i];j++){
			if (l[j].x<0 && flag){
				flag=0;
				if (w>s[i]){
					upd(1,1,w,s[i]+1,w,i);
					upd(1,1,w,1,w-s[i],i);
				}
			}
			int le=l[j].pos, ri=w-s[i]+l[j].pos;
			l[j].le=queryL(1,1,w,le,ri,i);
			if (l[j].le){
				l[j].ri=queryR(1,1,w,le,ri,i);
				upd(1,1,w,l[j].le,l[j].ri,i);
				tag[l[j].le]+=l[j].x;
				tag[l[j].ri+1]-=l[j].x;
			}
		}
	}
	ll ans=0;
	for (int i=1;i<=w;i++) printf("%I64d%s", ans+=tag[i], i==n?"\n":" ");
	return 0;
}
