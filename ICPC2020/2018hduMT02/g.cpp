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
ll readll(){
    ll p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
#define N 100050
#define M N*4
int n, q, b[N], c[N], f[M], g[M];
void updc(int x){
	for (;x<=n;x+=x&(-x)) c[x]++;
}
int sum(int x){
	int res=0;
	for (;x;x-=x&(-x)) res+=c[x];
	return res;
}
void build(int t, int l, int r){
	if (l==r){
		f[t]=-b[l];
		g[t]=0;
		return;
	}
	int mid=l+r>>1;
	build(t<<1, l, mid);
	build((t<<1)+1, mid+1, r);
	f[t]=max(f[t<<1], f[(t<<1)+1]);
	g[t]=0;
}
void pushdown(int t){
	if (g[t])
		f[t<<1]+=g[t],
		g[t<<1]+=g[t], 
		f[(t<<1)+1]+=g[t],
		g[(t<<1)+1]+=g[t],
		g[t]=0;
}
void upd(int t, int l, int r, int x){
	if (l==r){
		f[t]=-b[l];
		return;
	}
	pushdown(t);
	int mid=l+r>>1;
	if (x<=mid) upd(t<<1, l, mid, x);
	else upd((t<<1)+1, mid+1, r, x);
	f[t]=max(f[t<<1], f[(t<<1)+1]);
}
int query(int t, int l, int r){
	if (f[t]) return 0;
	if (l==r) return l;
//	cout<<t<<' '<<l<<' '<<r<<' '<<f[t]<<endl;
	pushdown(t);
	int mid=l+r>>1;
	if (!f[t<<1]) return query(t<<1, l, mid);
	return query((t<<1)+1, mid+1, r);
}
void add(int t, int l, int r, int le, int ri){
	if (le<=l && r<=ri){
		g[t]++;
		f[t]++;
		return;
	}
	pushdown(t);
	int mid=l+r>>1;
	if (le<=mid) add(t<<1, l, mid, le, ri);
	if (ri>mid) add((t<<1)+1, mid+1, r, le, ri);
	f[t]=max(f[t<<1], f[(t<<1)+1]);
}
void solve(){
	for (int i=1;i<=n;i++) b[i]=read(), c[i]=0;
	int cnt=0, ct=0;
	build(1,1,n);
	for (int i=1;i<=q;i++){
		int x, y;
		char op[10];
		scanf("%s%d%d", op, &x, &y);
		if (op[0]=='a'){
			int res=0;
			add(1,1,n,x,y);
			while (res=query(1,1,n))
				updc(res),
				upd(1,1,n,res);
		}
		else printf("%d\n", sum(y)-sum(x-1));
	}
}
int main(){
	while (~scanf("%d%d", &n, &q)) solve();
    return 0;
}
