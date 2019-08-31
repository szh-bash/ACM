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
ll readll(){
	ll p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=='-'?q=-1:0, ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
ll gcd(ll a, ll b){
	return b?gcd(b, a%b):a;
}
int main(){
	ll n=readll(), m=readll();
	ll gys=gcd(n,m);
	ll tn=n/gys, tm=m/gys;
	for (int _=readll();_;_--){
		ll sx=readll(), sy=readll(), ex=readll(), ey=readll();
		ll bs, be;
		if (sx==1) bs=(sy-1)/tn+1;else bs=(sy-1)/tm+1;
		if (ex==1) be=(ey-1)/tn+1;else be=(ey-1)/tm+1;
		if (bs==be) puts("YES");else puts("NO");
	}
	return 0;
}
