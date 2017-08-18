#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define N 20010
using namespace std;
int cnt, n, f[N], ans, q[2][3], size[N], u[N], nu[N*4], next[N*4], va[N*4], done[N]; 
void add(int u, int v, int w){
	next[++cnt]=next[u];next[u]=cnt;nu[cnt]=v;va[cnt]=w;
}
void dfs(int t, int fa){
	u[++cnt]=t;
	size[t]=1;
	f[t]=0;
	for (int i=next[t];i;i=next[i])
		if (!done[nu[i]] && nu[i]!=fa){
			dfs(nu[i],t);
			size[t]+=size[nu[i]];
			f[t]=max(f[t],size[nu[i]]);
		}
}
int find(int t){
	cnt=0;
	int Min=0xfffffff, p;
	dfs(t,0);
	for (int i=1;i<=cnt;i++)
		if (max(size[t]-size[u[i]],f[u[i]])<Min) 
			Min=max(size[t]-size[u[i]],f[u[i]]), p=u[i];
	return p;
}
void dfs2(int t, int fa, int di){
	q[1][di%3]++;
	for (int i=next[t];i;i=next[i])
		if (!done[nu[i]] && nu[i]!=fa)
			dfs2(nu[i],t,di+va[i]);
}
void calc(int t){
	q[0][0]=q[0][1]=q[0][2]=0;
	for (int i=next[t];i;i=next[i])
		if (!done[nu[i]]){
			q[1][0]=q[1][1]=q[1][2]=0;
			dfs2(nu[i], t, va[i]);
			ans+=q[1][0]*(1+q[0][0])+q[1][1]*q[0][2]+q[1][2]*q[0][1];
			q[0][0]+=q[1][0];
			q[0][1]+=q[1][1];
			q[0][2]+=q[1][2];
		}
}
void work(int t){
	int root=find(t);
	done[root]=1;
	calc(root);
	//cout<<root<<' '<<ans<<endl;
	for (int i=next[root];i;i=next[i])
		if (!done[nu[i]]) work(nu[i]);
}
int gcd(int a, int b){return !b?a:gcd(b,a%b);}
int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout); 
	scanf("%d", &n);cnt=n;
	for (int i=1;i<n;i++){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		add(u,v,w);
		add(v,u,w);
	}
	work(1);
	//for (int i=1;i<=n;i++) cout<<done[i]<<endl;
	ans=ans*2+n; 
	int gys=gcd(ans,n*n);
	printf("%d/%d", ans/gys, n*n/gys);
	return 0;
}
