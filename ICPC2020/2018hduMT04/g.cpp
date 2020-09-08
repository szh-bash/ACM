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
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
ll readll(){
    ll p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
#define N 1000005
#define M N*3
int n, cnt, t, ct, nex[M], nu[M], son[N], b[N], power[N], c[N], l[N], tag[N], vis[N];
int ans, res;
void add(int u, int v){
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;
}
void dfs0(int u, int fa){
	for (int j=nex[u];j;j=nex[j]){
		int v=nu[j];
		if (v==fa) continue;
		dfs0(v,u);
		son[u]++;
	}
}
int pw(ll a, int b){
	ll c=1;
	while (b){
		if (b&1) c=c*a%mo;
		a=a*a%mo;
		b>>=1;
	}
	return c;
}
inline void inc (int &a, int b){
	a+=b;
	if (a>=mo) a-=mo;
}
void upd(int x, int y){
	for (;x<=n;x+=x&(-x)) c[x]+=y;
}
int sum(int x){
	int res=0;
	for (;x;x-=x&(-x)) res+=c[x];
	return res;
}
int dfs2(int u, int fa){
	if (++t>n) return 1;
	int tct=ct;
	for (int j=nex[u];j;j=nex[j]){
		int v=nu[j];
		if (v==fa) continue;
		l[++ct]=v;
		upd(ct,1);
		continue;
	}
	sort(l+tct+1,l+ct+1);
	for (int j=tct+1;j<=ct;j++) tag[l[j]]=j;
	while (t<=n && tag[b[t]]>tct && tag[b[t]]<=ct){
		res=1ll*res*pw(power[son[u]],mo-2)%mo*power[son[u]-1]%mo;
		inc(ans,1ll*res*(sum(tag[b[t]]-1)-sum(tct))%mo);
		upd(tag[b[t]],-1);
		son[u]--;
		vis[tag[b[t]]]=u;
		if (dfs2(b[t],u)) return 1;
	}
	int tres=1ll*res*pw(power[son[u]],mo-2)%mo*power[son[u]-1]%mo;
	int flag=0;
	for (int j=tct+1;j<=ct;j++)
		if (vis[j]!=u){
			if (l[j]<b[t]) inc(ans,tres);
			tag[l[j]]=0;
			upd(j,-1);
			flag=1;
		}
	ct=tct;
	return flag;
}
void solve(){
	cnt=n=read();
	for (int i=1;i<=n;i++) b[i]=read(), nex[i]=tag[i]=c[i]=vis[i]=son[i]=0;
	for (int i=1;i<n;i++){
		int u=read(), v=read();
		add(u,v);
		add(v,u);
	}
	dfs0(1,0);
	res=1;
	ans=0;
	for (int i=1;i<=n;i++) res=1ll*res*power[son[i]]%mo;
	for (int i=1;i<b[1];i++){
		inc(ans,res);
		res=1ll*res*pw(power[son[i]],mo-2)%mo;
		res=1ll*res*pw(power[son[i+1]],mo-2)%mo;
		son[i]--;
		son[i+1]++;
		res=1ll*res*power[son[i]]%mo;
		res=1ll*res*power[son[i+1]]%mo;
	}
	dfs2(b[t=1],ct=0);
	printf("%d\n",ans);
}
int main(){
	power[0]=1;
	for (int i=1;i<N;i++) power[i]=1ll*power[i-1]*i%mo;
	for (int _=read();_;_--) solve();
    return 0;
}
