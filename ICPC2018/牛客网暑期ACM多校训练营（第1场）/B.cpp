#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 200000
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int n, m;
ll f[N], g[N];
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
	f[0]=1;
	f[1]=0;
	f[2]=1;
	f[3]=1;g[3]=1;
	while (~scanf("%d%d", &n, &m)){
		for (ll i=4;i<=n;i++){
			ll k=((i-1LL)*(i-2)/2)%m;
			g[i]=(g[i-1]*(i-1)%m+k*f[i-3]%m)%m;
			f[i]=(f[i-2]*(i-1)%m+g[i])%m;
			//cout<<i<<' '<<f[i]<<' '<<g[i]<<endl;
		}
		printf("%lld\n", f[n]%m);
	}
    return 0;
}
