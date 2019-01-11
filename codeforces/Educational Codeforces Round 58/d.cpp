#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <tr1\unordered_map>
#define N 200005
typedef long long ll;
using namespace std;
using namespace std::tr1;
int cnt, n, ans, nex[N*3], nu[N*3], a[N];
int g[N][505], id[N][505];
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') 
		ch=='-'?q=-1:0,
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
void add(int u, int v){
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;
	nex[++cnt]=nex[v];nex[v]=cnt;nu[cnt]=u;
}
unordered_map<int,int>mp[N];

void dfs(int u, int fa){
	for (int j=2;j*j<=a[u];j++)
		if (a[u]%j==0)
			id[u][++id[u][0]]=j,
			mp[u][j]=id[u][0],
			id[u][++id[u][0]]=a[u]/j,
			mp[u][a[u]/j]=id[u][0];
			//tid[u][++tid[u][0]]=a[u]/j,
			//ind;
	if (a[u]>1)
		id[u][++id[u][0]]=a[u],
		mp[u][a[u]]=id[u][0],
		ans=1;
	
	for (int i=nex[u];i;i=nex[i]){
		int v=nu[i];
		if (v==fa) continue;
		dfs(v,u);
		for (int j=1;j<=id[v][0];j++)
			if (a[u]%id[v][j]==0){
				int k=mp[u][id[v][j]];
				ans=max(ans,g[u][k]+g[v][j]+1);
				if (g[v][j]+1>g[u][k]) g[u][k]=g[v][j]+1;
				//cout<<a[u]<<' '<<a[v]<<' '<<id[v][j]<<endl;
			}
	}
	
}
int main(){
	cnt=n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<n;i++) add(read(),read());
	dfs(1, 0);
	cout<<ans<<endl;
	return 0;
}
