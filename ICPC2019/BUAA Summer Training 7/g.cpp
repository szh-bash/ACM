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
#define mo 1000000007
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int x, x2, x3 ,x4, xx;
int y, y2, y3, y4, yy;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
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
int main(){
	freopen("grave.in", "r", stdin);
	freopen("grave.out", "w", stdout);
	x=read(), y=read(), x2=read(), y2=read();
	x3=read(), y3=read(), x4=read(), y4=read();
	xx=read(), yy=read();
	if ((y2-y4>=yy || y3-y>=yy) && x2-x>=xx || (x3-x>=xx || x2-x4>=xx) && y2-y>=yy) puts("Yes");
	else puts("No");
    return 0;
}
