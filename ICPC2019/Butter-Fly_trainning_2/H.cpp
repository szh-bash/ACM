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
int n;
char s0[100], s1[100];
ll bit[100];
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
ll calc(char *s){
	ll p=1;
	for (int i=n-1;i>=0;i--)
		if (s[i]=='1')
			p=bit[n-i-1]-p+1+bit[n-i-1];
	return p;
}
int main(){
	n=read();
	scanf("%s%s", s0, s1);
	bit[0]=1;
	for (int i=1;i<=n;i++) bit[i]=bit[i-1]<<1;
	ll ans=-1;
	ans-=calc(s0);
	ans+=calc(s1);
	cout<<ans<<endl;
    return 0;
}
