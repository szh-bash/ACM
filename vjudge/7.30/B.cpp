#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, next[300000], nu[300000], f[300000], flag[300000], v[300000], cnt;
void add(int u, int v){
	next[++cnt]=next[u];next[u]=cnt;nu[cnt]=v;
}
void dfs(int t, int w){
	if (f[t]!=-1){
		if(f[t]!=w) f[t]=-2;
		if (flag[t]) return;
		if (t) return;
	}
	f[t]=w;
	flag[t]=1;
	for (int j=next[t];j;j=next[j]){
		int u=nu[j];
			if (v[t]) dfs(u,v[t]);else dfs(u,w);
	}
	flag[t]=0;
}
int main(){
	scanf("%d", &n);
	cnt=n;
	for (int i=1;i<=n;i++){
		int m, x;
		scanf("%d%d", &v[i], &m);
		for (int j=1;j<=m;j++){
			scanf("%d", &x);
			if (x==i) continue;
			add(i,x);
		}
    }
    memset(f,-1,sizeof(f));
    f[0]=0;
    dfs(1, v[1]);
    for (int i=1;i<=n;i++){
    	if (f[i]==-2) cout<<"unknown ";
			else
			if (!f[i]) cout<<"sober ";
			else cout<<f[i]<<' ';
    	if (v[i]) cout<<v[i]<<endl;
    		else
    		if (f[i]==-2) cout<<"unknown"<<endl;
				else 
				if (!f[i]) cout<<"sober"<<endl;
					else cout<<f[i]<<endl;
    }
	return 0;
}
