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
#define N 100010
#define mo 998244353
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
ll f[N], g[N];
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
	f[3]=3;
	g[3]=0;
	for (int i=4;i<N;i++)
		f[i]=(f[i-1]*(i-1)+g[i-1])%mo,
		g[i]=(f[i-1]+g[i-1]*(i-2))%mo;
	
	for (int _=read();_;_--) printf("%lld\n", f[read()]);
    return 0;
}
