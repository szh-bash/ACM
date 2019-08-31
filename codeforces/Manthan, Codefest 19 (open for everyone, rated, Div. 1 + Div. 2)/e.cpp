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
ll f[N], g[N], ad[N];
struct njh{
	int x, pos;
}l[N];
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
	if (x.x<y.x) return 1;
	if (x.x>y.x) return 0;
	return x.pos<y.pos;
}
void pushdown_id(int t, int id){
	if (g[t]<id){
		f[t]+=ad[t];
		g[t]=id;
		ad[t]=0;
	}
	else{
		if (g[t<<1]<g[t]){
			f[t<<1]+=ad[t<<1];
			ad[t<<1]=ad[t];
			g[t<<1]=g[t];
		} else ad[t<<1]=max(ad[t<<1], ad[t]);
		if (g[(t<<1)+1]<g[t]){
			f[(t<<1)+1]+=ad[(t<<1)+1];
			ad[(t<<1)+1]=ad[t];
			g[(t<<1)+1]=g[t];
		} else ad[(t<<1)+1]=max(ad[(t<<1)+1], ad[t]);
		ad[t]=0;
	}
}
void upd(int t, int l, int r, int le, int ri, int id, int y){
	if (le<=l && r<=ri){
		if (g[t]<id) g[t]=id, f[t]+=ad[t];
		ad[t]=y;
		return;
	}
	pushdown_id(t, id);
	int mid=l+r>>1;
	if (le<=mid) upd(t<<1, l, mid, le, ri, id, y);
	if (ri>mid) upd((t<<1)+1, mid+1, r, le, ri, id, y);
}
ll query(int t, int l, int r, int id, int x){
	if (l==r) return f[t]+ad[t];
	int mid=l+r>>1;
	pushdown_id(t, id);
	if (x<=mid) return query(t<<1, l, mid, id, x);
	return query((t<<1)+1, mid+1, r, id, x);
}
int main(){
	n=read();w=read();
	for (int i=1;i<=n;i++){
		g[i]=read();
		for (int j=1;j<=g[i];j++) l[j].x=read(), l[j].pos=j;
		sort(l+1, l+1+g[i], cmp);
		for (int j=1;j<=g[i];j++){
			int le=l[j].pos, ri=w-g[i]+l[j].pos;
			upd(1,1,w,le,ri,i,l[j].x);
		}
	}
	for (int i=1;i<=n;i++) printf("%I64d%s", query(1,1,w,n,i), i==n?"\n":" ");
	return 0;
}
