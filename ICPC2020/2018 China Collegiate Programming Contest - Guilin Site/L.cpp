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
#define mo 1000000007
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
int x[5], y[5];
inline ll xj(int x1, int y1, int x2, int y2){
	return x1*y2-x2*y1;
}
inline long double xjd(long double x1, long double y1, long double x2, long double y2){
	return x1*y2-x2*y1;
}
bool seg_cross(){
	int res = xj(x[0]-x[1], y[0]-y[1], x[1]-x[3], y[1]-y[3])*
			  xj(x[2]-x[1], y[2]-y[1], x[1]-x[3], y[1]-y[3]);
	return res<0;
}
void get_point(long double &x0, long double &y0){
	long double k0, k1;
	if (x[2]==x[0]) k0=(long double) 999999999.0*999999; 
		else k0=(long double)1.0*(y[2]-y[0])/(x[2]-x[0]);
	if (x[3]==x[1]) k1=(long double) 999999999.0*999999; 
		else k1=(long double)1.0*(y[3]-y[1])/(x[3]-x[1]);
	long double b0=y[0]-k0*x[0], b1=y[1]-k1*x[1];
	x0 = (b1-b0)/(k0-k1);
	y0 = k0*x0+b0;
}
bool line(int u){
	return 0;
}
void solve(int T){
	for (int i=0;i<4;i++) x[i]=read(), y[i]=read();
	if (line(2) || line(3)){
		printf("Case %d: 0\n", T);
		return;
	}
	ll res = xj(x[2]-x[0], y[2]-y[0], x[0]-x[1], y[0]-y[1])*
			 xj(x[3]-x[0], y[3]-y[0], x[0]-x[1], y[0]-y[1]);
	ll sum = xj(x[2]-x[0], y[2]-y[0], x[0]-x[1], y[0]-y[1])+
			 xj(x[3]-x[0], y[3]-y[0], x[0]-x[1], y[0]-y[1]);
	if (res<=0){
			printf("Case %d: %s\n", T, (res<0 || sum==0)?"0":"inf");
			return;
		}
	if (seg_cross())
		swap(x[2], x[3]),
		swap(y[2], y[3]);
	// cout<<seg_cross()<<endl;
	if ((x[2]-x[0])*(y[3]-y[1]) == (x[3]-x[1])*(y[2]-y[0])){
		printf("Case %d: inf\n", T);
		return;
	}
	long double x0, y0;
	get_point(x0,y0);
	cout<<x0<<' '<<y0<<endl;
	long double resd = xjd(x0-x[0], y0-y[0], x[1]-x[0], y[1]-y[0])*
						xjd(x[2]-x[0], y[2]-y[0], x[1]-x[0], y[1]-y[0]);
	if (resd >= 0){
		printf("Case %d: inf\n", T);
		return;
	}
	long double ans = 0.5*xjd(x[0]-x0, y[0]-y0, x[1]-x0, y[1]-y0);
	printf("Case %d: ", T);
	cout<<fabs(ans)<<endl;
}
int main(){
	for (int _=read(), o=1;_;_--, o++)
		solve(o);
    return 0;
}
