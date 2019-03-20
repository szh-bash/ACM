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
#include <tr1\\unordered_map>
#define N 1005
typedef long long ll;
using namespace std;
using namespace std::tr1;
int a[N][N], b[N], fx[N][N], fy[N][N], ctx[N], cty[N];
int n, m;
unordered_map<int, int> mp;
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
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) b[j]=a[i][j];
		sort(b+1,b+1+m);
		int cnt=0;
		mp.clear();
		for (int j=1;j<=m;j++)
			if (b[j]!=b[j-1]) mp[b[j]]=++cnt;
		for (int j=1;j<=m;j++) fx[i][j]=mp[a[i][j]];
		ctx[i]=cnt;
	}
	for (int j=1;j<=m;j++){
		for (int i=1;i<=n;i++) b[i]=a[i][j];
		sort(b+1,b+1+n);
		int cnt=0;
		mp.clear();
		for (int i=1;i<=n;i++)
			if (b[i]!=b[i-1]) mp[b[i]]=++cnt;
		for (int i=1;i<=n;i++) fy[i][j]=mp[a[i][j]];
		cty[j]=cnt;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			printf("%d%s", max(fx[i][j],fy[i][j])+max(ctx[i]-fx[i][j],cty[j]-fy[i][j]),(j==m?"\n":" "));
	return 0;
}
