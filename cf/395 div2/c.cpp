#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, ans, cnt, next[1000000], nu[1000000], f[200000], c[200000];
int dfs1(int t, int fa){
	int j=next[t], flag=c[t];
	while (j){
		int v=nu[j];
		if (v!=fa && dfs1(v, t)!=c[t]) flag=0;
		j=next[j];
	}
	return f[t]=flag;
}
int dfs2(int t, int fa){
	int j=next[t], flag=1, p;
	for (int j=next[t];j;j=next[j])
	if (nu[j]!=fa)
		if (!f[nu[j]]) flag--;
	if (flag==1){
		ans=t;
		return 1;
	}
	if (flag<0) return 0;
	if (c[t]!=c[1]) return 0;
	for (int j=next[t];j;j=next[j])
	if (nu[j]!=fa)
		if (!f[nu[j]]) p=nu[j];
		else
			if (f[nu[j]]!=c[1]) return 0;
	return dfs2(p, t);
}
int main(){
	cin>>n;
	cnt=n;
	for (int i=1;i<n;i++){
		int u, v;
		scanf("%d%d", &u, &v);
		next[++cnt]=next[u];next[u]=cnt;nu[cnt]=v;
		next[++cnt]=next[v];next[v]=cnt;nu[cnt]=u;
	}
	for (int i=1;i<=n;i++) scanf("%d", &c[i]);
	dfs1(1,1);
	dfs2(1,1);
	if (!ans) cout<<"NO"<<endl;
	else cout<<"YES"<<endl<<ans<<endl;
	return 0;
}
