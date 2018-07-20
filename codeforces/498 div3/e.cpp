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
#define N 1000000
typedef long long ll;
using namespace std;
int cnt, n, k, le[N], ri[N], dfn[N], nex[N], nu[N], p[N];
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') 
		ch=='-'?q=-1:0,
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
void add(int u, int v){
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;
}
void dfs(int u){
	le[u]=++cnt;
	dfn[cnt]=u;
	for (int j=nex[u];j;j=nex[j]) dfs(nu[j]);
	ri[u]=cnt;
}
int main(){
	cnt=n=read();k=read();
	for (int i=1;i<n;i++) p[i+1]=read();
	for (int i=n;i>1;i--) add(p[i],i);
	cnt=0;
	dfs(1);
	for (int i=1;i<=k;i++){
		int x=read(), y=read();
		if (ri[x]-le[x]+1<y) printf("-1\n");
		else printf("%d\n", dfn[le[x]+y-1]);
	}
	return 0;
}
