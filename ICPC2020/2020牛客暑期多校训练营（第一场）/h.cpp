#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <tr1/unordered_map>
#define num(x) (x>='0' && x<='9')
#define N 10000
#define M 50000
#define INF 1000000000
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int n, m ,cnt, s, t, nex[M], nu[M], va[M], w[M];
int dis[N], fl[N], fr[N], fr_edge[N], flag[N], l[N*10];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
void add(int u, int v, int flow, int cost){
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;va[cnt]=flow;w[cnt]=cost;
	nex[++cnt]=nex[v];nex[v]=cnt;nu[cnt]=u;va[cnt]=0;w[cnt]=-cost;
}
void __init(){
	s=1;t=n;
	cnt=n+((n&1)^1);
	for (int i=1;i<=cnt;i++) nex[i]=0;
	for (int i=1;i<=m;i++){
		int u=read(), v=read(), w=read();
		add(u,v,1,w);
	}
}
bool spfa(){
	int le=0, ri=1;
	for (int i=1;i<=t;i++) dis[i]=INF, flag[i]=0;
	dis[l[1]=s]=0;
	flag[s]=1;
	while (le<ri){
//		cout<<le<<endl;
		int u=l[++le];
//		cout<<le<<' '<<u<<' '<<dis[1]<<' '<<dis[2]<<endl;
		flag[u]=0;
		for (int j=nex[u];j;j=nex[j]){
			if (!va[j]) continue;
			int v=nu[j];
			if (dis[u]+w[j]<dis[v]){
				fr[v]=u;
				fr_edge[v]=j;
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
ll ans[M], pre[M];
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
void solve(){
//	cout<<"hahahaha"<<endl;
	__init();
	int ct=0;
	while (spfa()) {
		ans[++ct]=sub();
		pre[ct]=pre[ct-1]+ans[ct];
//		cout<<ct<<endl;
	}
//	for (int i=1;i<=ct;i++) cout<<i<<' '<<ans[i]<<endl;
	for (int q=read();q;q--){
		int u=read(), v=read();
		if (!u) {puts("NaN");continue;}
		int k=v/u;
		if (k+(v>u*k)<=ct){
			ll y=pre[k]*u+ans[k+1]*(v%u), x=v;
			ll gys=gcd(y,x);
			y/=gys;
			x/=gys;
			printf("%lld/%lld\n", y, x);			
		}
		else puts("NaN");
	}
}
int main(){
	while (~scanf("%d%d", &n, &m)) solve();
    return 0;
}
