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
// #include <tr1/unordered_map>
#define mo 1000000007
typedef long long ll;
using namespace std;
// using namespace std::tr1;
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
int power(ll a, int b){
	ll c=1;
	while (b){
		if (b&1) c=c*a%mo;
		a=a*a%mo;
		b>>=1;
	}
	return c;
}
#define N 100005
int n, m, a[N];
ll sum[N];
unordered_map<ll, int> f;
void build(int l, int r){
	f[sum[r]-sum[l-1]]=1;
	if (l==r) return;
	int x=a[l]+a[r]>>1, mid=l;
	for (int i=l;i<=r && a[i]<=x;i++) mid=i;
	if (mid==r) return;
	build(l,mid);
	build(mid+1,r);
}
void solve(){
	f.clear();
	n=read();m=read();
	for (int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	build(1,n);
	for (int i=1;i<=m;i++){
		if (f[read()]) puts("Yes");
		else puts("No");
	}
}
int main(){
	for (int _=read();_;_--) solve();
	return 0;
}
