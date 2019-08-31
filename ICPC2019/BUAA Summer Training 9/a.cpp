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
int n, ct;
int ans[2000000];
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
	n=read()-1;
	for (ll i=1;i*i<=n;i++){
		if (n%i==0){
			ans[++ct]=i;
			if (i*i!=n) ans[++ct]=n/i;
		}
	}
	sort(ans+1,ans+1+ct);
	for (int i=1;i<=ct;i++) printf("%d%s", ans[i], i==ct?"\n":" ");
    return 0;
}
