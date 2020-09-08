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
#define N 300000
int a[N], n;
ll f[N], g[2];
const ll inf = 1ll*999999999*99999999;
void solve(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	g[0]=g[1]=inf;
	for (int i=1;i<4;i++) f[i]=inf;
	for (int i=4;i<=n;i++){
		int o=i&1;
		if (i>=4) g[o]=min(g[o],f[i-4]-a[i-3]);
		f[i]=g[o]+a[i];
//		cout<<i<<' '<<g[o]<<' '<<f[i]<<endl;
	}
	cout<<f[n]*2<<endl;
}
int main(){
	for (int _=read();_;_--) solve();
    return 0;
}
