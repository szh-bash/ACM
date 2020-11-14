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
#define mo 1000000007
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
#define N 100005
#define M N*3
#define V 8000006
#define DATA N*3*10
char s[DATA];
int pos;
int read(){
    int p=0;
    while (s[pos] && !num(s[pos])) pos++;
    while (num(s[pos])) p=p*10+s[pos++]-'0';
    return p;
}
ll ans;
int n, x, cnt, rt, Son;
int a[N], sz[N], son[N], flag[N], l[N];
int nex[M], nu[M];
int g[V][2];
void add(int u, int v){
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;
}
void dfs_pre(int u, int fa){
	sz[u]=1;
	int mx=0;
	for (int j=nex[u];j;j=nex[j]){
		int v=nu[j];
		if (v==fa) continue;
		dfs_pre(v,u);
		sz[u]+=sz[v];
		if (sz[v]>mx) mx=sz[v], son[u]=v;
	}
}
void solve(int u, int fa){
	ans+=1ll*g[rt^a[u]][((u&x)>0)^1]*x;
	for (int j=nex[u];j;j=nex[j]){
		int v=nu[j];
		if (v==fa) continue;
		solve(v,u);
	}
}
void solve_q(int s, int fa){
	flag[fa]=1;
	l[1]=s;
	flag[s]=1;
	int le=0, ri=1;
	while (le<ri){
		int u=l[++le];
		ans+=1ll*g[rt^a[u]][((u&x)>0)^1]*x;
		for (int j=nex[u];j;j=nex[j]){
			int v=nu[j];
			if (flag[v]) continue;
			l[++ri]=v;
			flag[v]=1;
		}
	}
	flag[fa]=0;
	for (int i=1;i<=ri;i++) flag[l[i]]=0;
}
void upd(int u, int fa, int val){
	g[a[u]][(u&x)>0]+=val;
	for (int j=nex[u];j;j=nex[j]){
		int v=nu[j];
		if (v==fa) continue;
		upd(v,u,val);
	}
}
void upd_q(int s, int fa, int val){
	flag[fa]=1;
	l[1]=s;
	flag[s]=1;
	int le=0, ri=1;
	while (le<ri){
		int u=l[++le];
		g[a[u]][(u&x)>0]+=val;
		for (int j=nex[u];j;j=nex[j]){
			int v=nu[j];
			if (flag[v]) continue;
			l[++ri]=v;
			flag[v]=1;
		}
	}
	flag[fa]=0;
	for (int i=1;i<=ri;i++) flag[l[i]]=0;
}
void calc(int u, int fa){
	g[a[u]][(u&x)>0]++;
	for (int j=nex[u];j;j=nex[j]){
		int v=nu[j];
		if (v==fa || v==Son) continue;
		solve_q(v,u);
		upd_q(v,u,1);
	}
}
void dfs(int u, int fa, int opt){
	for (int j=nex[u];j;j=nex[j]){
		int v=nu[j];
		if (v==fa || v==son[u]) continue;
		dfs(v,u,0);
	}
	if (son[u]) dfs(son[u],u,1), Son=son[u], rt=a[u];
	calc(u,fa);Son=0;rt=0;
	if (!opt) upd_q(u,fa,-1); 
}
int main(){
	fread(s,1,DATA,stdin);
	cnt=n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<n;i++){
		int u=read(), v=read();
		add(u,v);
		add(v,u);
	}
	// cout<<"lyknb"<<endl;
	dfs_pre(1,0);
	// for (int i=1;i<=n;i++) cout<<i<<' '<<sz[i]<<' '<<son[i]<<endl;
	for (x=1;x<=n;x<<=1){
		dfs(1,0,0);
		// cout<<x<<' '<<ans<<endl;
	}
	cout<<ans<<endl;
    return 0;
}
