#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define N 10000
#define M 50000
#define mo N*9
#define INF 1000000000
using namespace std;
int n, m ,cnt, s, t, nex[M], nu[M], va[M], w[M];
int dis[N], fl[N], fr[N], flag[N], l[N*10];
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
	cnt=n*2+1;
	s=1;t=n*2;
	for (int i=1;i<=cnt;i++) nex[i]=0;
	for (int i=2;i<n;i++)
		add(i,i+n,1,0);
	add(1,n+1,2,0);
	add(n,n*2,2,0);
	for (int i=1;i<=m;i++){
		int a=read(), b=read(), c=read();
		add(a+n,b,1,c);
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
		for (int k=nex[fr[j]];k;k=nex[k])
			if (nu[k]==j){
				va[k]-=mi;
				va[k^1]+=mi;
				break;
			}
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
	while (~scanf("%d%d", &n, &m)){
		__init();
		solve();
	}
	return 0;
}
/*
6 11
1 2 23
1 3 12
1 4 99
2 5 17
2 6 73
3 5 3
3 6 21
4 6 8
5 2 33
5 4 5
6 5 20
*/
