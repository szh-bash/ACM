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
#define N 200000
ll n, a, r, m, h[N], sum[N], ans;
void get(int x, ll &le, ll &ri){
	le=0, ri=n+1;
	while (le<ri-1){
		int mid=le+ri>>1;
		if (h[mid]<x) le=mid;
		else ri=mid;
	}
}
ll solve(int x){
	ll le, ri;
	get(x, le, ri);
	le=x*le-sum[le], ri=sum[n]-sum[ri-1]-x*(n-ri+1);
	ll com=min(le,ri), res=(le-com)*a+(ri-com)*r;
	return min(le*a+ri*r,com*m+res);
}
int main(){
	ans=1ll*999999999*999999999*8;
	n=read(), a=read(), r=read(), m=read();
	for (int i=1;i<=n;i++) h[i]=read();
	sort(h+1, h+1+n);
	for (int i=1;i<=n;i++) sum[i]=sum[i-1]+h[i];
	int le=-1, ri=999999999+5;
	while (ri-le>2){
		int l1=le+(ri-le)/3, l2=le+2*(ri-le)/3;
		ll tmp1=solve(l1), tmp2=solve(l2);
		if (tmp1>tmp2) le=l1, ans=tmp2;
		else ri=l2, ans=tmp1;
	}
	cout<<ans<<endl;
	return 0;
}
