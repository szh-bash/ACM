#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;
int n;
int read(){
	int p=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
void dfs(int x, int y, int z){
	if (!x || x>n || !y || y>n) return;
	if (z==3){
	}
	for (int i=1;i<=4;i++)
		dfs(x+b[i],y+c[i],z+1);
		
}
int main(){
	n=read();m=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) 	a[i][j]=read();
	dfs(1,1,0);
	cout<<min(f[n][n][0],min(f[n][n][1],f[n][n][2]))<<endl;
	return 0;
}
