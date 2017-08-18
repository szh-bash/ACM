#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, m, q, cnt, fa[110000], p[110000];
int father(int x){return fa[x]==x?x:fa[x]=father(fa[x]);}
void add(int u, int v){
	next[++cnt]=next[u];next[u]=cnt;nu[cnt]=v;
}
void work(int u, int v){
	if (u==v) cout<<-1<<endl;
	
}
int main(){
	cin>>n>>m>>q;
	cnt=n;
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=m;i++){
		int u, v;
		scanf("%d%d", &u, &v);
		fa[father(u)]=father(v);
		add(u,v);
		add(v,u);
	}
	cnt=0;
	for (int i=1;i<=n;i++)
		if (!p[father(i)){
			p[fa[i]]=++cnt;
			dfs1()
			dfs2()
		}
	for (int i=1;i<=q;i++){
		int u, v;
		scanf("%d%d", &u, &v);
		work(fa[u],fa[v]);
	}
	return 0;
}
