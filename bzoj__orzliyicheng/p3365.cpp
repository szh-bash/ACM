#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 40010
using namespace std;
struct zsm{
	int belong, dis;
}a[N];
int cnt, ans, n, m, k, same[N], next[N*4], nu[N*4], va[N*4], size[N], f[N], u[N], done[N];
void add(int u, int v, int w){
	next[++cnt]=next[u];next[u]=cnt;nu[cnt]=v;va[cnt]=w;
}
bool cmp(zsm a, zsm b){return a.dis<b.dis;}
void dfs(int t, int fa){
	int j=next[t];
	u[++cnt]=t;
	size[t]=1;
	f[t]=0;
	while (j){
		if (!done[nu[j]] && nu[j]!=fa){
			dfs(nu[j], t);
			size[t]+=size[nu[j]];f[t]=max(f[t],size[nu[j]]);
		}
		j=next[j];
	}
}
int find(int t){
	cnt=0;
	dfs(t,0);
	int p, Min=0x7fffffff;
	for (int i=1;i<=cnt;i++){
		if (max(size[t]-size[u[i]], f[u[i]])<=Min) 
			Min=max(size[t]-size[u[i]], f[u[i]]), p=u[i];
		//cout<<Min<<' '<<p<<endl;
	}
	//cout<<endl;
	return p;
}
void dfs2(int t, int fa, int belong, int di){
	a[++cnt].dis=di;
	a[cnt].belong=belong;
	for (int j=next[t];j;j=next[j])
		if (!done[nu[j]] && nu[j]!=fa)
			dfs2(nu[j], t, belong, di+va[j]);
}
void calc(int t){
	cnt=0;
	a[++cnt].belong=t;
	a[cnt].dis=0;
	for (int i=next[t];i;i=next[i])
		if (!done[nu[i]]) dfs2(nu[i], t, nu[i],va[i]);
	sort(a+1,a+1+cnt, cmp);
	memset(same,0,sizeof(same));
    for (int i=1;i<=cnt;i++) same[a[i].belong]++;
	for (int i=1;i<cnt;i++){
		while (a[i].dis+a[cnt].dis>k && cnt>i) same[a[cnt--].belong]--;
		same[a[i].belong]--;
		ans+=cnt-i-same[a[i].belong];
	}
}
inline void work(int t){
	int root=find(t);
	done[root]=1;
	calc(root);
	//cout<<root<<' '<<ans<<endl;
	for (int i=next[root];i;i=next[i])
		if (!done[nu[i]])work(nu[i]);
}
int main(){
	freopen("1.in","r",stdin);
	scanf("%d%d", &n, &m);cnt=n;
	for (int i=1;i<=m;i++){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);getchar();getchar();
		add(u, v, w);
		add(v, u, w);
	}
	cin>>k;
	ans=0;
	work(1);
	cout<<ans<<endl;
	return 0;
}
