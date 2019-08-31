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
pair <int, int> rout;
int dfs(int x, int y){
	y%=m[x];
	if (flag[x*20+y]) return cnt+1-flag[x*20+y];
	l[flag[x*20+y]=++cnt]=x*n+y;
	dfs(e[x][(y+k[x])%m[x]],(y+k[x])%m[x]);
}
int calc(int x, int y){
	dfs(x,y);
}
int main(){
	n=read();
	for (int i=1;i<=n;i++) k[i]=read();
	for (int i=1;i<=n;i++){
		m[i]=read();
		k[i]%=m[i];
		for (int j=1;j<=m[i];j++) e[i][j]=read();
	}
	for (int i=1;i<=n;i++)
		for (int j=0;j<m[i];j++)
			ans[i][j]=calc(i,j);
	return 0;
}
