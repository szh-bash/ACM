#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define INF (long long)999999999*999999;
using namespace std;
int n, m, cnt, next[50000], nu[50000], flag[5050];
bool q[5050][5050];
long long va[50000], f[5050][5050], T;
void dfs(int x){
	for (int i=1;i<=n;i++) f[x][i]=INF;
	if (x==n){
		q[n][1]=1;
		f[n][1]=0;
		return;
	}
	int j=next[x];
	while (j){
		int v=nu[j];
		if (!flag[v]) dfs(v), flag[v]=1;
		for (int k=1;k<=n;k++)
			if (q[v][k-1])
				f[x][k]=min(f[x][k],f[v][k-1]+va[j]), q[x][k]=1;
		j=next[j];
	}
}
int main(){
	cin>>n>>m>>T;
	cnt=n;
	for (int i=1;i<=m;i++){
		int u, v;
		long long w;
		cin>>u>>v>>w;
		next[++cnt]=next[u];next[u]=cnt;nu[cnt]=v;va[cnt]=w;
	}
	dfs(1);
	for (int i=n;i;i--)
		if (f[1][i]<=T){
			cout<<i<<endl;
			int p=i, k=1;
			while (k!=n){
				
				cout<<k<<' ';
				int j=next[k];
				while (j){
					if (f[nu[j]][p-1]+va[j]==f[k][p]){
						k=nu[j];
						p--;
						break;
					}
					j=next[j];
				}
			}
			cout<<n<<endl;
			return 0;
		}
	return 0;
}
