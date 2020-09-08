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
int k, a, b, c, bit[20];
int main(){
	a=read(), b=read(), c=read();
	k=read();
	bit[0]=1;
	for (int i=1;i<=10;i++) bit[i]=bit[i-1]<<1;
	for (int i=0;i<=k;i++)
		if (a<b*bit[i] && b*bit[i]<c*bit[k-i]){
			puts("Yes");
			return 0;
		}
	puts("No");
    return 0;
}
