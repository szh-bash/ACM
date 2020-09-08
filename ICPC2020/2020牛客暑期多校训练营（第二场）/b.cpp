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
#define N 3000
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
const double eps = 1e-9;
int n, ct, f[N], tag[N];
double x[N], y[N], a[N], b[N];
bool check_px(int i, int j){
	if (y[i]==0 && y[j]==0) return 1;
	if (y[i]==0 || y[j]==0) return 0;
	return fabs(a[i]-a[j])<eps;
}
bool check_cv(int i, int j){
	if (y[i]==0 && y[j]==0) return x[i]==x[j];
	return fabs(b[i]-b[j])<eps;
}
struct point{
	double x, y;
	int i, j;
}p[N*N];
void cross(int i, int j){
	++ct;
	if (y[i]==0 || y[j]==0){
		if (y[j]==0) swap(i,j);
		p[ct].x=x[i]/2;
		p[ct].y=x[i]*a[j]/2+b[j];
	}
	else
		p[ct].x=(b[j]-b[i])/(a[i]-a[j]),
		p[ct].y=p[ct].x*a[i]+b[i];
	p[ct].i=i;
	p[ct].j=j;
}
double sqr(double x) {return x*x;}
bool cmp(point a, point b){
	if (a.x<b.x) return 1;
	if (a.x>b.x) return 0;
	return a.y<b.y;
}
int ans;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		scanf("%lf%lf", &x[i], &y[i]);
		f[i]=1;
		if (x[i]==0 && y[i]==0){
			ans++;
			n--;
			i--;
			continue;
		}
		if (y[i]!=0)
			a[i]=-x[i]/y[i],
			b[i]=(sqr(x[i])+sqr(y[i]))/2/y[i];
		for (int j=1;j<i;j++)
			if (check_px(i,j)){
				if (check_cv(i,j)) f[j]++;
			}
			else cross(i,j);
	}
	if (ct){
		sort(p+1,p+1+ct,cmp);
		int sum=2, ma=0, pos=1, flag=1;
		tag[p[1].i]=tag[p[1].j]=flag;
		for (int i=2;i<=ct;i++)
			if (fabs(p[i].x-p[i-1].x)<eps && fabs(p[i].y-p[i-1].y)<eps){
				if (tag[p[i].i]!=flag) sum++, tag[p[i].i]=flag;
				if (tag[p[i].j]!=flag) sum++, tag[p[i].j]=flag;
			}
			else{
				if (sum>ma) ma=sum, pos=i-1;
				sum=2;
				flag++;
				tag[p[i].i]=tag[p[i].j]=flag;
			}
		if (sum>ma) ma=sum, pos=ct;
		double r2=sqr(p[pos].x)+sqr(p[pos].y);
		for (int i=1;i<=n;i++)
			if (fabs(sqr(x[i]-p[pos].x)+sqr(y[i]-p[pos].y)-r2)<eps) ans++;
		cout<<ans<<endl;
	}
	else{
		int ma=0;
		for (int i=1;i<=n;i++) ma=max(ma, f[i]);
		cout<<ma+ans<<endl;
	}
    return 0;
}
