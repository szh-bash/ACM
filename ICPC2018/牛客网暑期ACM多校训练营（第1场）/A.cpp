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
#define N 1000
#define M 1000
#define mo 1000000007
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int n, m;
ll f[N+5][M+5][5];
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
	f[1][1][0]=f[1][1][1]=f[1][1][2]=1;
	for (int i=2;i<=N;i++)
		for (int k=0;k<3;k++)
			for (int p=0;p<=k;p++)
				f[1][i][k]=(f[1][i][k]+f[1][i-1][p])%mo,
				f[i][1][k]=(f[i][1][k]+f[i-1][1][p])%mo;
	for (int i=2;i<=N;i++)
		for (int j=2;j<=M;j++)
			for (int k=0;k<3;k++)
				for (int p=0;p<=k;p++)
					for (int q=0;q<=k;q++)
						f[i][j][k]=(f[i][j][k]+f[i-1][j][p]*f[i][j-1][q])%mo;
	while (~scanf("%d%d", &n, &m)){
		printf("%d\n", (f[n][m][0]+f[n][m][1]+f[n][m][2])%mo);
	}
    return 0;
}
