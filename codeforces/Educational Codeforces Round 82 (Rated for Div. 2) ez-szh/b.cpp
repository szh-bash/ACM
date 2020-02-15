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
	ll n = read(), g = read(), b = read();
	ll m = (n + 1) / 2;
	ll bd_last = max( (n-1) % (g + b) + 1 - g, 0ll);
	ll gd_last = min( (n-1) % (g + b) + 1 , g);
	ll bd = n / (g + b) * b + (bd_last == b?0:bd_last);
	if (bd + m <= n) return n;
	if (bd + m - n <= g - gd_last) return n + (m - n + bd);
	ll nd = m - (n - bd) - (g - gd_last);
	return n + (b-bd_last) + (g - gd_last) + ((nd-1)/g+1)*(g+b) - b - (g-(nd-1)%g-1);
//	return ((m-1)/g+1)*(g+b)-b-(g-(m-1)%g-1);
//	return m/g*(g+b)+m%g;
}
int main(){
	for (int _=read();_;_--) printf("%I64d\n", solve()); 
	return 0;
}
