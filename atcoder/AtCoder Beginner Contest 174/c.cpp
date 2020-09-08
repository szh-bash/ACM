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
int f[2000000];
int main(){
	int k=read();
	int x=7, ans=1;
	if (x%k==0){
		puts("1");
		return 0;
	}
	x%=k;
	while (!f[x]){
		f[x]=1;
		x=(x*10+7)%k;
		ans++;
		if (!x){
			cout<<ans<<endl;
			return 0;
		}
	}
	puts("-1");
    return 0;
}
