#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define N 200000
#define M 800000
using namespace std;
int cnt, n, m, top, tot, in[N], out[N], f[N], flag[N], dfn[N], low[N], co[N], stack[N], nex[M], nu[M];
int nex2[N], nu2[N];
double ans;
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
void add2(int u, int v){
	nex2[++cnt]=nex2[u];nex2[u]=cnt;nu2[cnt]=v;
}
void tarjan(int u){
	dfn[u]=low[u]=++cnt;
	flag[u]=1;
	stack[++top]=u;
	for (int j=nex[u];j;j=nex[j]){
		int v=nu[j];
		if (!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if (flag[v]) low[u]=min(low[u],dfn[v]);
	}
	if (dfn[u]==low[u]){
		co[stack[top]]=++tot;
		flag[stack[top]]=0;
		while (stack[top--]!=u) flag[stack[top]]=0, co[stack[top]]=tot;
	}
}
int main(){
	cnt=n=read();m=read();
	for (int i=1;i<=m;i++){
		int u=read(), v=read();
		add(u,v);
	}
	for (int i=1;i<=n;i++) if (!dfn[i]) tarjan(i);
	cnt=n;
	for (int i=1;i<=n;i++){
		int u=co[i];
		f[u]++;
		for (int j=nex[i];j;j=nex[j]){
			int v=co[nu[j]];
			if (v==u) continue;
			in[v]++;
			out[u]++;
			add2(u,v);
		}
	}
	for (int i=1;i<=tot;i++)
		if (!in[i]) ans++;
	for (int i=1;i<=tot;i++)
		if (!in[i] && f[i]==1){
			int flag=1;
			for (int j=nex2[i];j;j=nex2[j])
				if (in[nu2[j]]==1){
					flag=0;
					break;
				}
			if (flag){
				ans--;
				break;
			}
		}
	ans=(double)(n-ans)/n;
	printf("%.6lf\n", ans);
	return 0;
}
