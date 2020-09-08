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
#define N 1000005
struct node{
	int n;
	ll x, y;
}p[N];
int n, g[N], ans=1;
bool cmp(node a, node b){
	return a.y*b.x<a.x*b.y; 
}
ll xj(ll x1, ll y1, ll x2, ll y2){return x1*y2-x2*y1;}
inline int get_dr(int u, int v){
	ll x=xj(p[u].x, p[u].y, p[v].x-p[u].x, p[v].y-p[u].y);
	return x?(x/abs(x)):0;
}
int flag[N];
int main(){
	n=read();
	for (int i=1;i<=n;i++){
		p[i].x=read(),
		p[i].y=read(),
		p[i].n=i;
	}
	sort(p+1,p+1+n,cmp);
	for (int i=1;i<=n;i++) g[p[i].n]=i;
	int bl=1, tmp=0;
	for (int i=1;i<=n;i++){
		if (flag[i]) continue;
		flag[i]=1;
		int u=p[i].n, l=(u-1)?(u-1):n, r=(u<n)?(u+1):1;
		int le=g[l], ri=g[r];
		int drL=get_dr(i, le);
		int drR=get_dr(i, ri);
		while (!drL){
			flag[le]=1;
			l=(l-1)?(l-1):n;
			drL=get_dr(le, g[l]);
			le=g[l];
		}
		while (!drR){
			flag[ri]=1;
			r=(r<n)?(r+1):1;
			drR=get_dr(ri, g[r]);
			ri=g[r];
		}
		if (cmp(p[i-1], p[i])) bl+=tmp, tmp=0;
		ans=max(ans, bl);
		if (drL>0 && drR>0){
			if (xj(p[ri].x-p[i].x, p[ri].y-p[i].y, p[le].x-p[i].x, p[le].y-p[i].y)>0) tmp++;
			else bl++;
		}
		if (drL<0 && drR<0){
			if (xj(p[ri].x-p[i].x, p[ri].y-p[i].y, p[le].x-p[i].x, p[le].y-p[i].y)<0) tmp--;
			else bl--;
		}
		ans=max(ans, bl);
	}
	ans=max(ans, bl+tmp);
	cout<<ans<<endl;
    return 0;
}
