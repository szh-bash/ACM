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
#define N 2005
int w[]={1,6,28,88,198,328,648};
int a[]={18,60+18,280+28,880+58,1980+128,3280+198,6480+388};
int ans, n, f[N];
int main(){
	n=read();
	for (int i=0;i<7;i++)
		for (int j=n;j>=w[i];j--)
			f[j]=max(f[j],f[j-w[i]]+a[i]);
	for (int i=1;i<=n;i++)
		ans=max(f[i]+(n-i)*10,ans);
	cout<<ans<<endl;
    return 0;
}
