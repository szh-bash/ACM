#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
const int INF=1e8;
int ans, cnt, n, s, t, l, w, next[200000], nu[200000], va[200000], hd[1000], d[1000], x[300], y[300];
int sqr(int x){return x*x;}
bool f(int a, int b){return sqr(x[a]-x[b])+sqr(y[a]-y[b])<=40000;}
void add(int u, int v, int w){
	next[++cnt]=next[u];next[u]=cnt;nu[cnt]=v;va[cnt]=w;
	next[++cnt]=next[v];next[v]=cnt;nu[cnt]=u;va[cnt]=0;	
}
int sap(int x, int flow){
	if (x==t) return flow;
	int j=next[x], tp=flow, mind=n-1;
	while (j){
		int v=nu[j];
		if (d[x]==d[v]+1 && va[j]){
			int tmp=sap(v,min(flow,va[j]));
			va[j]-=tmp;
			va[j^1]+=tmp;
			flow-=tmp;
			if (d[s]>=n) return tp-flow;
			if (!flow) break;
		}
		if (va[j]) mind=min(mind,d[v]);
		j=next[j];
	}
	if (tp==flow){
		if (!--hd[d[x]]) d[s]=n;
		hd[d[x]=mind+1]++;
	}
	return tp-flow;
}
int main(){
	scanf("%d%d%d", &l, &w, &n);
	for (int i=1;i<=n;i++) scanf("%d%d", &x[i], &y[i]);
	cnt=t=n*2+2;s=t-1;cnt++;
	for (int i=1;i<=n;i++){
		add(i,i+n,1);
		if (y[i]<=100) add(s,i,INF);
		if (w-y[i]<=100) add(i+n,t,INF);
		for (int j=i+1;j<=n;j++)
			if (f(i,j)) add(i+n,j,INF),add(j+n,i,INF);
	}
	hd[0]=n=n*2+2;
	while (d[s]<n) ans+=sap(s,INF);
	printf("%d", ans);
	return 0;
}
