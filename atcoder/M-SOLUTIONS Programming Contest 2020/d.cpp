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
#define N 2000
ll n, a[N];
ll g[N];
int main(){
	n=read();
	g[0]=1000;
	for (int i=1;i<=n;i++){
		a[i]=read();
		for (int j=1;j<i;j++)
			g[i]=max(g[i],g[j]+g[j]/a[j]*(a[i]-a[j]));
		for (int j=0;j<i;j++)
			g[i]=max(g[i],g[j]);
	}
	cout<<g[n]<<endl;
    return 0;
}
