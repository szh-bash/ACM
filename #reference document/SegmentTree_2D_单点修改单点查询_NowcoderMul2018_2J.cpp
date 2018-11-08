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
#define N 1000000
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int n, m, k, T, x1, yy, x2 ,y2, cnt, x;
//map <int, int> g;
int son[N*2][5], g[N*2];
char s[N*50+5];
int read(){
    int p=0;
    while (s[x]<'0' || s[x]>'9') x++;
    while (s[x]>='0' && s[x]<='9') p=p*10+s[x++]-'0';
    return p;
}
void pushdown(int t){
	if (!g[t]) return;
	for (int i=0;i<4;i++)
		if (son[t][i])
			if (!g[son[t][i]] || g[son[t][i]]==g[t]) g[son[t][i]]=g[t];
			else g[son[t][i]]=-1;
	g[t]=0;
}
void upd(int t, int l1, int r1, int l2, int r2){
	if (x1<=l1 && r1<=x2 && yy<=l2 && r2<=y2){
		if (!g[t] || g[t]==k) g[t]=k;
		else g[t]=-1;
		return;
	}
	if (g[t]<0) return;
	pushdown(t); 
	int midx=(l1+r1)>>1, midy=(l2+r2)>>1;
	if (x1<=midx && yy<=midy) upd(son[t][0],l1,midx,l2,midy);
	if (x1<=midx && y2>midy) upd(son[t][1],l1,midx,midy+1,r2);
	if (x2>midx && yy<=midy) upd(son[t][2],midx+1,r1,l2,midy);
	if (x2>midx && y2>midy) upd(son[t][3],midx+1,r1,midy+1,r2);
}
int query(int t, int l1, int r1, int l2, int r2){
	if (l1==r1 && l2==r2 || g[t]<0) return g[t];
	pushdown(t);
	int midx=(l1+r1)>>1, midy=(l2+r2)>>1;
	if (x1<=midx && yy<=midy) return query(son[t][0],l1,midx,l2,midy);
	if (x1<=midx && yy>midy) return query(son[t][1],l1,midx,midy+1,r2);
	if (x1>midx && yy<=midy) return query(son[t][2],midx+1,r1,l2,midy);
	return query(son[t][3],midx+1,r1,midy+1,r2);
}
void build(int &t, int l1, int r1, int l2, int r2){
	if (l1>r1 || l2>r2) return;
	t=++cnt;
	if (l1==r1 && l2==r2) return;
	int midx=l1+r1>>1, midy=l2+r2>>1;
	build(son[t][0], l1, midx, l2, midy);
	build(son[t][1], l1, midx, midy+1, r2);
	build(son[t][2], midx+1, r1, l2, midy);
	build(son[t][3], midx+1, r1, midy+1, r2);
}
int main(){
	fread(s,1,N*50,stdin);
	n=read();m=read();T=read();
	int p, q=n*m;
	build(p,1,n,1,m);
	x1=yy=x2=y2=1;
	for (int i=1;i<=q;++i){
		k=read(),
		upd(1,1,n,1,m);
		//cout<<x1<<' '<<yy<<' '<<query(1,1,n,1,m)<<endl;;
		if (++yy>m) x1++, yy=1;
		if (++y2>m) x2++, y2=1;
	}
	for (int i=1;i<=T;++i)
		x1=read(),
		yy=read(),
		x2=read(),
		y2=read(),
		k=read(),
		upd(1,1,n,1,m);
	int ans=0;
	x1=yy=1;
	for (int i=1;i<=q;++i){
		ans+=query(1,1,n,1,m)>=0;
		//cout<<x1<<' '<<yy<<' '<<query(1,1,n,1,m)<<endl;
		if (++yy>m) x1++, yy=1;
	}
	cout<<n*m-ans<<endl;
    return 0;
}
