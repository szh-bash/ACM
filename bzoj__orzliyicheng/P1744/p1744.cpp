#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
struct zsm{
	int x, y;
	double t;
}l[300000];
int n, m, a[300][300], flag[30000], le, ri;
long long q[60];
double v, f[30000];
void add(int x, int y, double t, int w){
	if (!x || !y || (x>n) || (y>m)) return;
	int tv=a[1][1]-w;
	double tmp;
	if (tv>=0) tmp=t+1/v/q[tv];
		else tmp=t+q[-tv]/v;
	if (tmp>=f[(x-1)*m+y]) return;
	f[(x-1)*m+y]=tmp;
	if (!flag[(x-1)*m+y]){
		flag[(x-1)*m+y]=1;
		l[++ri].x=x;
		l[ri].y=y;
		l[ri].t=tmp;
	}
}
int main(){
	cin>>v>>n>>m;
	q[0]=1;
	for (int i=1;i<=51;i++) q[i]=q[i-1]*2;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)	cin>>a[i][j], f[(i-1)*m+j]=(double)1000000000*1000000000;
	int x, y;
	f[1]=0;
	l[1].x=l[1].y=ri=1;
	l[1].t=0;
	while (le<ri){
		x=l[++le].x;
		y=l[le].y;
		flag[(x-1)*m+y]=0;
		add(x-1,y,f[(x-1)*m+y],a[x][y]);
		add(x,y+1,f[(x-1)*m+y],a[x][y]);
		add(x,y-1,f[(x-1)*m+y],a[x][y]);
		add(x+1,y,f[(x-1)*m+y],a[x][y]);
	}
	printf("%.2lf\n", f[n*m]);
	return 0;
}
