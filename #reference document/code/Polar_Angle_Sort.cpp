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
#define N 10000
#define Q 10000
struct point{
	ll x, y;
	int n, q;
	int xx;
}l[N+Q], p[N+Q];
ll cross(point a, point b){
	return a.x*b.y-a.y*b.x;
}
bool cmp(point a, point b){
	if (a.xx<b.xx) return 1;
	if (a.xx>b.xx) return 0;
	return cross(a,b)>0; 
}
int getxx(int x, int y){
	if (x>0 && y>=0) return 1;
	if (x<=0 && y>0) return 2;
	if (x<0 && y<=0) return 3;
	if (x>=0 && y<0) return 4;
}
ll dot (point a, point b){
	return a.x*b.x+a.y*b.y;
}
int n, q;
int ans[N];
int le[2], ri[2];
void solve(int o){
	int x=p[o].x, y=p[o].y;
	int cnt=0;
	for (int i=1;i<=n;i++)
		if (i!=o)
			l[++cnt].n=p[i].n,
			l[cnt].x=p[i].x-x,
			l[cnt].y=p[i].y-y,
			l[cnt].q=p[i].q,
			l[cnt].xx=getxx(l[cnt].x, l[cnt].y);
	sort(l+1,l+1+cnt,cmp);
//	cout<<o<<endl;
//	for (int i=1;i<=cnt;i++) cout<<l[i].x<<' '<<l[i].y<<' '<<l[i].n<<' '<<l[i].xx<<endl;
	for (int i=cnt+1;i<=cnt*2;i++)
		l[i].xx=l[i-cnt].xx+4,
		l[i].x=l[i-cnt].x,
		l[i].y=l[i-cnt].y,
		l[i].q=l[i-cnt].q,
		l[i].n=l[i-cnt].n;
	int q=p[o].q;
	if (!q){
		for (int i=1, j=1;i<=cnt;i++){
			while (j<=cnt*2){
				if (l[j].xx<=l[i].xx) {j++;continue;}
				if (l[j].xx>l[i].xx+1) break;
				if (dot(l[i],l[j])>0){j++;continue;}
				if (dot(l[i],l[j])<0) break;
				++ri[l[j++].q];
			}
			ans[p[o].n]+=ri[1]*l[i].q;
			while (i<cnt && !cross(l[i],l[i+1]) && (l[i].xx==l[i+1].xx))
				ans[p[o].n]+=ri[1]*l[++i].q;
			ri[0]=ri[1]=0;
		}
	}
	else{
		for (int i=1, j=1;i<=cnt;i++){
			while (j<=cnt*2){
				if (l[j].xx<=l[i].xx) {j++;continue;}
				if (l[j].xx>l[i].xx+1) break;
				if (dot(l[i],l[j])>0){j++;continue;}
				if (dot(l[i],l[j])<0) break;
				++ri[l[j++].q];
			}
			le[0]=le[1]=0;
			ans[l[i].n]+=ri[1]*(!l[i].q);
			++le[l[i].q];
			while (i<cnt && !cross(l[i],l[i+1]) && (l[i].xx==l[i+1].xx))
				ans[l[i+1].n]+=ri[1]*(!l[i+1].q), 
				le[l[++i].q]++;
			if (ri[0]+ri[1])
				for (int k=1;k<=ri[0]+ri[1];k++)
					 ans[l[j-k].n]+=le[1]*(!l[j-k].q);
			ri[0]=ri[1]=0;
		}
	}
}
int main(){
	n=read();q=read();
	for (int i=1;i<=n+q;i++) p[i].x=read(), p[i].y=read(), p[i].n=i, p[i].q=i<=n;
	n+=q;
	for (int i=1;i<=n;i++){
		solve(i);
//		for (int j=n-q+1;j<=n;j++) printf("%d\n", ans[j]);
	}
	for (int i=n-q+1;i<=n;i++) printf("%d\n", ans[i]);
    return 0;
}
