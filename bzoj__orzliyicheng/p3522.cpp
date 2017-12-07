#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, cnt, g[5000], f[5001], next[15000], nu[15000];
long long ans;
void add(int u, int v){
	next[++cnt]=next[u];next[u]=cnt;nu[cnt]=v;
}
int dfs(int u, int fa){
	int tot=0, tmp=0, MAX=f[u];
	for (int j=next[u];j;j=next[j]){
		int v=nu[j];
		if (v!=fa){;
			f[v]=f[u]+1;
			int vp=dfs(v,u);
			MAX=max(vp,MAX);
			if (u==fa) g[vp]++;
		}
		tot++;
	}
	if (u==fa && tot>2){
		for (int j=n;j;j--){
			tmp+=g[j];
			if (tmp>2) ans+=(long long)tmp*(tmp-1)*(tmp-2)/6;
		}
	}
	return MAX;
}
int main(){
	scanf("%d", &n);
	cnt=n;
	for (int i=1;i<n;i++){
		int u, v;
		scanf("%d%d", &u, &v);
		add(u,v);add(v,u);
	}
	for (int i=1;i<=n;i++){
		f[i]=0;
		memset(g,0,4*n);
		dfs(i,i);
	}
	cout<<ans<<endl;	
	return 0;
}
