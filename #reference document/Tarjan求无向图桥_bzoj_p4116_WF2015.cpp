#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 2010
using namespace std;
int n, m, cnt, ans, dfn[N], low[N], flag[N], bridge[N], nu[N*3], num[N*3], nex[N*3];
int vis[N], x[N], y[N];
int read(){
	int p=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
void add(int u, int v, int n){
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;num[cnt]=n;
}
void initialize(){
	cnt=n+n%2+1;
	for (int i=1;i<=n;i++) nex[i]=dfn[i]=low[i]=0;
	for (int i=1;i<=m;i++) bridge[i]=0;
}
void tarjan(int u, int from){
	dfn[u]=low[u]=++cnt;
	for (int j=nex[u];j;j=nex[j])
		if (j^from^1){
			int v=nu[j];
			if (dfn[v]) low[u]=min(low[u],dfn[v]);
			else{
				tarjan(v,j);
				low[u]=min(low[u],low[v]);
				bridge[num[j]]=low[v]>dfn[u];
			}
		}
}
int gcd(int a, int b){return b?gcd(b,a%b):a;}
int main(){
	n=read();m=read();
	cnt=n+n%2+1;
	for (int i=1;i<=m;i++){
		int u=x[i]=read(), v=y[i]=read();
		add(u,v,i);
		add(v,u,i);
	}
	for (int i=1;i<=n;i++)
		if (!dfn[i]) tarjan(i,0);
	for (int i=1;i<=m;i++) flag[i]=bridge[i];
	for (int i=1;i<=m;i++)
		if (!vis[i] && !flag[i]){
			initialize();
			vis[i]=1;
			int tot=1;
			for (int j=1;j<=m;j++)
				if (j!=i) add(x[j],y[j],j),add(y[j],x[j],j);
			for (int j=1;j<=n;j++)
				if (!dfn[j]) tarjan(j,0);
			for (int j=1;j<=m;j++)
				if (bridge[j] && !flag[j]) tot++, vis[j]=1;
			ans=gcd(ans,tot);
		}
	for (int i=1;i<=ans;i++)
		if (ans%i==0) printf("%d%c", i, i==ans?'\n':' ');
	return 0;
}
