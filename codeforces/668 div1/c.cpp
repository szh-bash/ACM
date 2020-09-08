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
#define N 300005
#define M N*4
int n, q, l[N], c[N];
int f[M], sum[M], g[M];
void pushup(int t){
	int ls=t<<1, rs=(t<<1)+1;
	if (f[rs]<=f[ls]) g[t]=g[rs];else g[t]=g[ls];
	f[t]=min(f[rs], f[ls]);
}
void pushdown(int t){
	if (sum[t]){
		int ls=t<<1, rs=(t<<1)+1;
		f[ls]-=sum[t];
		f[rs]-=sum[t];
		sum[ls]+=sum[t];
		sum[rs]+=sum[t];
		sum[t]=0;
	}
}
void upd(int t, int l, int r, int x, int y){
	if (l==r){
		f[t]=y;
		g[t]=l;
		return;
	}
	pushdown(t);
	int mid=l+r>>1;
	if (x<=mid) upd(t<<1, l, mid, x, y);
	else upd((t<<1)+1, mid+1, r, x, y);
	pushup(t);
}
void upd2(int t, int l, int r, int x){
	if (x<=l){
		f[t]--;
		sum[t]++;
		return;
	}
	pushdown(t);
	int mid=l+r>>1;
	if (x<=mid) upd2(t<<1, l, mid, x);
	upd2((t<<1)+1, mid+1, r, x);
	pushup(t);
}
#define Q 300005
struct node{
	int l, r, n;
}qs[Q];
int ans[Q];
bool cmp(node a, node b){
	return a.l>b.l;
}
void solve(){
	n=read();q=read();
	for (int i=1;i<=n;i++){
		int x=read();
		if (x>i) upd(1,1,n,i,999999);
		else upd(1,1,n,i,i-x);
	}
	int ct=0;
	while (!f[1]){
		int x=g[1];
		l[++ct]=g[1];
		upd(1,1,n,x,999999);
		upd2(1,1,n,x);
	}
	for (int i=1;i<=q;i++) qs[i].l=read(), qs[i].r=read(), qs[i].n=i;
	sort(qs+1,qs+1+q,cmp);
	for (int i=1, j=1;i<=q;i++){
		while (l[j]>qs[i].l)
			for (int k=l[j++];k<=n;k+=k&(-k)) c[k]++;
		for (int k=n-qs[i].r;k;k-=k&(-k)) ans[qs[i].n]+=c[k];
	}
	for (int i=1;i<=q;i++) printf("%d\n", ans[i]);
}
int main(){
	solve();
	return 0;
}
