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
typedef long long ll;
using namespace std;
#define N 50005 
#define M 15
int n, m=5, ma[M], g[M], ct;
int a[N][M], c[N], ans[N][M], num[N];
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') 
		ch=='-'?q=-1:0,
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
bool cmp(int x, int y){
	return a[x][g[1]]<a[y][g[1]];
}
void solve(){
	n=read();
	for (int j=1;j<=m;j++) ma[j]=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) 
			a[i][j]=read(), 
			ma[j]=max(ma[j], a[i][j]);
	int T=(1<<m)-1;
	ct=0;
	for (int i=0;i<T;i++){
		int cnt=0;
		for (int j=0;j<m;j++)
			if (i&(1<<j))
				g[++cnt]=j+1;
		if (cnt!=3) continue;
		++ct;
		// cout<<ct<<' '<<i<<endl;
		for (int j=1;j<=n;j++) num[j]=j;
		for (int j=1;j<=ma[g[2]];j++) c[j]=N+1;
		sort(num+1,num+1+n,cmp);
		for (int k=1;k<=n;k++){
			int v=num[k];
			int mi=N+1;
			for (int j=a[v][g[2]];j;j-=j&(-j)) mi=min(c[j],mi);
			for (int j=a[v][g[2]];j<=ma[g[2]];j+=j&(-j)) c[j]=min(c[j],a[v][g[3]]);
			if (mi>a[v][g[3]]) ans[v][ct]=1;
			else ans[v][ct]=0;
			// cout<<n<<' '<<i<<' '<<k<<' '<<mi<<' '<<g[2]<<' '<<ma[g[2]]<<endl;
		}
	}
	for (int i=1;i<=n;i++){
		int flag=1;
		for (int j=1;j<=ct;j++) flag&=ans[i][j];
		if (flag){
			printf("%d\n", i);
			return;
		}
	}
	puts("-1");
}
int main(){
	for (int _=read();_;_--) solve();
	return 0;
}
