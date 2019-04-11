#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 1000
typedef long long ll;
using namespace std;
int n, m, fa, fb, a[N][N], b[N][N], c[N][N];
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') 
		ch=='-'?q=-1:0,
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
int main(){
	n=read();m=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) a[i][j]=read(), fa+=a[i][j];
	int fw=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) b[i][j]=read(), fb+=a[i][j], fw+=a[i][j]!=b[i][j], c[i][j]=a[i][j]^b[i][j];
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++)
			if (c[i][j])
				if (i<n && j<m) c[i][j]^=1, c[i+1][j]^=1, c[i][j+1]^=1, c[i+1][j+1]^=1;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) if (c[i][j]){
			cout<<"No"<<endl;
			return 0;
		}
	cout<<"Yes"<<endl;
	return 0;
}
