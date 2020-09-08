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
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
ll readll(){
    ll p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
#define N 100005
int n, b[N];
bool check(int x){
	ll sum=0;
	for (int i=n;i;i--)
		if (b[i]>x) sum+=b[i]-x;
		else sum=max(0ll, sum-x+b[i]);
	return sum==0;
}
void solve(){
	n=read();
	int l=0, r=0;
	for (int i=1;i<=n;i++) b[i]=read(), r=max(r,b[i]);
	while (l<r-1){
		int mid=l+r>>1;
		if (check(mid)) r=mid;else l=mid;
	}
	printf("%d\n", r);
}
int main(){
	for (int _=read();_;_--) solve();
    return 0;
}
