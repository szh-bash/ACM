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
int n, m, a[N][N], b[N][N], q[N], p[N];
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
		for (int j=1;j<=m;j++) a[i][j]=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) b[i][j]=read();
	for (int k=1;k<=n+m;k++){
		int ct=0;
		for (int j=1;j<=k && j<=m;j++)
			if (k-j+1<=n) p[++ct]=a[k-j+1][j], q[ct]=b[k-j+1][j];
		sort(p+1,p+1+ct);
		sort(q+1,q+1+ct);
		for (int j=1;j<=ct;j++) if (p[j]!=q[j]) {cout<<"NO"<<endl; return 0;}
	}
	cout<<"YES"<<endl;
	return 0;
}
