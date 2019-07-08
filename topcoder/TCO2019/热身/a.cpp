#include <map>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define eps (1e-5)
#define INF 9999999999
typedef long long ll;
using namespace std;
const double pi=acos(-1);
double w, h, x, y, r, dx, dy;
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') (ch=='-'?q=-1:0), ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
int main(){
	//cout<<sin(pi/4)<<' '<<sin(3*pi/4)<<' '<<sin(5*pi/4)<<' '<<sin(7*pi/4)<<endl;
	//cout<<cos(pi/4)<<' '<<cos(3*pi/4)<<' '<<cos(5*pi/4)<<' '<<cos(7*pi/4)<<endl;
	//return 0;
	w=read();h=read();
	x=read();y=read();
	r=read();
	dx=cos(r/180*pi), dy=sin(r/180*pi);
	//cout<<dx<<' '<<dy<<endl;
	int cnt=500000;
	while (cnt--){
		double tx, ty;
		if (dx>0) tx=(w-x)/dx;
		else if (dx<0) tx=-x/dx;
		else tx=INF;
		if (dy>0) ty=(h-y)/dy;
		else if (dy<0) ty=-y/dy;
		else ty=INF;
		double t=min(tx, ty);
		x+=t*dx;
		y+=t*dy;
		//cout<<x<<' '<<y<<' '<<w<<' '<<h<<endl;
		if (fabs(x-w)<eps || fabs(x)<eps) dx=-dx;
		if (fabs(y-h)<eps || fabs(y)<eps) dy=-dy;
		if ((fabs(x-w)<eps || fabs(x)<eps) && (fabs(y-h)<eps || fabs(y)<eps)){
			cout<<"Yes"<<endl;
			return 0;
		}
	}
	cout<<"No"<<endl;
	return 0;
}
