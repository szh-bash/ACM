#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int n, m1, m2, ans, e1[10][10], e2[10][10], flag[10], c[10];
ll f[45];
map <ll, int>g;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
int trans(int x, int y){
	if (x<y) swap(x,y);
	return x*(x-1)/2+y; 
}
void dfs(int t){
	if (t>n){
		ll k=0;
		for (int i=1;i<=n;i++)
			for (int j=i;j<=n;j++){
				if (e1[i][j] && (e1[i][j]!=e2[c[i]][c[j]] || e1[j][i]!=e2[c[j]][c[i]]))
					return;
				if (e1[i][j]) k+=f[trans(c[i],c[j])];
			}
		if (!g[k]) g[k]=1, ans++;
		return;
	}
	for (int i=1;i<=n;i++)
		if (!flag[i]){
			flag[i]=1;
			c[t]=i;
			dfs(t+1);
			flag[i]=0;
		}
}
int main(){
	f[0]=1;
	for (int i=1;i<=40;i++) f[i]=f[i-1]<<1;
	while (~scanf("%d%d%d", &n, &m1, &m2)){
		ans=0;
		g.clear();
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++) e1[i][j]=e2[i][j]=0;
		for (int i=1;i<=m1;i++){
			int u=read(), v=read();
			e1[u][v]=e1[v][u]=1;
		}
		for (int i=1;i<=m2;i++){
			int u=read(), v=read();
			e2[u][v]=e2[v][u]=1;
		}
		dfs(1);
		cout<<ans<<endl;
	}
    return 0;
}
