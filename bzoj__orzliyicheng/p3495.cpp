#include <map>
#include <cmath>
#include <ctime>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 8000005
#define M 30*1000000
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int n, m, k, ct, cnt, tot, dfn[N], low[N], flag[N], stack[N], nex[M], nu[M], co[N], top;
int read(){
	int p=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
void add(int u, int v){
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;
}
void tarjan(int u){
	dfn[u]=low[u]=++ct;
	stack[++top]=u;
	flag[u]=1;
	for (int j=nex[u];j;j=nex[j]){
		int v=nu[j];
		if (!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else
			if (flag[v]) low[u]=min(low[u],dfn[v]);
	}
	if (low[u]==dfn[u]){
		co[stack[top]]=++tot;
		while (stack[top--]!=u) co[stack[top]]=tot;
	}
	flag[u]=0;
}
int main(){
	n=read();m=read();k=read();
	cnt=n*4;
	for (int i=1;i<=m;i++){
		int u=read(), v=read();
		add(u+n,v);
		add(v+n,u);
	}
	for (int i=1;i<=k;i++){
		int v=0, u=0;
		for (int _=read();_;_--){
			u=read();
			add(u,u+n*2);
			add(u+n*3,u+n);
			if (v)
				add(v+n*2,u+n*2),
				add(u+n*3,v+n*3),
				add(v+n*2,u+n),
				add(u,v+n*3);
			v=u;
		}
	}
	for (int i=1;i<=n*4;i++)
		if (!dfn[i]) tarjan(i);
//	for (int i=1;i<=n*4;i++)
//		cout<<i<<' '<<co[i]<<endl;
	for (int i=1;i<n;i++)
		if (co[i]==co[i+n] || co[i+n*2]==co[i+n*3]) return printf("NIE"), 0;
	printf("TAK");
	return 0;
}

