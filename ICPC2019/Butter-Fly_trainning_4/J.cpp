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
#define N 300000
int n, a[N];
int solve(){
	n=read();
	for (int i=1;i<=10;i++) a[i]=0;
	for (int i=1;i<=n;i++) a[i+10]=read();
	n+=10;
	ll sum=0;
	a[n+1]=0;
	for (int i=1;i<=n;i++) a[i]=a[i+1]-a[i], sum+=a[i];
	if (sum) return 0;
	sum=0;
	for (int i=6;i<=n;i++){
		if (a[i]<0)
			if (sum+a[i]<0) return 0;
			else
				sum+=a[i],
				a[i]=0;
		sum+=a[i-2];
	}
	return 1;
}
int main(){
	for (int _=read(), o=1;_;_--, o++)
		printf("Case #%d: %s\n", o, solve()?"Yes":"No");
    return 0;
}
/*
4
13
1 2 2 1 0 0 0 0 0 0 0 0 0
13
1 1 1 1 0 1 1 0 0 0 0 0 0
9
1 2 3 4 4 6 4 4 4
8
1 2 3 3 6 4 4 4
*/
