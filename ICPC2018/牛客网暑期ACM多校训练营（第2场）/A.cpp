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
#define N 100000
#define mo 1000000007
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int k;
ll f[N*5][3], g[N*5];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
void upd(ll &a, ll b){
	a+=b;
	if (a>=mo) a%=mo;
}
int main(){
	int q=read();k=read();
	f[0][0]=1;
	f[0][1]=0;
	for (int i=0;i<N;i++)
		upd(f[i+k][1],f[i][0]),
		upd(f[i+1][0],f[i][0]+f[i][1]);
	for (int i=1;i<=N;i++)
		upd(g[i],g[i-1]+f[i][0]+f[i][1]);
	for (;q;q--){
		int l=read(), r=read();
		printf("%lld\n", ((g[r]-g[l-1])%mo+mo)%mo);
	}
    return 0;
}
