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
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
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
#define N 8005
int n, ct, x[N], y[N], g[N];
ll ans=1e18, sum;
struct node{
	int x, y, g, xx;
	long double thi, cs;
}l[N];
inline ll xj(int i, int j){
	return 1ll*l[i].x*l[j].y-1ll*l[i].y*l[j].x;
}
inline ll cross_dot(int x1, int y1, int x2, int y2){
	return 1ll*x1*y2-1ll*x2*y1;
}
inline bool cmp(node &a, node &b){
//  method1 (bad eps)
	return a.thi<b.thi;
 
//  method2 (no eps)
	if (a.xx<b.xx) return 1;
	if (a.xx>b.xx) return 0;
	return cross_dot(a.x, a.y, b.x, b.y)>0;
	
// method3 (idk, same bad eps)
	if (a.xx<b.xx) return 1;
	if (a.xx>b.xx) return 0;
	if (a.xx<=2) return a.cs>b.cs;
	return a.cs<b.cs;
}
int get_xx(int x, int y){
	if (y>=0 && x>0) return 1;
	if (x<=0 && y>0) return 2;
	if (y<=0 && x<0) return 3;
	if (x>=0 && y<0) return 4;
}
inline ll sqr(int a) {return 1ll*a*a;}
void solve(int u){
	ct=0;
	for (int i=1;i<=n;i++)
		if (i!=u){
			l[++ct].g=g[i];
			l[ct].x=x[i]-x[u];
			l[ct].y=y[i]-y[u];
			l[ct].thi=atan2l(l[ct].y, l[ct].x);
			l[ct].cs=(long double) l[ct].x/sqrt(sqr(l[ct].x)+sqr(l[ct].y));
			l[ct].xx=get_xx(l[ct].x, l[ct].y);
		}
	sort(l+1,l+1+ct,cmp);
	for (int i=ct+1;i<=ct*2;i++) l[i]=l[i-ct];
	ll p1=g[u];
	for (int i=1, j=1;i<=ct;i++){
		while (j<ct+i && xj(i,j)>=0) p1+=l[j++].g;
		ans=min(ans, abs(p1-(sum+g[u]+l[i].g-p1)));
		p1-=l[i].g;
	}
}
int main(){
	n=read();
	for (int i=1;i<=n;i++){
		x[i]=read(), y[i]=read(), sum+=(g[i]=read());
		for (int j=1;j<i;j++)
			if (x[j]==x[i] && y[j]==y[i]) {g[j]+=g[i];i--;n--;break;}
	}
	for (int i=1;i<=n;i++) solve(i);
	cout<<ans<<endl;
    return 0;
}
