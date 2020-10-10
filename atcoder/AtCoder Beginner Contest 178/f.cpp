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
#define N 200005
int n, a[N], b[N], f[N], g[N];
int main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(), f[a[i]]++;
	for (int i=1;i<=n;i++) b[i]=read(), g[b[i]]++;
	for (int i=1;i<=n;i++)
		if (f[i]+g[i]>n){
			puts("No");
			return 0;
		}
	puts("Yes");
	for (int i=1;i<=n/2;i++) swap(b[i],b[n-i+1]);
	int x=0, le=n+1, ri=0;
	for (int i=1;i<=n;i++) if (a[i]==b[i]) x=a[i];
	for (int i=1;i<=n;i++) if (a[i]==x || b[i]==x) le=min(le,i), ri=max(ri, i);	
	for (int i=1, j=1;i<=n;i++)
		if (a[i]==b[i]){
			if (le<=j && j<=ri) j=ri+1;
			swap(b[j++], b[i]);
		}
	for (int i=1;i<=n;i++) printf("%d%s", b[i], i==n?"\n":" ");	
    return 0;
}
/*
5
2 2 3 3 3
1 1 2 2 3
*/ 
