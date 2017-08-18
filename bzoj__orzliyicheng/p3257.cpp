#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
const long long INF=(long long)1e8*1e8;
void add(int u, int v, int w){
	next[++cnt]=next[u];next[u]=cnt;nu[cnt]=v;va[cnt]=w;
}
int main(){
	scanf("%d", &T);
	while (T){
		T--;
		scanf("%d", &n);
		for (int i=1;i<=n;i++)	scanf("%d", &g[i]);
		cnt=n;
		memset(next,0,4*(n+2));
		for (int i=1;i<n;i++){
			int u, v;
			scanf("%d%d&d", &u, &v, &w);
			add(u,v);add(v,u);
		}
		cnt=1;
		l[1]=1;
		memset(f,0,4*(n+2));
		int le=0;
		while (le, cnt){
			int u=l[++le];
			int j=next[u];
			while (j){
				int v=nu[j];
				if (!f[v]) l[++cnt]=v;
				j=next[j];
			}
		}
		memset(f,1,4*(n+2));
		for (int i=1;i<=n;i++)
			for (int j=0;j<=2;j++) f[i][j]=INF;
		for (int i=n;i;i--){
			int u=l[i];
			f[u]=1;
			int j=next[u];
			while (j){
				int v=nu[j];
				if (f[v]){
					a1=min(va[j],f[v][0]);
					a2=min(va[j],f[v][1]);
					
				}
				j=next[j];
			}
			if (!g[u]){
				p[i][0]=INF;
				
			}
			if (g[u]==1){
			}
			if (g[u]==2){
			}
		}
	}
	return 0;
}

