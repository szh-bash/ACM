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
#define N 500005
#define Q 500005
struct node{
	int n, x, y;
}l[Q*2];
int n, cnt, q, a[N], f[N], last[N], g[N*10], ans[Q];
bool cmp(node a, node b){return a.x<b.x;}
void upd(int t, int l, int r, int x){
	if (l==r) {
		g[t]++;
		return;
	}
	int mid=l+r>>1;
	if (x<=mid) upd(t<<1, l, mid, x);
	else upd((t<<1)+1, mid+1, r, x);
	g[t]=g[t<<1]+g[(t<<1)+1];
}
int query(int t, int l, int r, int ri){
	if (r<=ri) return g[t];
	int mid=l+r>>1;
	int tmpl=query(t<<1, l, mid, ri), tmpr=0;
	if (ri>mid) tmpr=query((t<<1)+1, mid+1, r, ri);
	return tmpl+tmpr;
}
int main(){
	n=read(), q=read();
	for (int i=1;i<=n;i++) {
		a[i]=read();
		f[i]=last[a[i]];
		last[a[i]]=i;
	}
	for (int i=1;i<=q;i++){
		int le=read()-1, ri=read();
		l[++cnt].x=ri;
		l[cnt].y=le;
		l[cnt].n=i;
		ans[i]-=le;
	}
	sort(l+1,l+1+cnt,cmp);
	for (int i=1, j=1;i<=n && j<=q;i++){
		upd(1,1,n+1,f[i]+1);
		for (;j<=q && l[j].x<=i;j++)
			ans[l[j].n]+=query(1,1,n+1,l[j].y+1);
	}
	for (int i=1;i<=q;i++) printf("%d\n", ans[i]);
    return 0;
}
