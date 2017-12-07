#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define INF 1e8
#define list 11000
using namespace std;
int n, s, t, ss, st, cnt, l[11001], next[50000], nu[50000], va[50000], d[11001];
void add(int u, int v, int f){
	next[++cnt]=next[u];next[u]=cnt;nu[cnt]=v;va[cnt]=f;
	next[++cnt]=next[v];next[v]=cnt;nu[cnt]=u;va[cnt]=0;
}
bool bfs(){
	memset(d,-1,sizeof(d));
	d[ss]=0;l[1]=ss;
	int le=0, ri=1;
	while (le!=ri){
		le=le%list+1;
		int u=l[le], j=next[l[le]];
		//cout<<u<<' '<<d[u]<<endl;
		while (j){
			int v=nu[j];
			if (d[v]==-1 && va[j]){
				d[v]=d[u]+1;
				ri=ri%list+1;
				l[ri]=v;
				//if (v==st) return 1;
			}
			j=next[j];
		}
	}
	//cout<<(d[st]!=-1)<<endl;
	return d[st]!=-1;
}
int dfs(int u, int flow){
	if (u==st) return flow;
	int j=next[u], tmp;
	while (j){
		int v=nu[j];
		if (va[j] && d[v]==d[u]+1 && (tmp=dfs(v,min(flow,va[j])))){
			va[j]-=tmp;va[j^1]+=tmp;return tmp;
		}
		j=next[j];
	}
	return 0;
}
int dinic(){
	int ans=0, tmp;
	while (bfs())
		while (tmp=dfs(ss,INF)) ans+=tmp;
	return ans;
}
int main(){
	scanf("%d", &n);
	s=0;t=2*n+1;ss=t+1;st=t+2;
	cnt=st+(st+1)%2;
	for (int i=1;i<=n;i++){
		int k, x;
		if (i==n) k=0;else scanf("%d", &k);
		for (int j=1;j<=k;j++)
			scanf("%d", &x), add(i+n,x,INF), d[x]++;
		add(i,i+n,INF);
		add(i+n,st,k);
	}
	for (int i=1;i<=n;i++) add(ss,i,d[i]);
	add(s,1,INF);
	add(n*2,t,INF);
	dinic();
	add(t,s,INF);
	dinic();
	printf("%d\n", va[cnt]);
	return 0;
}
