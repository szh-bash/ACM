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
int a[10];
int calc(int x){
	if (x<49) x=a[1];
	else if (x<57) x=a[2];
	else if (x<61) x=a[3];
	else if (x<63) x=a[4];
	else x=a[5];
	return x;
}
int main(){
	for (int _=read(), o=1;_;_--, o++){
		for (int i=1;i<=5;i++) a[i]=read();
		int n=read();
		ll ans=0;
		for (int i=1;i<=n;i++) ans+=calc(read());
		printf("Case #%d: %I64d\n",o, ans*10000);
	}
    return 0;
}
