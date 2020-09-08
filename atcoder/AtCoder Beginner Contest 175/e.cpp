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
#define N 3005
ll f[N][N][4];
int r, c, k, a[N][N];
int main(){
	r=read(), c=read(), k=read();
	for (int i=1;i<=k;i++){
		int x=read(), y=read();
		a[x][y]=read();
	}
	for (int i=1;i<=r;i++)
		for (int j=1;j<=c;j++){
			for (int k=0;k<=3;k++){
				f[i][j][k]=max(f[i-1][j][3], f[i][j-1][k]);
				if (k)
					f[i][j][k]=max(f[i][j][k], f[i][j-1][k-1]+a[i][j]),
					f[i][j][k]=max(f[i][j][k], f[i-1][j][3]+a[i][j]);
			}
		}
	cout<<f[r][c][3]<<endl;
    return 0;
}
