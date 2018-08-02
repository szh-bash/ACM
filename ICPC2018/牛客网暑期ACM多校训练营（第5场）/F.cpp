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
#define N 2000000
#define mo 998244353
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int n, w, cnt, s[N], g[N], flags[N], flagg[N];
struct qlz {
	int p, d, n, v, p0, p1;
}l[N];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
bool cmpd(qlz a, qlz b){ return a.d<b.d;}
bool cmpn(qlz a, qlz b){ return a.n<b.n;}
int add(int a, int b){
	int c=a+b;
	if (c>=mo) c-=mo;
	return c;
}
int sub(int a, int b){
	int c=a-b;
	if (c<0) c+=mo;
	return c;
}
int mul(int a, int b){
	ll c=(ll) a*b;
	return c%mo;
}
void pushdown(int t){
	if (flags[t]!=1){
		s[t<<1]=mul(s[t<<1],flags[t]);
		flags[t<<1]=mul(flags[t<<1],flags[t]);
		s[(t<<1)+1]=mul(s[(t<<1)+1],flags[t]);
		flags[(t<<1)+1]=mul(flags[(t<<1)+1],flags[t]);
		flags[t]=1;
	}
	if (flagg[t]!=1){
		g[t<<1]=mul(g[t<<1],flagg[t]);
		flagg[t<<1]=mul(flagg[t<<1],flagg[t]);
		g[(t<<1)+1]=mul(g[(t<<1)+1],flagg[t]);
		flagg[(t<<1)+1]=mul(flagg[(t<<1)+1],flagg[t]);
		flagg[t]=1;
	}
}
int querys(int t, int l, int r, int x){
	if (r<=x) return s[t];
	pushdown(t);
	int mid=l+r>>1;
	ll p=querys(t<<1,l,mid,x);
	if (x>mid) p=add(p,querys((t<<1)+1,mid+1,r,x));
	return p;
}
void updas(int t, int l, int r, int x, int v){
	if (l==r){
		s[t]=add(s[t],v);
		return;
	}
	pushdown(t);
	int mid=l+r>>1;
	if (x<=mid) updas(t<<1,l,mid,x,v);
	else updas((t<<1)+1,mid+1,r,x,v);
	s[t]=add(s[t<<1],s[(t<<1)+1]);
}
void updms(int t, int l, int r, int x, int v){
	if (r<=x){
		flags[t]=mul(flags[t],v);
		s[t]=mul(s[t],v);
		return;
	}
	pushdown(t);
	int mid=l+r>>1;
	updms(t<<1,l,mid,x,v);
	if (x>mid) updms((t<<1)+1,mid+1,r,x,v);
	s[t]=add(s[t<<1],s[(t<<1)+1]);
}
int queryg(int t, int l, int r, int x){
	if (r<=x) return g[t];
	pushdown(t);
	int mid=l+r>>1;
	ll p=queryg(t<<1,l,mid,x);
	if (x>mid) p=add(p,queryg((t<<1)+1,mid+1,r,x));
	return p;
}
void updag(int t, int l, int r, int x, int v){
	if (l==r){
		g[t]=add(g[t],v);
		return;
	}
	pushdown(t);
	int mid=l+r>>1;
	if (x<=mid) updag(t<<1,l,mid,x,v);
	else updag((t<<1)+1,mid+1,r,x,v);
	g[t]=add(g[t<<1],g[(t<<1)+1]);
}
void updmg(int t, int l, int r, int x, int v){
	if (r<=x){
		flagg[t]=mul(flagg[t],v);
		g[t]=mul(g[t],v);
		return;
	}
	pushdown(t);
	int mid=l+r>>1;
	updmg(t<<1,l,mid,x,v);
	if (x>mid) updmg((t<<1)+1,mid+1,r,x,v);
	g[t]=add(g[t<<1],g[(t<<1)+1]);
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
int main(){
	n=read();
	w=power(100,mo-2);
	for (int i=1;i<N;i++)
		flags[i]=flagg[i]=1;
	for (int i=1;i<=n;i++) 
		l[i].p=read(),
		l[i].p0=mul(l[i].p,w),
		l[i].p1=mul(100-l[i].p,w),
		l[i].d=read(),
		l[i].n=i;
	sort(l+1,l+1+n,cmpd);
	for (int i=1;i<=n;i++)
		if (l[i].d!=l[i-1].d) l[i].v=++cnt;
		else l[i].v=cnt;
	sort(l+1,l+1+n,cmpn);
	updas(1,0,cnt,0,1);
	for (int i=1;i<=n;i++){
		//cout<<g[1]<<endl;
		ll s=querys(1,0,cnt,l[i].v-1), g=queryg(1,0,cnt,l[i].v-1);
		//cout<<i<<' '<<s<<' '<<g<<endl;
		updms(1,0,cnt,l[i].v-1,l[i].p1);
		updas(1,0,cnt,l[i].v,mul(s,l[i].p0));
		updmg(1,0,cnt,l[i].v-1,l[i].p1);
		updag(1,0,cnt,l[i].v,add(mul(g,l[i].p0),mul(s,l[i].p0)));
	}
	cout<<g[1]<<endl;
    return 0;
}
