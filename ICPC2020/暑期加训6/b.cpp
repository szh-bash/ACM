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
#define N 9
#define M 50000
int n, f[N], g[N][M][N];
int main(){
	n=read();
	f[1]=1;
	g[1][1][1]=1;
	for (int i=2;i<=n;i++){
		int cnt=0;
		for (int j=1, o=0;j<=f[i-1];j++, o^=1)
			if (o)
				for (int k=1;k<=i;k++){
					++cnt;
					for (int p=1, t=1;p<=i;p++)
						if (p!=k) g[i][cnt][p]=g[i-1][j][t++];
					g[i][cnt][k]=i;
				}
			else
				for (int k=i;k;k--){
					++cnt;
					for (int p=1, t=1;p<=i;p++)
						if (p!=k) g[i][cnt][p]=g[i-1][j][t++];
					g[i][cnt][k]=i;
				}
		f[i]=cnt;
	}
	for (int i=1;i<=f[n];i++)
		for (int j=1;j<=n;j++) printf("%d%s", g[n][i][j], (j==n?"\n":" "));
    return 0;
}
