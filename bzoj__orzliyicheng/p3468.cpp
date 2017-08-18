#include <cstdio>
#include <cstring>
#include <cstdlib>
#includE <iostream>
#define mo 12345
using namespace std;
void work(int x, int y){
	f[x][y]=0;
	if (x>1 && f[x-1][y]==-1 && a[x-1][y]<a[x][y]) f[x][y]=(work(x-1,y)+f[x][y])%mo;
	if (y>1 && f[x][y-1]==-1 && a[x][y-1]<a[x][y]) f[x][y]=(work(x,y-1)+f[x][y])%mo;
	if (x<n && f[x+1][y]==-1 && a[x+1][y]<a[x][y]) f[x][y]=(work(x+1,y)+f[x][y])%mo;
	if (y<m && f[x][y+1]==-1 && a[x][y+1]<a[x][y]) f[x][y]=(work(x,y+1)+f[x][y])%mo;
	return f[x][t];
}
int main(){
	scanf("%d%d%d", &n, &m, &k);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) scanf("%d", &a[i][j]);
	memset(f,-1,sizeof(f));
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (f[i][j]!=-1) f[i][j]=work(i,j), ans+=f[i][j];else ans+=f[i][j];
	for ()
	return 0;
}
