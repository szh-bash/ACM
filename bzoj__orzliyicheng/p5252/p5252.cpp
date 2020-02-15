#include<set>
#include<map>
#include<ctime>
#include<queue>
#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define N 400000
#define M (8*N)
#define DATA (300000*30)
typedef long long ll;
using namespace std;
int n, k, cnt, nex[M], nu[M], va[M];
ll lim=1;
int pos;
char s[DATA];
int read(){
	int x=0, q=1;
	while(s[pos] && (s[pos]<'0' || s[pos]>'9')) s[pos++]=='-'?q=-1:0;
	while(s[pos] && (s[pos]>='0' && s[pos]<='9')) x=x*10+s[pos++]-'0';
	return x*q;
}
void link(int u, int v, int w){
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;va[cnt]=w;
}
ll f[N][3], g[N][3], best[N][3];
void dfs(int u, int fa, ll x){
	f[u][0]=0;
	f[u][1]=f[u][2]=-x;
	g[u][0]=0;
	g[u][1]=g[u][2]=1;
	best[u][0]=0;
	best[u][1]=0;
	for (int j=nex[u];j;j=nex[j]){
		int v=nu[j];
		if (v==fa) continue;
		dfs(v,u,x);
		{
			ll tmp0=f[u][1]+f[v][0]+va[j];
			ll tmp1=f[u][1]+f[v][1]+va[j]+x;
			ll tmp2=f[u][2]+best[v][0];
			f[u][2]+=best[v][0];
			g[u][2]+=best[v][1];
			if (tmp0>f[u][2] || tmp0==f[u][2] && g[u][1]+g[v][0]>g[u][2])
				f[u][2]=tmp0,
				g[u][2]=g[u][1]+g[v][0];
			if (tmp1>f[u][2] || tmp1==f[u][2] && g[u][1]+g[v][1]-1>g[u][2])
				f[u][2]=tmp1,
				g[u][2]=g[u][1]+g[v][1]-1;
		}
		{
			ll tmp0=f[u][0]+f[v][0]+va[j]-x;
			ll tmp1=f[u][0]+f[v][1]+va[j];
			ll tmp2=f[u][1]+best[v][0];
			f[u][1]+=best[v][0];
			g[u][1]+=best[v][1];
			if (tmp0>f[u][1] || tmp1==f[u][1] && g[u][0]+g[v][0]+1>g[u][1])
				f[u][1]=tmp0,
				g[u][1]=g[u][0]+g[v][0]+1;
			if (tmp1>f[u][1] || tmp1==f[u][1] && g[u][0]+g[v][1]>g[u][1])
				f[u][1]=tmp1,
				g[u][1]=g[u][0]+g[v][1];
		}
		{
			f[u][0]+=best[v][0];
			g[u][0]+=best[v][1];
		}
	}
	for (int j=0;j<3;j++)
		if (f[u][j]>best[u][0] || f[u][j]==best[u][0] && g[u][j]>best[u][1])
			best[u][0]=f[u][j],
			best[u][1]=g[u][j];
}
bool check(ll x){
	dfs(1,0,x);
//	cout<<"Result: "<<x<<' '<<best[1][0]<<' '<<best[1][0]+best[1][1]*x<<' '<<best[1][1]<<endl;
	return best[1][1]<k;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("data.in","r",stdin);
#endif
	fread(s,1,DATA-1,stdin);
	cnt=n=read();k=read()+1;
	for (int i=1;i<n;i++){
		int u=read(), v=read(), w=read();
		link(u,v,w);
		link(v,u,w);
		lim+=abs(w);
	}
	ll ans=0;
	for (ll le=lim, ri=-lim;le>ri+1;){
		ll mid=le+ri>>1;
		if (check(mid)) le=mid;else ri=mid, ans=best[1][0]+mid*k;
	}
	cout<<ans<<endl;
	return 0;
}
