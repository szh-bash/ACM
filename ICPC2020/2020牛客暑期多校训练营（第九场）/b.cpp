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
#define N 100005
int n, ct, cnt, a[N], num[N], nex[N*3], nu[N*3], va[N*3];
ll need[N], exceed[N];
void add(int u, int v, int w){
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;va[cnt]=w;
}
bool cmp(int a, int b){
	if (exceed[a]>need[a]){
		if (exceed[b]>need[b]) return need[a]<need[b];
		return 1; 
	}
	else if (exceed[a]==need[a]){
		if (exceed[b]>=need[b]) return 0;
		return 1;
	}
	else{
		if (exceed[b]>=need[b]) return 0;
		return exceed[a]>exceed[b];
	}
}
void dfs(int u, int fa){
	need[u]=0;
	int tp=ct;
	for (int j=nex[u];j;j=nex[j]){
		int v=nu[j];
		if (v==fa) continue;
		dfs(v, u);
		num[++ct]=v;
		need[v]+=va[j];
		exceed[v]-=va[j];
		if (exceed[v]<0) need[v]-=exceed[v], exceed[v]=0;
	}
	sort(num+tp+1, num+ct+1,cmp);
	ll sum=0;
	if (ct>tp) need[u]=1ll*999999999*999999999;
	for (int i=tp+1;i<=ct;i++){
		sum-=need[num[i]];
		need[u]=min(need[u], sum);
		sum+=exceed[num[i]];
	}
	exceed[u]=sum-need[u];
	need[u]=-need[u]-a[u];
	if (need[u]<0) exceed[u]-=need[u], need[u]=0;
	ct=tp;
}
void solve(){
	cnt=n=read();
	for (int i=1;i<=n;i++) a[i]=read(), nex[i]=0;
	for (int i=1;i<n;i++){
		int u=read(), v=read(), w=read();
		add(u, v, w);
		add(v, u, w);
	}
	dfs(1,0);
	printf("%lld\n", need[1]);
}
int main(){
	for (int _=read();_;_--) solve();
    return 0;
}

/*
4
5
4 2 1 5 7
1 2 4
1 3 5
4 2 9
5 2 3
6
0 0 0 0 0 10
1 2 1
1 3 1
3 4 1
3 5 1
1 6 1
3
0 6 1
1 2 5
1 3 1
4
0 12 50 49
1 2 10
1 3 25
1 4 40
*/
