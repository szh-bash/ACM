#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int f[1800][1800], flag[1800][1800], n, m, a[1800][1800];
int work(int x, int y){
	if (flag[x][y]) return 0;
	if (f[x][y]) return f[x][y];
	int t=0;
	if (x>1 && a[x-1][y]<a[x][y]) t=max(t,work(x-1,y));
	if (y>1 && a[x][y-1]<a[x][y]) t=max(t,work(x,y-1));
	if (x<n && a[x+1][y]<a[x][y]) t=max(t,work(x+1,y));
	if (y<n && a[x][y+1]<a[x][y]) t=max(t,work(x,y+1));
	return f[x][y]=t+1;
}
int solve(){
	memset(f,0,sizeof(f));
	int ans=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++){
			if (!f[i][j] && !flag[i][j]) work(i,j);
			ans=max(ans,f[i][j]);
		}
	return ans;
}
int main(){
	scanf("%d", &n);
	for (int i=1;i<=n;i++) 
		for (int j=1;j<=n;j++) scanf("%d", &a[i][j]);
	scanf("%d", &m);
	while (m){
		m--;
		getchar();
		char c=getchar();
		int x, y, z, x1, x2, y1, y2;
		if (c=='C'){
			scanf("%d%d%d", &x, &y, &z);
			a[x][y]=z;
		} 
		if (c=='S'){
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			for (int i=x1;i<=x2;i++)
				for (int j=y1;j<=y2;j++) flag[i][j]=1;
		}
		if (c=='B'){
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			for (int i=x1;i<=x2;i++)
				for (int j=y1;j<=y2;j++) flag[i][j]=0;
		}
		if (c=='Q') printf("%d\n", solve());
	}
	return 0;
}
