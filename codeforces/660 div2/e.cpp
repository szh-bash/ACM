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
typedef long long ll;
typedef long double ld;
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
#define N 10000
#define M 5000000
struct node{
	ll xl, xr, y;
}l[N];
ll fzl[M], fml[M], fzr[M], fmr[M];
int num[M];
int n;
inline ll sqr(ll x){return x*x;}
inline bool cmpl(int a, int b){
	//get min cos
	if (fzl[a]<=0 && fzl[b]<=0) return sqr(fzl[a])*fml[b]>sqr(fzl[b])*fml[a];
	if (fzl[a]>=0 && fzl[b]>=0) return sqr(fzl[a])*fml[b]<sqr(fzl[b])*fml[a];
	return fzl[a]<0;
}
inline bool cmpr(int a, int b){
	// get max cos
	if (fzr[a]<=0 && fzr[b]<=0) return sqr(fzr[a])*fmr[b]<sqr(fzr[b])*fmr[a];
	if (fzr[a]>=0 && fzr[b]>=0) return sqr(fzr[a])*fmr[b]>sqr(fzr[b])*fmr[a];
	return fzr[a]>0;
}
ld ans;
void get_ans(ld fz, ld fm){
	ld y=sqrt(fm-sqr(fz)), x=-fz;
	ld L, R;
	for (int i=1;i<=n;i++){
		ld x0=l[i].xl+l[i].y*x/y;
		ld x1=l[i].xr+l[i].y*x/y;
		if (i==1) L=x0, R=x1;
		else L=min(L,x0), R=max(R,x1);
	}
	ans=min(ans,R-L);
}
void solve(){
	n=read();
	for (int i=1;i<=n;i++)
		l[i].xl=read(), 
		l[i].xr=read(), 
		l[i].y=read();
	int ct=0;
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++){
			if (l[i].y==l[j].y) continue;
			int u=i, v=j;
			if (l[u].y<l[v].y) swap(u,v);
			++ct;
			fzl[ct]=l[u].xr-l[v].xl;
			fml[ct]=sqr(l[u].y-l[v].y)+sqr(fzl[ct]);
			
			fzr[ct]=l[u].xl-l[v].xr;
			fmr[ct]=sqr(l[u].y-l[v].y)+sqr(fzr[ct]);
			
			num[ct]=ct;
		}
	if (!ct){
		ll le=0, ri=0;
		for (int i=1;i<=n;i++)
			if (i==1) le=l[i].xl, ri=l[i].xr;
			else le=min(le, l[i].xl), ri=max(ri, l[i].xr);
		printf("%.9Lf\n", ld(ri-le));
		return;
	}
	ans=1ll*999999999*999999999;
	sort(num+1,num+1+ct,cmpl);
	get_ans(fzl[1], fml[1]);
	sort(num+1,num+1+ct,cmpr);
	get_ans(fzr[1], fmr[1]);
	printf("%.9Lf\n", ans);
}
int main(){
	solve();
	return 0;
}
