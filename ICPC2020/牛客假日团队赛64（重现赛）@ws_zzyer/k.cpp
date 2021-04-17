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
#define N 5
int suma, sumb, a[N], b[N];
int main(){
	int n=4;
	for (int i=1;i<=n;i++) suma+=a[i]=read(), sumb+=b[i]=read();
	int dt = sumb-suma;
	a[1]+=dt;
	for (int i=1;i<n;i++)
		if (a[i]>b[i])
			printf("%d\n", a[i]-b[i]),
			a[i+1]+=a[i]-b[i];
		else puts("0");

    return 0;
}
