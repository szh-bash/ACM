#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, tp, w[300000], pp;
long long a[1000000], tmp, k, m, ww;
long long x;
void update(int t, int l, int r, int d){
	if (l==r){
		a[t]=x;
		return;
	}
	int mid=l+r>>1;
	if (d<=mid) update(t*2,l,mid,d);
	else update(t*2+1,mid+1,r,d);
	a[t]=min(a[t*2],a[t*2+1]);
}
void query(int t, int l, int r){
	if (l==r){
		tmp=a[t];
		tp=l;
		return;
	}
	int mid=l+r>>1;
	if (a[t*2]>a[t*2+1]) query(t*2+1,mid+1,r);
	else query(t*2,l,mid);
}
void print(int t, int l, int r){
	if (l==r){
		if (w[l] && a[t]) cout<<'-';
		cout<<a[t]<<' ';
		return;
	}
	int mid=l+r>>1;
	print(t*2,l,mid);
	print(t*2+1,mid+1,r);
}
int main(){
	cin>>n>>k>>m;
	tmp=1999999999;
	for (int i=1;i<=n;i++){
		scanf("%I64d", &x);
		if (x<0){
			x=-x;
			w[i]=1;
			pp^=1;
		}
		update(1,1,n,i);
		if (x<tmp){
			tmp=x;
			tp=i;
		}
	}
	if (!pp){
		ww=min(1+(tmp/m),k);
		tmp-=m*ww;
		k-=ww;
		x=tmp;
		if (x<0) x=-x, w[tp]^=1;
		update(1,1,n,tp);
	}
	while (k--){
		query(1,1,n);
		x=tmp+m;
		update(1,1,n,tp);
	}
	print(1,1,n);
	return 0;
}
