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
#define N 5000
int n, m;
ll f[N], g[N], h[N];
ll solve(){
	ll ans=0;
	n=read();m=read()*2;
	for (int j=0;j<N;j++) f[j]=g[j]=h[j]=-1ll*999999999*999999999;
	h[0]=0;
	for (int i=1;i<=n;i++){
		int w=read()*2;
		ll v=read();
		ans=max(ans, v);
		if (w>=m*2) continue;
		for (int j=max(0,m-w);j;j--)
			g[j+w]=max(g[j+w], g[j]+v);
		for (int j=m-1;j;j--)
			if (j+w/2<=m) g[j+w/2]=max(g[j+w/2], f[j]+v);
		for (int j=max(0,m-w);j;j--)
			f[j+w]=max(f[j+w],f[j]+v);
		for (int j=m-1;j>=0;j--)
			if (j+w/2<=m) f[j+w/2]=max(f[j+w/2], h[j]+v);
		for (int j=max(0,m-w);j>=0;j--)
			h[j+w]=max(h[j+w], h[j]+v);
	}
	for (int j=1;j<=m;j++) ans=max(ans, g[j]);
	return ans;
}
int main(){
	for (int _=read(), O=1;_;_--, O++)
		printf("Case #%d: %I64d\n", O, solve());
    return 0;
}
