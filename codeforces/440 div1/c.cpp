#include <map>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define N 500000
#define mo 1000000007
typedef long long ll;
using namespace std;
map<ll, int> mp;
int n, cnt, ct, flag[N], nex[N*3], gg[N], nu[N*3], count, count2, g[N*3], num[N*3];
ll f[N+100], ans;
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=='-'?(q=-1):0, ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
void add(int u, int v, int k){
	nex[++ct]=nex[u];nex[u]=ct;nu[ct]=v;num[ct]=k;
}
void dfs(int u){
	flag[u]=1;
	count++;
	for (int j=nex[u];j;j=nex[j]){
		if (!g[num[j]]) count2+=g[num[j]]=1;
		if (!flag[nu[j]]) dfs(nu[j]);
	}
}
int power(ll x, int b){
	ll p=1;
	while (b){
		if (b&1) p=p*x%mo;
		x=x*x%mo;
		b>>=1;
	}
	return p;
}
void get_ans(){
	ll p=0;
	for (int i=0;i<=count2 && i<=count;i++)
		p=(p+(f[count]*gg[i]%mo)*gg[count-i]%mo)%mo;
	count=count2=0;
	ans=ans*p%mo;
}
int main(){
	f[0]=ans=1;
	for (int i=1;i<=N;i++) f[i]=f[i-1]*i%mo;
	n=read();
	for (int i=0;i<=n*2;i++) gg[i]=power(f[i],mo-2);
	ct=N;
	for (int i=1;i<=n;i++){
		ll x=read()+1000000000, y=read()+1000000005;
		y=y+2000000000;
		if (!mp[x]) mp[x]=++cnt;
		if (!mp[y]) mp[y]=++cnt;
		x=mp[x];y=mp[y];
		add(x,y,i);
		add(y,x,i);
	}
	for (int i=1;i<=cnt;i++)
		if (!flag[i]){
			dfs(i);
			get_ans();
		}
	cout<<ans<<endl;
	return 0;
}
