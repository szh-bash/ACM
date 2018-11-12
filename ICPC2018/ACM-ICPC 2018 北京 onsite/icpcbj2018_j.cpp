#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 3000
#define mo 998244353
typedef long double ld;
typedef long long ll;
//typedef __int128 ull;
typedef long long ull;
using namespace std;
ull ts_a, ts_b;
const ld pi=acos(-1);
struct vec{
	ull x, y;
	double a;
}l[N], g[N];
ll x[N], y[N];
int n, cnt;
ld get_sqrt(ull v){
	ld le=0, ri=v, eps=1e-20;
	while (ri-le>eps){
		ld mid=(le+ri)/2;
		if (mid*mid>v) ri=mid;else le=mid;
	}
	return le;
}
double get_angle(ull x, ull y){
	double a=acos((double)x/get_sqrt(x*x+y*y));
	if (y<0) a=2*pi-a;
	//cout<<x<<' '<<y<<' '<<a<<endl;
	return a;
/*	double t=atan2(y, x);
	if (t<0) t=2*pi+t;
	return t;*/
//	return atan2(y, x);
}
bool cmp(vec a, vec b){ return a.a<b.a;}
ull chaji_lg_b(int x, int h, int t){
	return (l[x].x*(g[h].y-g[t+1].y)-l[x].y*(g[h].x-g[t+1].x))%mo;
}
void calc_add(){
	ull tmp=0;
	int mid=cnt+1;
	for (int i=2;i<=cnt;i++)
		if (l[i].a-l[1].a>pi){
			mid=i;
			break;
		}
	for (int i=1;i<cnt;i++){
		while (mid<=cnt && l[mid].a-l[i].a<=pi) mid++;
		ull tp=chaji_lg_b(i,i+1,mid-1)-chaji_lg_b(i,mid,cnt);
		if (tp<0) tp=-tp;
//		if (tp>=mo) tp-=mo;
		tmp=(tmp+tp)%mo;
//		if (tmp>=mo) tmp-=mo;
//		cout<<(ll)l[i].x<<' '<<(ll)l[i].y<<' '<<l[i].a<<endl;
	}
//	cout<<(ll)tmp<<endl<<endl;
	ts_a=(ts_a+tmp)%mo;
//	if (ts_a>=mo) ts_a-=mo;
	//cout<<(ll)tmp<<' '<<"lyk"<<endl;
}
void calc_sub(){
	int head=cnt+1, tail=1, mid=cnt+1;
	for (int i=2;i<=cnt;i++)
		if (l[i].a-l[1].a>=pi/2){
			head=i;
			break;
		}
	for (int i=2;i<=cnt;i++)
		if (l[i].a-l[1].a>pi) {
			mid=i;
			break;
		}
	for (int i=cnt;i;i--)
		if (l[i].a-l[1].a<=3*pi/2){
			tail=i;
			break;
		}
//	cout<<head<<' '<<tail<<endl;
	for (int i=1;i<cnt;i++){
		while (head<=cnt && l[head].a-l[i].a<pi/2) head++;
		while (mid<=cnt && l[mid].a-l[i].a<=pi) mid++;
		while (tail<cnt && l[tail+1].a-l[i].a<=3*pi/2) tail++;
		ull tttt=0;
		if (head<=mid && head<=tail) tttt=chaji_lg_b(i,head,min(mid-1,tail));
		if (mid<=tail) tttt-=chaji_lg_b(i,mid,tail);
		if (tttt<0) tttt=-tttt;
//		if (tttt>=mo) tttt-=mo;
		ts_b=(ts_b+tttt)%mo;
//		if (ts_b>=mo) ts_b-=mo; 
	}
}
ll power(ll x, int y){
	ll c=1;
	while (y){
		if (y&1) c=c*x%mo;
		x=x*x%mo;
		y>>=1;
	}
	return c;
}
int main(){
//	cout<<acos(1)<<' '<<acos(-1)<<' '<<acos(0)<<endl;
	int _;cin>>_;
	ull md=power(3,mo-2);
	for (;_;_--){
		ts_a=ts_b=0;
		cin>>n;
		for (int i=1;i<=n;i++){
			ll tx, ty;
			scanf("%lld%lld", &tx, &ty);
			x[i]=tx, y[i]=ty;
		}
		for (int i=1;i<=n;i++){
			cnt=0;
			for (int j=1;j<=n;j++)
				if (i!=j){
					l[++cnt].x=x[j]-x[i];
					l[cnt].y=y[j]-y[i];
					l[cnt].a=get_angle(l[cnt].x, l[cnt].y);
				}
			sort(l+1,l+1+cnt,cmp);
			g[cnt+1].x=g[cnt+1].y=0;
			g[cnt].x=l[cnt].x%mo;
			g[cnt].y=l[cnt].y%mo;
			for (int i=cnt-1;i;i--)
				g[i].x=(g[i+1].x+l[i].x)%mo,
				g[i].y=(g[i+1].y+l[i].y)%mo;
			calc_add();
			calc_sub();
		}
		ts_a=ts_a*md%mo;
//		cout<<(ll)ts_a<<' '<<(ll)ts_b<<endl;
		ll ans=((ts_a-ts_b)%mo+mo)%mo;
		cout<<ans<<endl;
	}
	return 0;
}
