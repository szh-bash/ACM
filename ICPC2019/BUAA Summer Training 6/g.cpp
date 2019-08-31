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
#define N 900
#define num(x) (x>='0' && x<='9')
#define eps 1e-8
#define eps_sanfen 1e-8
typedef unsigned long long ull;
typedef long long ll;
typedef double db;
using namespace std::tr1;
using namespace std;
const db pi=acos(-1);
int n, cnt, x[N], y[N];
db ans;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
struct line{
	int id;
	int x, y;
	db dist;
	db theta;
}l[N];
bool cmp(line u, line v){
	// to-do
	// ¼«½ÇÅÅÐò 
	return u.theta<v.theta;
}
void cpy(line &u, line &v){
	u.id=v.id;
	u.x=v.x;
	u.y=v.y;
	u.dist=v.dist;
	u.theta=v.theta+2*pi;
}
db sqr(db x) {return x*x;}
db cal(db theta, int rr){
	db mi=999999999;
	for (int i=rr+1;i<=rr+n/2;i++)
		mi=min(mi, fabs(sin(l[i].theta-theta)*l[i].dist));
	return mi;
}
void calc(db theta, db ri, int rr){
	db le=0;
	while (ri-le>eps_sanfen){
		db midl=le+(ri-le)/3, midr=le+2*(ri-le)/3;
		if (cal(theta+midl, rr)>cal(theta+midr, rr)) ri=midr;
		else le=midl;
	}
	ans=max(ans, cal(theta+le, rr));
}
int main(){
	n=read();
	for (int i=1;i<=n;i++)
		x[i]=read(),
		y[i]=read();
	for (int i=1;i<=n;i++){
		cnt=0;
		for (int j=1;j<=n;j++)
			if (i!=j){
				l[++cnt].id=j;
				l[cnt].x=x[j]-x[i];
				l[cnt].y=y[j]-y[i];
				l[cnt].dist=sqrt(sqr(l[cnt].x)+sqr(l[cnt].y));
				if (!l[cnt].x)
					l[cnt].theta=l[cnt].y>0?pi/2:3*pi/2;
				else{
					l[cnt].theta=atan((db)l[cnt].y/l[cnt].x)+(l[cnt].x>0 && l[cnt].y<0)*2*pi+(l[cnt].x<0)*pi;
//					l[cnt].theta=atan((db)l[cnt].y/l[cnt].x)+pi/2+(l[cnt].x<0)*pi;
				}
			}
		sort(l+1,l+1+cnt,cmp);
		for (int j=cnt+1;j<=cnt*2;j++)
			cpy(l[j],l[j-cnt]);
		int le=1, ri=0;
		db mid=0;
		while (le<=cnt){
			while (le<=cnt && l[le].theta-mid<eps) le++;
			while (l[ri+1].theta<mid+pi+eps) ri++;
			db tl=l[le].theta-mid;
			db tr=l[ri+1].theta-(mid+pi);
			db dt=min(tl, tr);
			if (ri-le+1+1==n/2) calc(mid, dt, ri);
			mid+=dt;
		}
	}
	printf("%.8lf\n", ans/2);
    return 0;
}
