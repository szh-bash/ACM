#include <map>
#include <set> 
#include <ctime>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=='-'?q=-1:0, ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
ll readll(){
	ll p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=='-'?q=-1:0, ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
#define N 205
int g[3][N], f[N][N][N], l[3];
bool cmp(int a, int b){return a>b;}
void solve(){
	for (int i=0;i<3;i++)
		l[i]=read();
	for (int i=0;i<3;i++){
		for (int j=1;j<=l[i];j++) g[i][j]=read();
		sort(g[i]+1,g[i]+1+l[i]);
	}
	for (int i=0;i<=l[0];i++)
		for (int j=0;j<=l[1];j++)
			for (int k=0;k<=l[2];k++)
			if ((!i)+(!j)+(!k)<2){
				f[i][j][k]=0;
				if (i&&j) f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+g[0][i]*g[1][j]);
				if (i&&k) f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+g[0][i]*g[2][k]);
				if (j&&k) f[i][j][k]=max(f[i][j][k],f[i][j-1][k-1]+g[1][j]*g[2][k]);
//				cout<<i<<' '<<j<<' '<<k<<' '<<f[i][j][k]<<endl;
			}
	printf("%d\n", f[l[0]][l[1]][l[2]]);
}
int main(){
	solve();
	return 0;
}
