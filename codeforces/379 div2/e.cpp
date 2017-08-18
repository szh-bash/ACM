#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int le, ri, cnt, n, next[900000], nu[900000], next2[900000], nu2[900000], f[300000], q[300000][5], l[300000], c[300000], tmp;
void add(int u, int v){
	next[++cnt]=next[u];next[u]=cnt;nu[cnt]=v;
}
void dfs(int t){
	tmp++;
	int lt=ri+1, rt;
	l[++ri]=t;
	f[t]=tmp;
	while (le<ri){
		int u=l[++le], j=next[u];
		while (j){
			int v=nu[j];
			if (c[v]==c[u] && !f[v]) l[++ri]=v, f[v]=tmp;
			j=next[j];
		}
	}
	rt=ri;
	for (int i=lt;i<=rt;i++){
		int u=l[i], j=next[u];
		while (j){
			int v=nu[j];
			if (!f[v]){
				dfs(v);
				next2[++cnt]=next2[f[t]];
				next2[f[t]]=cnt;
				nu2[cnt]=f[v];
			}
			j=next[j];
		}
	}
}
int dfs2(int t){
	int j=next2[t], p=0;
	q[t][0]=q[t][1]=1;
	while (j){
		int v=nu2[j];
		p=max(p,dfs2(v));
		if (q[v][0]+1>=q[t][0]) q[t][1]=q[t][0];
		else 					q[t][1]=max(q[t][1],q[v][0]+1);
		q[t][0]=max(q[t][0],q[v][0]+1);
		j=next2[j];
	}
	return max(q[t][0]+q[t][1]-1,p);
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++) scanf("%d", &c[i]);
	cnt=n;
	for (int i=1;i<n;i++){
		int u, v;
		scanf("%d%d", &u, &v);
		add(u,v);
		add(v,u);
	}
	cnt=n;
	dfs(1);
	cout<<(dfs2(1)/2)<<endl;
	return 0;
}
