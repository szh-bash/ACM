#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
struct zsm{
	double x;double y;
	zsm (double u=0,double v=0){x=u;y=v;}
	zsm operator -(const zsm &A){return zsm(x-A.x,y-A.y);}
	zsm operator /(const double &a){return zsm(x/a,y/a);}
}a[2], b[2], p[2];
double P,q,r;
const double eps=1e-12;
double sqr(double x){return x*x;}
double dist(zsm a, zsm b){
	return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
}
void read(zsm &a){cin>>a.x>>a.y;}
double geta(){
	return dist(a[0],p[0])/P+dist(p[0],p[1])/r+dist(p[1],b[1])/q;
}
double div3(int k){
	zsm l=a[k],r=b[k],m1,m2,del;
	double a1,a2;
	while (dist(l,r)>eps){
		del=(r-l)/3;
		m2=r-del;m1=m2-del;
		p[k]=m1;if (k) a1=div3(1-k);else a1=geta();
		p[k]=m2;if (k) a2=div3(1-k);else a2=geta();
		if (a1<a2) r=m2;else l=m1;
	}
	if (dist(a[k],b[k])<=eps){
		p[k]=a[k];
		if (k) return div3(1-k);
			else return geta();
	}
	return a1;
}
int main(){
	for (int i=0;i<2;i++)
		read(a[i]), read(b[i]);
	cin>>P>>q>>r;
	printf("%.2lf\n", div3(1));
	return 0;
}
