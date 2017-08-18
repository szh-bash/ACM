#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int ans, tot;
int n, cnt, p, m, k, l[300000], q[300000], a[300000], nextt[2000000], nu[2000000], f[300000];
void dfs(int x){
	tot=1;
	l[1]=x;
	f[x]=1;
	for (int i=1;i<=tot;i++){
	x=l[i];
	++q[a[x]];
	p=max(p,q[a[x]]);
	int j=nextt[x];
	while (j){
		int v=nu[j];
		if (!f[v]) f[v]=1,l[++tot]=v;
		j=nextt[j];
	}
	}
}
void clean(int x){
	cnt=1;
	l[1]=x;
	f[x]=2;
	for (int i=1;i<=cnt;i++){
	x=l[i];
	--q[a[x]];
	int j=nextt[x];
	while (j){
		int v=nu[j];
		if (f[v]==1) f[v]=2,l[++cnt]=v;
		j=nextt[j];
	}
	}
}
int main(){	
	cin>>n>>m>>k;
	cnt=n;
	for (int i=1;i<=n;i++) scanf("%d", &a[i]);
	for (int i=1;i<=m;i++){
		int u, v;
		scanf("%d%d" , &u, &v);
		nextt[++cnt]=nextt[u];nextt[u]=cnt;nu[cnt]=v;
		nextt[++cnt]=nextt[v];nextt[v]=cnt;nu[cnt]=u;
	}
	for (int i=1;i<=n;i++)
		if (!f[i]) p=0, dfs(i), ans+=tot-p, clean(i);
	cout<<ans<<endl;
	return 0;
}
