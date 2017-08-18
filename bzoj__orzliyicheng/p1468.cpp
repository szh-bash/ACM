#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, k, ans, f[40010], next[200000], nu[200000], va[200000], cnt, root, sum, son[40010], done[40010], deep[40010], d[40010];
void add(int a, int b, int c){
	next[++cnt]=next[a];next[a]=cnt;nu[cnt]=b;va[cnt]=c;
}
void getroot(int x, int fa){
	f[x]=0;son[x]=1;
	for (int j=next[x];j;j=next[j]){
		if (nu[j]==fa || done[nu[j]]) continue;
		getroot(nu[j], x);
		son[x]+=son[nu[j]];
		f[x]=max(f[x],son[nu[j]]);
	}
	f[x]=max(f[x], sum-son[x]);
	if (f[x]<f[root]) root=x;
}
void getdeep(int x, int fa){
	deep[++deep[0]]=d[x];
	for (int j=next[x];j;j=next[j]){
		if (nu[j]==fa || done[nu[j]]) continue;
		d[nu[j]]=d[x]+va[j];
		getdeep(nu[j],x);
	}
}
int calc(int x, int now){
	d[x]=now;deep[0]=0;getdeep(x,0);
	sort(deep+1,deep+1+deep[0]);
	int t=0, l, r;
	for (l=1, r=deep[0];l<r;)
		if (deep[l]+deep[r]<=k) {t+=r-l;l++;}
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
		root=0;f[0]=sum;
		getroot(nu[j],root);
		work(root);
	}
}
int main(){
	scanf("%d", &n);
	cnt=n;
	for (int i=1;i<n;i++){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		add(a, b, c);
		add(b, a, c);
	}
	scanf("%d", &k);
	f[0]=sum=n;
	getroot(1, 0);
	work(root);
	printf("%d\n", ans);
	return 0;
}
