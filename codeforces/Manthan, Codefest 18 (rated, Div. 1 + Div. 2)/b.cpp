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
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int n, s, a[300000];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
int main(){
	n=read();s=read();
	for (int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	ll ans=0;
	for (int i=n/2+1;i;i--)
		if (a[i]>s) ans+=a[i]-s;
	for (int i=n/2+1;i<=n;i++)
		if (a[i]<s) ans+=s-a[i];
	cout<<ans<<endl;
    return 0;
}
