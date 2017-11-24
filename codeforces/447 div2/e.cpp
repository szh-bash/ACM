#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define N 2000000
#define M 5000000
typedef unsigned long long ll;
using namespace std;
int n, m, s, flag[N], dfn[N], co[N], low[N], stack[N], top, cnt, ct;
int nex[M], nex2[M], nu[M], nu2[M], va[M],va2[M], l[N*40];
ll g[N], f[N], ans, dis[N], sum[N/10];
int read(){
	int p=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
void add(int u, int v, int k){
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;va[cnt]=k;
}
void add2(int u, int v, int k){
	nex2[++cnt]=nex2[u];nex2[u]=cnt;nu2[cnt]=v;va2[cnt]=k;
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
		} else if (flag[v]) low[u]=min(low[u],dfn[v]);
	}
	if (dfn[u]==low[u]){
		co[stack[top]]=++ct;
		flag[stack[top]]=0;
		while (stack[top--]!=u) flag[stack[top]]=0, co[stack[top]]=ct;
	}
}
ll getmr(int x){
	int le=0, ri=100000;
	while (le<ri-1){
		int mid=le+ri>>1;
		if (sum[mid]>x) ri=mid;else le=mid;
	}
	ll t=le;
	return (t+1)*x+g[t]-t*(t+1)*t/2;
}
int main(){
	for (int i=1;i<=50000;i++) g[i]=g[i-1]+(ll)(i-1)*i;
	for (int i=1;i<=100000;i++) sum[i]=sum[i-1]+i;
	//for (int i=1;i<=10;i++) cout<<getmr(i)<<endl;
	cnt=n=read();m=read();
	for (int i=1;i<=m;i++){
		int u=read(), v=read(), k=read();
		add(u,v,k);
	}
	cin>>s;
	tarjan(s);
	cnt=ct;
	for (int i=1;i<=n;i++){
		int u=co[i];
		for (int j=nex[i];j;j=nex[j]){
			int v=co[nu[j]];
			if (u==v) f[u]+=getmr(va[j]);
			else add2(u,v,va[j]);
		}
	}
	int le=0, ri=1;
	l[1]=s=co[s];
	flag[s]=1;
	dis[s]=f[s];
	while (le<ri){
		int u=l[++le];
		flag[u]=0;
		for (int j=nex2[u];j;j=nex2[j]){
			int v=nu2[j];
			if (dis[u]+va2[j]+f[v]>dis[v]){
				dis[v]=dis[u]+va2[j]+f[v];
				if (!flag[v]){
					l[++ri]=v;
					flag[v]=1;
				}
			}
		}
	}
	for (int i=1;i<=ct;i++) ans=max(ans,dis[i]);
	cout<<ans<<endl;
	return 0;
}
