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
#define N 30
#define eps 1e-5
int n=20;
double sqr(double x){return x*x;}
double get(double x1, double y1, double x2, double y2){return x1*y2-x2*y1;}
double x[N], y[N];
void solve(){
	int st, ed;
	for (int i=1;i<=n;i++) scanf("%lf%lf", &x[i], &y[i]);
	x[n+1]=x[1], y[n+1]=y[1];
	for (int i=1;i<=n;i++)
		if (fabs(sqrt(sqr(x[i]-x[i+1])+sqr(y[i]-y[i+1]))-9)<eps){
			st=i;
			ed=i%n+1;
		}
	int ri=ed%n+1;
	double xj=get(x[ri]-x[ed], y[ri]-y[ed], x[st]-x[ed], y[st]-y[ed]);
	double ri_len=sqrt(sqr(x[ri]-x[ed])+sqr(y[ri]-y[ed]));
//	cout<<st<<' '<<ed<<' '<<ri<<' '<<ri_len<<endl;
	if (fabs(ri_len-8)<eps){
		//five
		if (xj>0) puts("right");
		else puts("left");
	}
	else{
		//flase
		if (xj>0) puts("left");
		else puts("right");
	}
}
int main(){
	for (int _=read();_;_--) solve();
    return 0;
}
