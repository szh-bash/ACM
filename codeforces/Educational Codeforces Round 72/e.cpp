#include <map>
#include <set> 
#include <ctime>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=='-'?q=-1:0, ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
ll readll(){
	ll p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=='-'?q=-1:0, ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
#define N 1000000
#define M 2000000
int n, m, p[N], a[N];
ll f[M], ans[M];
int check(int i, int j, ll sum){
	ll p=1;
	while (sum>=p){
		int x=sum/p%10;
		int flag=0;
		for (int k=i;k<=j;k++)
			if (a[k]/p%10==x) {flag=1;break;}
		if (!flag) return 1;
		p=p*10;
	}
	return 0;
}
void upd(int t, int l, int r, int x, ll y){
	cout<<l<<' '<<r<<endl;
	if (l==r) {f[t]=y;return;}
	int mid=l+r>>1;
	if (x<=mid) upd(t<<1,l,mid,x,y);
	else upd((t<<1)+1,mid+1,r,x,y);
	f[t]=min(f[t<<1],f[(t<<1)+1]);
}
const ll inf=1ll*999999999*999999999;
ll query(int t, int l, int r, int le, int ri){
	if (le<=l && r<=ri) return f[t];
	int mid=l+r>>1;
	ll p0=inf, p1=inf;
	if (le<=mid) p0=query(t<<1,l,mid,le,ri);
	if (ri>mid) p1=query((t<<1)+1,mid+1,r,le,ri);
	return min(p0, p1);
}
int main(){
	int	n=read(), m=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++){
		int ma=0;
		ll sum=0;
		ans[i]=inf;
		for (int j=i;j<=n;j++){
			cout<<i<<' '<<j<<endl;
			sum+=a[j];
			ma=max(ma,a[j]);
			if (check(i,j,sum)) {ans[i]=sum;p[i]=j;break;}
		}
		upd(1,1,n,i,ans[i]);
		cout<<i<<' '<<p[i]<<' '<<ans[i]<<endl;
	}
	cout<<"build ac"<<endl;	
	while (m--){
		int op=read();
		if (op==1){
			int x=read(), y=read();
			a[x]=y;
			for (int i=max(x-100, 1);i<=x;i++){
				int ma=0;
				ll sum=0;
				ans[i]=inf;
				for (int j=i;j<=n;j++){
					sum+=a[j];
					ma=max(ma,a[j]);
					if (check(i,j,sum)) {ans[i]=sum;p[i]=j;break;}
				}
				upd(1,1,n,i,ans[i]);
			}
		}
		else{
			int l=read(), r=read();
			ll res=l<=r-100?query(1,1,n,l,r-100):inf;
			for (int i=max(l,r-99);i<=r;i++)
				if (p[i]<=r) res=min(res,ans[i]);
//			printf("%I64d\n", res);
			cout<<res<<endl;
		}
		
	}
	return 0;
}
