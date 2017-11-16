#include <map>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define N 100000
using namespace std;
int n, m, cnt, tot, top, flag[N], nex[N], nu[N], dfn[N], low[N], stack[N], co[N];
map <string, int> mp;
char female[10], male[10];
void add(int u, int v){
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;
}
void tarjan(int u){
	dfn[u]=low[u]=cnt++;
	flag[u]=1;
	stack[++top]=u;
	for (int j=nex[u];j;j=nex[j]){
		int v=nu[j];
		if (!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(flag[v]) low[u]=min(low[u],dfn[v]);//

	}
	if (dfn[u]==low[u]){
		co[stack[top]]=++tot;
		flag[stack[top]]=0;
		while (stack[top--]!=u) flag[stack[top]]=0, co[stack[top]]=tot;
	}
}
int main(){
	cin>>n;
	cnt=n*2;
	for (int i=1;i<=n;i++){
		scanf("%s %s", female, male);
		mp[female]=2*i-1;
		mp[male]=2*i;
		add(2*i-1,2*i);
	}
	cin>>m;
	for (int i=1;i<=m;i++){
		scanf("%s %s", female, male);
		int u=mp[female], v=mp[male];
		add(v,u);
	}
	for (int i=1;i<=2*n;i++) if (!dfn[i]) tarjan(i);
	for (int i=1;i<=n;i++)
		if (co[i*2-1]==co[i*2]) printf("Unsafe\n");else printf("Safe\n");
	return 0;
}
