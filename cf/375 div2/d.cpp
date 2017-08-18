#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, tot, ans, k, a[100][100], f[100][100], cnt ,b[10000], flag[100000], q[100][100];
char s[100];
void dfs(int x, int y){
	if (!a[x][y] || !x || !y || x>n || y>m || f[x][y]) return;
	f[x][y]=1;
	tot++;
	dfs(x-1,y);
	dfs(x+1,y);
	dfs(x,y+1);
	dfs(x,y-1);
}
void dfs2(int x, int y){
	if (!a[x][y] || !x || !y || x>n || y>m) return;
	a[x][y]=0;
	dfs2(x-1,y);
	dfs2(x+1,y);
	dfs2(x,y+1);
	dfs2(x,y-1);
}
void dfs3(int x, int y){
	if (a[x][y]!=1 || !x || !y || x>n || y>m) return;
	a[x][y]=-1;
	dfs3(x-1,y);
	dfs3(x+1,y);
	dfs3(x,y+1);
	dfs3(x,y-1);
}
int cmp(int a, int b){return a>b;}
int main(){
	cin>>n>>m>>k;
	for (int i=1;i<=n;i++){
		scanf("%s", s);
		for (int j=0;j<m;j++)
			a[i][j+1]=s[j]=='.';
	}
	for (int i=1;i<=n;i++){
		if (a[i][1]==1) dfs3(i,1);
		if (a[i][m]==1) dfs3(i,m);
	}
	for (int i=1;i<=m;i++){
		if (a[1][i]==1) dfs3(1,i);
		if (a[n][i]==1) dfs3(n,i);
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (!f[i][j] && a[i][j]==1) tot=0, dfs(i,j), q[i][j]=tot, b[++cnt]=tot;
	sort(b+1,b+1+cnt, cmp);
	for (int i=k+1;i<=cnt;i++) flag[b[i]]++;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (flag[q[i][j]]) ans+=q[i][j], flag[q[i][j]]--, dfs2(i,j);
	cout<<ans<<endl;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) cout<<(a[i][j]==1 || a[i][j]==-1 ?'.':'*');
		cout<<endl;
	}
	return 0;
}
