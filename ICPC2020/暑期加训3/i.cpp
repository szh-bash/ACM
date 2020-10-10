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
#define inf 1e15
#define N 152
int a[N], b[N];
ll f[N][N][N][2], g[N][N][N][2];
void solve(){
	int n=read(), A=read(), B=read(), sum=0;
	for (int i=1;i<=n;i++) a[i]=read(), b[i]=read(), sum+=b[i];
	for (int i=0;i<=n;i++)
		for (int ia=0;ia<=sum;ia++)
			for (int ib=0;ib+ia<=sum;ib++)
				for (int k=0;k<2;k++) f[i][ia][ib][k]=-inf;
	f[0][0][0][0]=A-B;
	for (int i=1;i<=n;i++)
		for (int ia=0;ia<=sum;ia++)
			for (int ib=0;ib+ia<=sum;ib++)
				for (int k=0;k<2;k++){
					ll w=f[i-1][ia][ib][k];
					if (w>-inf){
						cout<<i<<' '<<ia<<' '<<ib<<' '<<k<<' '<<w<<' '<<a[i]<<' '<<b[i]<<endl;
						if (!k){
							if (w>0 && i<n) 
								f[i+1][ia+b[i+1]][ib+b[i]][k^1]=max(f[i+1][ia+b[i+1]][ib+b[i]][k^1],
																-w+a[i]+1-a[i+1]);
							f[i][ia+b[i]][ib][k^1]=max(f[i][ia+b[i]][ib][k^1],-w-a[i]);
						}
						else{
							if (w>0 && i<n) 
								f[i+1][ia+b[i]][ib+b[i+1]][k^1]=max(f[i+1][ia+b[i]][ib+b[i+1]][k^1],
																-w+a[i]+1-a[i+1]);
							f[i][ia][ib+b[i]][k^1]=max(f[i][ia][ib+b[i]][k^1],-w-a[i]);
						}
					}
				}
//	for (int i=sum, flag=0;i>=0 && !flag;i--)
//		for (int j=0;j<2;j++)
//			if (f[n][i][sum-i][j]>-inf){
//				printf("%d %d\n", i, sum-i);
//				flag=1;
//				break;
//			}
	for (int i=sum;i>=0;i--)
		for (int j=0;j<2;j++)
			if (f[n][i][sum-i][j]>-inf)
				g[n][i][sum-i][j]=j?sum-i:i;
			else g[n][i][sum-i][j]=-inf;
	for (int i=n-1;i>=0;i--)
		for (int ia=0;ia<=sum;ia++)
			for (int ib=0;ib+ia<=sum;ib++)
				for (int k=0;k<2;k++){
					ll w=f[i][ia][ib][k];
					g[i][ia][ib][k]=-inf;
					if (w>-inf){
						if (!k){
							if (w>0 && i<n)
								g[i][ia][ib][k]=max(g[i][ia][ib][k],sum-g[i+1][ia+b[i]][ib+b[i+1]][k^1]);
							g[i][ia][ib][k]=max(g[i][ia][ib][k],sum-g[i+1][ia][ib+b[i]][k^1]);
						}
						else{
							if (w>0 && i<n)
								g[i][ia][ib][k]=max(g[i][ia][ib][k],sum-g[i+1][ia+b[i+1]][ib+b[i]][k^1]);
							g[i][ia][ib][k]=max(g[i][ia][ib][k],sum-g[i+1][ia+b[i]][ib][k^1]);
						}
					}
				}
	cout<<g[0][0][0][0]<<' '<<sum-g[0][0][0][0]<<endl;
}
int main(){
	solve();
    return 0;
}
/*
5 1000000000 0
1000000000 1
0 50
0 1
0 1
0 50
*/
