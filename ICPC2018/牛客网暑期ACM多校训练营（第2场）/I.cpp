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
int ans, n, m, f[N], g[N];
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
	n=read();m=read();
	for (int i=1;i<=n;i++) f[i]=g[i]=1;
	for (int i=1;i<=m;i++){
		int x=read(), y=read();
		f[x]=g[y]=0;
	}
	for (int i=1;i<=n;i++) ans+=f[i]+g[i];
	if (n&1 && f[n/2+1] && g[n/2+1]) ans--;
	cout<<ans<<endl;
    return 0;
}
