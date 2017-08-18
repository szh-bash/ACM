#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define sqr(x) (x)*(x)
const double eps=1e-3;
const double INF=1e20;
const double pi=acos(-1.0);
using namespace std;
struct zsm{
	double x, y, dist;
}h[16];
int X, Y, n, cas;
double x[1001], y[1001];
int read(){
	char ch=getchar();
	int p=0;
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0'&& ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
double dis(double x1, double x2, double y1, double y2)
{return sqrt(sqr(x1-x2)+sqr(y1-y2));}
int main(){
	cas=read();
	srand(3);
	int L=25, P=15;
	while (cas--){
		X=read();Y=read();n=read(); 
		for (int i=1;i<=n;i++) scanf("%lf%lf", &x[i], &y[i]);
		double del=(double)(rand()%1000+1)/1000.000*(max(X,Y));
		for (int i=1;i<=P;i++){
			h[i].x=(double)(rand()%1000+1)/1000.000*X;
			h[i].y=(double)(rand()%1000+1)/1000.000*Y;
			h[i].dist=INF;
			for (int j=1;j<=n;j++)
				h[i].dist=min(h[i].dist,dis(h[i].x,x[j],h[i].y,y[j]));
		}
		while (del>eps){
			for (int i=1;i<=P;i++){
				zsm tmp=h[i];
				for (int j=1;j<=L;j++){
					zsm t;
					double the=double(rand()%1000+1)/1000.000*10*pi;
					t.x=tmp.x+del*cos(the);
					t.y=tmp.y+del*sin(the);
					if (t.x<0 || t.x>X || t.y<0 || t.y>Y) continue;
					t.dist=INF;
					for (int k=1;k<=n;k++)
						t.dist=min(t.dist,dis(t.x,x[k],t.y,y[k]));
					if (t.dist>h[i].dist) h[i]=t;
				}
			}
			del*=0.8;
		}
		int p=1;
		for (int i=2;i<=P;i++)
			if (h[i].dist>h[p].dist) p=i;
		printf("The safest point is (%.1lf, %.1lf).\n", h[p].x, h[p].y);
	}
	return 0;
}
