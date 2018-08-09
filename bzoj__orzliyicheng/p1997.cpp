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
#define N 8005
#define M 60*10000
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int n, m, k, ct, cnt, tot, f[N], g[N], u[M], v[M], insta[N], dfn[M], low[M], flag[M], stack[M], nex[M], nu[M], co[M], top;
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
	insta[u]=1;
	stack[++top]=u;
	flag[u]=1;
	for (int j=nex[u];j;j=nex[j]){
		int v=nu[j];
		if (!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else
			if (insta[v]) low[u]=min(low[u],dfn[v]);
	}
	if (low[u]==dfn[u]){
		co[stack[top]]=++tot;
		insta[stack[top]]=0;
		while (stack[top--]!=u) co[stack[top]]=tot, insta[stack[top]]=0;
	}
	flag[u]=0;
}
bool cross(int x, int y){
	int u1=f[u[x]], v1=f[v[x]], u2=f[u[y]], v2=f[v[y]];
	if (u1>v1) swap(u1,v1);
	if (u2>v2) swap(u2,v2);
	if (u1>u2)
		swap(u1,u2),
		swap(v1,v2);
	return u1<u2 && u2<v1 && v1<v2;
}
int main(){
	for (int _=read();_;_--){ 
		n=read();m=read();
		cnt=m*2;
		for (int i=1;i<=cnt;i++) nex[i]=dfn[i]=low[i]=0;
		for (int i=1;i<=m;i++)
			u[i]=read(),
			v[i]=read();
		for (int i=1;i<=n;i++) g[i]=read(), f[g[i]]=i;
		if (m>3*n-6) {puts("NO");continue;}
		for (int i=1;i<=m;i++)
			for (int j=i+1;j<=m;j++)
				if (cross(i,j))
					add(i,j+m),
					add(i+m,j),
					add(j,i+m),
					add(j+m,i);
		for (int i=1;i<=m*2;i++)
			if (!dfn[i]) tarjan(i);
		int flag=1;
		for (int i=1;i<=m;i++)
			if (co[i]==co[i+m]) flag=0;
		if (flag) puts("YES");
		else puts("NO");
	}
	return 0;
}

