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
ll solve(){
	ll n=read(), k=read();
	ll l=read(), r=read();
	ll x=read(), y=read();
	ll dup=min(y,r)-max(x,l);
	ll all=max(y,r)-min(x,l);
	ll res=0;
	if (l>y){
		swap(l,x);
		swap(y,r);
	}
	if (x>r){
		ll t=(k-1)/all+1;
		if (t>n) return (x-r+all)*n+(k-all*n)*2;
		res+=(t-1)*(x-r+all);
		k-=(t-1)*all;
		if (k<x-r && t>1) return res+k*2;
		return res+x-r+k;
	}
	else{
		if (dup*n>=k) return 0;
		k-=dup*n;
		if ((all-dup)*n>=k) return k;
		res+=(all-dup)*n;
		k-=(all-dup)*n;
		return res+k*2;
	}
}
int main(){
	for (int _=read();_;_--) printf("%I64d\n", solve());
	return 0;
}
