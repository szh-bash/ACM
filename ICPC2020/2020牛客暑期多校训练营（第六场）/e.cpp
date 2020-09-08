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
int n, k, a[5005];
int main(){
	n=read(), k=read();
	if (k!=(n*(n+1)/2)%n){
		puts("-1");
		return 0;
	}
	a[1]=n;
	if ((n-1)&1){
		a[2]=n>>1;
		for (int j=1;n-j>j;j++)
			a[2+2*j-1]=j,
			a[2+2*j]=n-j;
	}
	else{
		for (int j=1;n-j>j;j++)
			a[1+2*j-1]=j,
			a[1+2*j]=n-j;
	}
	for (int i=1;i<=n;i++) printf("%d%s", a[i], (i!=n?" ":"\n"));
    return 0;
}
