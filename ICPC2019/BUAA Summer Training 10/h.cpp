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
#define N 2100
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
int n, g[N], f[N];
int main(){
	for (int _=read();_;_--){
		n=read();
		for (int i=1;i<n;i++) g[i-1]=read(), f[i]=0;
		f[0]=n*g[0];
		for (int i=1;i<n-1;i++)
			for (int j=i;j<n-1;j++)
				f[j]=max(f[j], f[j-i]-g[0]+g[i]);
		printf("%d\n", f[n-2]);
	}
    return 0;
}
