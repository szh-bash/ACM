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
int n, ma, a[N], g[N];
ll e[N], f[N];
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
	for (int T=read();T;T--){
		n=read();
		for (int i=1;i<=n;i++) a[i]=read();
		f[n]=0;g[n]=0;
		e[n]=a[n];
		ma=n;
		for (int i=n-1;i;i--){
			if (e[ma]-a[i]>f[i+1] || e[ma]-a[i]==f[i+1] && g[ma]+1<g[i+1])
				f[i]=e[ma]-a[i], g[i]=g[ma]+1;
			else
				f[i]=f[i+1], g[i]=g[i+1];
			e[i]=f[i+1]+a[i];
			if (e[i]>e[ma] || e[i]==e[ma] && g[i]<g[ma]) ma=i;
		}
		cout<<f[1]<<' '<<g[1]*2<<endl;
	}
    return 0;
}
