#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define N 10000
#define M 50000
#define INF 1000000000
using namespace std;
int n, m ,cnt, s, t, nex[M], nu[M], va[M], w[M];
int dis[N], fl[N], fr[N], fr_edge[N], flag[N], l[N*10];
int read(){
	int p=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
void add(int u, int v, int flow, int cost){
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;va[cnt]=flow;w[cnt]=cost;
	nex[++cnt]=nex[v];nex[v]=cnt;nu[cnt]=u;va[cnt]=0;w[cnt]=-cost;
}
void __init(){
	n=read();m=read();
	cnt=(n+1)*2+1;
	s=2*n+1;t=2*n+2;
	for (int i=1;i<=n;i++){
		int x=read();
		add(s,i+n,1,x);
		add(s,i,1,0);
		add(i+n,t,1,0);
	}
	for (int i=1;i<=m;i++){
		int u=read(), v=read(), w=read();
		if (u>v) swap(u,v);
		add(u,v+n,1,w);
	}
}
bool spfa(){
	int le=0, ri=1;
	for (int i=1;i<=t;i++) dis[i]=INF, flag[i]=0;
	dis[l[1]=s]=0;
	flag[s]=1;
	while (le<ri){
		int u=l[++le];
		flag[u]=0;
		for (int j=nex[u];j;j=nex[j]){
			if (!va[j]) continue;
			int v=nu[j];
			if (dis[u]+w[j]<dis[v]){
				fr[v]=u;
				fl[v]=va[j];
				dis[v]=dis[u]+w[j];
				if (!flag[v]){
					flag[v]=1;
					l[++ri]=v;
				}
			}
		}
	}
	return dis[t]<INF;
}
int sub(){
	int j=t, mi=INF;
	while (j!=s) mi=min(mi,fl[j]), j=fr[j];
	j=t;
	while (j!=s){		
		va[fr_edge[j]]-=mi;
		va[fr_edge[j]^1]+=mi;
		j=fr[j];
	}
	return mi*dis[t];
}
void solve(){
	int ans=0;
	while (spfa()) ans+=sub();
	cout<<ans<<endl;
}
int main(){
	__init();
	solve();
	return 0;
}
