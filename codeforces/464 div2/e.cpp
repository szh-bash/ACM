#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define eps 1e-5
#define pi acos(-1)
typedef long long ll;
typedef long double db;
using namespace std;
db n, x[5], y[5], r[5];
int f[5][5];
db sqr(db x) {return x*x;}
int check(int u, int v){
	db dist=sqrt(sqr(x[u]-x[v])+sqr(y[u]-y[v]));
	if (r[v]+dist<=r[u]) return 3;
	if (r[u]+dist<=r[v]) return 2;
	if (r[u]+r[v]>dist) return 1;
	return 0;
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++) cin>>x[i]>>y[i]>>r[i];
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++){
			f[i][j]=check(i,j);
			if (f[i][j]==2) f[j][i]=3;
			if (f[i][j]==3) f[j][i]=2;
			if (f[i][j]<2) f[j][i]=f[i][j];
		}
	if (n==1){
		cout<<2<<endl;
		return 0;
	}
	if (n==2){
		cout<<(3+f[1][2])<<endl;
		return 0;
	}
	int k=(f[1][2]!=0)+(f[1][3]!=0)*2+(f[2][3]!=0)*4;
	if (k==0){
		cout<<4<<endl;
		return 0;
	}
	if (k==1 || k==2 || k==4){
		cout<<5<<endl;
		return 0;
	}
	if (k==3 || k==5 || k==6){
		cout<<(6-(f[1][2]>1)-(f[1][3]>1)-(f[2][3]>1))<<endl;
		return 0;
	}
	int flag=0;
	db dist=sqrt(sqr(x[1]-x[2])+sqr(y[1]-y[2]));
	db phi=acos((db)(sqr(r[1])-sqr(r[2])+sqr(dist))/(2*r[1]*dist));
	db h=sin(phi)*r[1], d=cos(phi)*r[1];
	db d0=sqrt(sqr(r[1])-sqr(h));
	db x0=(x[2]-x[1])*d0/dist+x[1], y0=(y[2]-y[1])*d0/dist+y[1];
	db x1=x0-(y[2]-y[1])*h/dist, y1=y0+(x[2]-x[1])*h/dist;
	db x2=x0+(y[2]-y[1])*h/dist, y2=y0-(x[2]-x[1])*h/dist;
	flag|=fabs(sqrt(sqr(x1-x[3])+sqr(y1-y[3]))-r[3])<eps;
	flag|=fabs(sqrt(sqr(x2-x[3])+sqr(y2-y[3]))-r[3])<eps;
/*	cout<<x1<<' '<<y1<<' '<<sqrt(sqr(x1-x[1])+sqr(y1-y[1]))<<endl;
	cout<<x1<<' '<<y1<<' '<<sqrt(sqr(x1-x[2])+sqr(y1-y[2]))<<endl;
	cout<<x1<<' '<<y1<<' '<<sqrt(sqr(x1-x[3])+sqr(y1-y[3]))<<endl;
	cout<<x2<<' '<<y2<<' '<<sqrt(sqr(x2-x[1])+sqr(y2-y[1]))<<endl;
	cout<<x2<<' '<<y2<<' '<<sqrt(sqr(x2-x[2])+sqr(y2-y[2]))<<endl;
	cout<<x2<<' '<<y2<<' '<<sqrt(sqr(x2-x[3])+sqr(y2-y[3]))<<endl;*/
	cout<<(8-(f[1][2]>1 || f[2][3]>1 || f[1][3]>1)-(f[1][2]>1)-(f[1][3]>1)-(f[2][3]>1)-flag)<<endl;
	return 0;
}
