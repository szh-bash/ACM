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
int n, x[200], y[200];
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
int len(int x, int y) {return x*x+y*y;}
int pd(int x1, int y1, int xx, int yy) {return x1*xx+y1*yy;}
int check(){
	if (!pd(x[2]-x[1], y[2]-y[1], x[3]-x[1], y[3]-y[1]) &&
		!pd(x[4]-x[2], y[4]-y[2], x[2]-x[1], y[2]-y[1]) &&
		!pd(x[4]-x[3], y[4]-y[3], x[3]-x[1], y[3]-y[1]) &&
		len(x[2]-x[1], y[2]-y[1])==len(x[3]-x[1], y[3]-y[1])){
			return 1;
	}
	return 0;
}
int main(){
	for (int _=read();_;_--){
		n=read();
		for (int i=1;i<=n;i++) x[i]=read(), y[i]=read();
		if (n!=4){
			puts("NO");
			continue;
		}
		
		if (check()){
			puts("YES");
			continue;
		}
		swap(x[2], x[4]);
		swap(y[2], y[4]);
		if (check()){
			puts("YES");
			continue;
		}
		swap(x[3], x[4]);
		swap(y[3], y[4]);
		if (check()){
			puts("YES");
			continue;
		}
		puts("NO");
	}
    return 0;
}
