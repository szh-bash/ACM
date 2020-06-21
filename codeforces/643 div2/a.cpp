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
bool check(ll &n){
	ll x = n;
	ll ma=0, mi=9;
	while (x){
		ma = max(ma, x%10);
		mi = min(mi, x%10);
		x /= 10;
	}
	if (!mi) return 0;
	n += ma*mi;
	return 1;
}
int main(){
	for (int _=read();_;_--){
		ll n=readll(), m=readll()-1;
		while (m && check(n)) m--;
		cout<<n<<endl;
	}
	return 0;
}
