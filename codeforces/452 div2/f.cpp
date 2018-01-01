#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define N 200050
using namespace std;
int n, m, cnt, mp[200], g[150][N], flag[150][N];
char s[N], ans[N], ch[200];
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9')
		(ch=='-'?q=-1:0),
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
int main(){
	n=read();m=read();
	scanf("%s", s+1);
	for (int i=1;i<=n;i++){
		if (!mp[s[i]]){
			mp[s[i]]=++cnt;
			ch[cnt]=s[i];
		}
		int u=mp[s[i]];
		g[u][++g[u][0]]=i;
	}
	for (int i=1;i<=m;i++){
		int x=read(), y=read();
		scanf("%s", s);
		int u=mp[s[0]], l=0, r=g[u][0]+1;
		if (!g[u][0]) continue;
		g[u][g[u][0]+1]=n+1;
		while (l<r-1){
			int mid=l+r>>1;
			if (g[u][mid]<x) l=mid;
			else r=mid;
		}
		x=r;
		//if (g[u][r]>x) x=r-1;else x=r;
		l=0;r=g[u][0]+1;
		while (l<r-1){
			int mid=l+r>>1;
			if (g[u][mid]<=y) l=mid;
			else r=mid;
		}
		y=l;
		//if (g[u][l]<y) y=l+1;else y=l;
		if (x<=y) flag[u][x]--, flag[u][y+1]++;
		cout<<x<<' '<<y<<' '<<s[0]<<' '<<u<<endl;
	}
	for (int i=1;i<=cnt;i++){
		int t=1;
		for (int j=1;j<=g[i][0];j++){
			t+=flag[i][j];
			if (t>0) ans[g[i][j]]=ch[i];
		}
	}
	for (int i=1;i<=n;i++)
		if (ans[i]) printf("%c", ans[i]);cout<<endl;
	return 0;
}
