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
#define N 20
int cnt, n, ct;
int mi, tmp, ans;
int flag[N], p[N], a[N][N], f[N][5], c[N], g[N];
void calc(int o){
	int tmp=0;
	for (int i=1;i<=n/2;i++)
		for (int j=i+1;j<=n/2;j++)
			if (a[c[i]][c[j]]) tmp+=4*(j-i);
	for (int i=1;i<=n/2;i++)
		tmp+=(((o^1)*(n/2-i+1)+o*i)*2-1)*p[c[i]];
	mi=min(mi,tmp);
}
void dfs(int t, int o){
	if (t>n/2){
		calc(o);
		return;
	}
	for (int i=1;i<=n;i++)
		if (!(g[i]^o) && !flag[i]){
			c[t]=i;
			flag[i]=1;
			dfs(t+1,o);
			flag[i]=0;
		}
}
void solve(){
	int sum=0;
	for (int i=1;i<=n;i++) p[i]=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=3;j++)
			if (g[i]^g[f[i][j]]) p[i]++, p[f[i][j]]++;
	mi=999999;dfs(1,0);sum+=mi;
	mi=999999;dfs(1,1);sum+=mi;
	ans=min(ans,sum);
}
void dfs1(int t, int d){
	if (t>n/2) {
		solve();
		return;
	}
	for (int i=d;i<=n;i++)
		if (!g[i]){
			g[i]=1;
			dfs1(t+1,i+1);
			g[i]=0;
		}
}
int main(){
	cnt=n=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=3;j++) f[i][j]=read(), a[i][f[i][j]]=1;
	ans=9999999;
	dfs1(1, 1);
	cout<<ans/4<<endl;
    return 0;
}
