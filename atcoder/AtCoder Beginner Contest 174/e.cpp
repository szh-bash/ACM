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
int n, k;
double a[N];
bool check(double x){
	ll res=0;
	for (int i=1;i<=n;i++) res+=ceil(a[i]/x)-1;
	return res<=k;
}
int main(){
	n=read(), k=read();
	double le=0.9, ri=1000000002;
	for (int i=1;i<=n;i++) a[i]=read();
	while (ri-le>0.00001){
		double mid=(le+ri)/2;
		if (check(mid)) ri=mid;
		else le=mid;
	}
	ll ans=ceil(ri);
	cout<<ans<<endl;
    return 0;
}

