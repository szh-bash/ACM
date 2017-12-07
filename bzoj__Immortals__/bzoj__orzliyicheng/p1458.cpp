#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
int s, t, cnt, n, m, k, ans2, a[200][200], hd[2000], d[2000], c[2000], x, y, l[2000], va[500000], next[500000], nu[500000], ans;
void add(int u, int v, int w){
	next[++cnt]=next[u];next[u]=cnt;nu[cnt]=v;va[cnt]=w;
	next[++cnt]=next[v];next[v]=cnt;nu[cnt]=u;va[cnt]=0;
}
int dfs(int x, int flow){
	if (x==t) return flow;
	int j=next[x], tp=flow, mind=t;
	while (j){
		int v=nu[j];
		if (d[x]==d[v]+1 && va[j]){
			int tmp=dfs(v,min(flow,va[j]));
			va[j]-=tmp;
			va[j^1]+=tmp;
			flow-=tmp;
			if (d[s]>t) return tp-flow;
			if (!flow) break;
		}
		if (va[j]) mind=min(mind,d[v]);
		j=next[j];
	}
	if (tp==flow){
		if (!--hd[d[x]]) d[s]=t+1, return tp-flow;
		hd[d[x]=mind+1]++;
	}
	return tp-flow;
}
void fail()
{
    puts("JIONG!");
    exit(0);
}
int main(){
	scanf("%d%d%d", &n, &m, &k);
	t=cnt=n+m+1;cnt+=(cnt+1)%2;
	for (int i=1;i<=n;i++) scanf("%d", &l[i]);
	for (int j=1;j<=m;j++) scanf("%d", &c[j]);
	for (int i=1;i<=k;i++) scanf("%d%d", &x, &y), a[x][y]=1;
	for (int i=1;i<=n;i++) 
		for (int j=1;j<=m;j++) 
	    	if (!a[i][j]) l[i]--,c[j]--, add(i,j+n,1), ans2++;
	for (int i=1;i<=n;i++) if (l[i]>0) fail();
	for (int j=1;j<=m;j++) if (c[j]>0) fail();
	for (int i=1;i<=n;i++) add(s,i,-l[i]);
	for (int j=1;j<=m;j++) add(j+n,t,-c[j]);
	hd[0]=t+1;
	while (d[s]<=t) ans+=dfs(s,1e8);
	cout<<ans2-ans<<endl;
	return 0;
}
