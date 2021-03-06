#include<iostream>  
#include<cstdlib>  
#include<cstdio>  
#include<cstring>  
#include<ctime>  
#include<cmath>  
#include<algorithm>  
#include<iomanip>  
#include<queue>  
#include<map>  
#include<bitset>  
#include<stack>  
#include<vector>  
#include<set>  
#define N 500050 
#define M 1048576
#define mo 1000000007
typedef long long ll;
using namespace std;
int n, d, p, a[N], g[M], f[10][M];
int read(){
	int p=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
int main(){
	n=read();d=read();
	for (int i=1;i<=n;i++) p^=a[i]=read();
	sort(a+1,a+1+n);
	f[0][0]=1;
	for (int i=1;i<=n;i++){
		for (int j=0;j<M && j<=a[i]*2;j++){
			g[j]=f[0][j]+f[d-1][j^a[i]];
			if (g[j]>=mo) g[j]-=mo;
		}
		for (int k=d-1;k;k--){
			for (int j=0;(j<M)&&(j<=a[i]*2);j++){
				f[k][j]+=f[k-1][j^a[i]];
				if (f[k][j]>=mo) f[k][j]-=mo;
			}
		}
		for (int j=0;j<M && j<=a[i]*2;j++) f[0][j]=g[j];
	}
	if (n%d==0) (f[0][p]+=mo-1)%=mo;
	cout<<f[0][p]<<endl;
	return 0;
}
