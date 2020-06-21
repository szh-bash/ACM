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
#define N 5005
#define M 500000
int cnt, n, m, n1, n2, n3;
int nex[M], nu[M];
int flag[N], c[N];
int f[N], g[N][2], tg[N][N], sum[N];
void add(int u, int v){
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;
}
int check(int u){
	flag[u]=cnt;
	g[cnt][c[u]]++;
	for (int j=nex[u];j;j=nex[j]){
		int v=nu[j];
		if (!flag[v]){
			c[v]=c[u]^1;
			if (check(v)) return 1;
		}
		else if (c[v]==c[u]) return 1;
	}
	return 0;
}
int main(){
	cnt=n=read(), m=read();
	n1=read(), n2=read(), n3=read();
	for (int i=1;i<=m;i++){
		int u=read(), v=read();
		add(u,v);
		add(v,u);
	}
	cnt=0;
	for (int i=1;i<=n;i++)
		if (!flag[i]){
			cnt++;
			if (check(i)) {
				puts("NO");
				return 0;
			}
		}
	f[0]=1;
	for (int i=1;i<=cnt;i++)
		for (int j=n2;j>=0;j--){
			if (j>=g[i][0] && f[j-g[i][0]]==i)
				f[j]=i+1,
				tg[j][i]=0;
			if (j>=g[i][1] && f[j-g[i][1]]==i) 
				f[j]=i+1,
				tg[j][i]=1;
		}
	if (f[n2]==cnt+1){
		for (int i=cnt, j=n2;i;i--)
			tg[0][i]=tg[j][i],
			j-=g[i][tg[j][i]];
		puts("YES");
		for (int i=1;i<=n;i++)
			if (tg[0][flag[i]]==c[i]) printf("2");
			else if (n1) printf("1"), n1--;
			else printf("3");
		cout<<endl;
	}
	else puts("NO");
	return 0;
}
