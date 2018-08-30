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
#define N 5000
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int n;
double yy1[N], yy2[N], c[N][N], x[N], tx[N];
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
	n=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			c[i][j]=read();
	for (int i=1;i<=n;i++) yy1[i]=read();
	for (int i=1;i<=n;i++) yy2[i]=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			yy1[i]+=c[i][j];
	int T=100000000/n/n;
	while (T--){
		for (int i=1;i<=n;i++){
			x[i]=0;
			for (int j=1;j<=n;j++)
				x[i]+=yy2[j]/yy1[j]*c[i][j];
		}
		for (int i=1;i<=n;i++) yy2[i]+=x[i]-tx[i], tx[i]=x[i];
	}
	for (int i=1;i<=n;i++) printf("%lf ", yy2[i]);
    return 0;
}
/*
3
1 10 1
11 1 1
1 12 1
10000000 20000000 20000000
30000000 20000000 30000000
*/










