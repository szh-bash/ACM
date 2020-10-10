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
#define N 105
#define L 10005
#define inf 1e9
int l, n, f[N][L][2];
bool solve(){
	l=read();n=read();
	for (int i=1;i<=n;i++)
		for (int j=0;j<=l;j++) f[i][j][0]=f[i][j][1]=inf;
	for (int i=1;i<=n;i++){
		int le=read(), ri=read(), len=ri-le;
		for (int j=0;j<=l;j++){
			if (l-j>=len && f[i-1][j][1]<=le)
				f[i][j+len][1]=min(f[i][j+len][1],ri),
				f[i][j+len][0]=min(f[i][j+len][0],ri+1);
			if (j>=len && f[i-1][j][0]<=le)
				f[i][j-len][0]=min(f[i][j-len][0],ri),
				f[i][j-len][1]=min(f[i][j-len][1],ri+1);
		}
	}
	for (int j=0;j<=l;j++)
		if (f[n][j][0]<inf || f[n][j][1]<inf) return 1;
	return 0;
}
int main(){
	int ans=1;
	for (int _=read();_;_--) ans&=solve();
	if (ans) puts("possible");
	else puts("impossible");
    return 0;
}
