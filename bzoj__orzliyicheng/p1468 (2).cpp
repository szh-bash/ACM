#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int ans,cnt, n, root, k, deep[5000], sum, f[50000], next[200000], nu[200000], va[200000], son[50000], d[50000], done[50000];
void add(int u, int v, int w){
	next[++cnt]=next[u];next[u]=cnt;nu[cnt]=v;va[cnt]=w;
}
void getroot(int x, int fa){
	f[x]=0;son[x]=1;
	for (int j=next[x];j;j=next[j]){
		if (nu[j]==fa || done[nu[j]]) continue;
		getroot(nu[j],x);
		son[x]+=son[nu[j]];
		f[x]=max(f[x],son[nu[j]]);
	}
	f[x]=max(f[x],sum-son[x]);
	if (f[x]<f[root]) root=x;
}
void getdeep(int x, int fa){
	deep[++deep[0]]=d[x];
	for (int j=next[x];j;j=next[j]){
		if (nu[j]==fa || done[nu[j]]) continue;
		d[nu[j]]=d[x]+va[j];
		getdeep(nu[  j],x);
	}
}
int calc(int x, int now){
	d[x]=now;deep[0]=0;getdeep(x,0);
	sort(deep+1,deep+1+deep[0]);
	int t=0, l, r;
	for (l=1,r=deep[0];l<r;)
		if (deep[l]+deep[r]<=k){t+=r-l;l++;}
		else r--;
	return t;
}
void work(int x){
	ans+=calc(x,0);
	done[x]=1;
	for (int j=next[x];j;j=next[j]){
		if (done[nu[j]]) continue;
		ans-=calc(nu[j],va[j]);
		sum=son[nu[j]];
		root=0;
		f[0]=sum;
		getroot(nu[j],root);
		work(root);
	}
}
int main(){
	cin>>n;
	cnt=n;
	for (int i=1;i<n;i++){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		add(u,v,w);
		add(v,u,w);
	}
	cin>>k;
	f[0]=sum=n;
	getroot(1,0);
	work(root);
	cout<<ans<<endl;
	return 0;
}
