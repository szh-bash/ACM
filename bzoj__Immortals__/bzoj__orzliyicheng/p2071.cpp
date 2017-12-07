#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define INF 999999
#define N 60000*3
using namespace std;
int n, cnt, ans, nu[N], next[N], flag[N], tot, u, v, d[N];
void add(int u, int  v){
	next[++cnt]=next[u];next[u]=cnt;nu[cnt]=v;
}
void dfs1(int u){
	int j=next[u], tot=0;flag[u]=1;d[u]=0;
	while(j){
		int v=nu[j];
		if (!flag[v]){
			dfs1(v);
			d[u]=max(d[v],d[u]);
			tot++;
		}
		j=next[j];
	}
	++d[u];
}
void dfs(int u){ 
	int j=next[u], f1, f2=0, t;
	flag[u]=0;
	while (j){
		int v=nu[j];
		if (flag[v])
			if (d[v]>f1) f1=d[v], t=v;
				else if (d[v]>f2) f2=f1;
		j=next[j];
	}
	tot=max(tot,f2);
	if (f1>tot+1){tot++;dfs(t);}
	else ans=f1;
}
int main(){
	scanf("%d", &n);
	cnt=n;
	for (int i=1;i<n;i++){
		scanf("%d%d", &u, &v);
		add(u,v);add(v,u);
	}
	dfs1(1);
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
