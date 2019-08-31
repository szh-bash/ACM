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
#define N 2000
typedef long long ll;
using namespace std;
int n, a[N][N];
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
int main(){
	n=read();
	int cnt=0;
	for (int i=1;i<=n/4;i++)
		for (int j=1;j<=n/4;j++)
			for (int p=1;p<=4;p++)
				for (int q=1;q<=4;q++)
					a[(i-1)*4+p][(j-1)*4+q]=cnt++;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) printf("%d%s", a[i][j], j==n?"\n":" ");
	return 0;
}
