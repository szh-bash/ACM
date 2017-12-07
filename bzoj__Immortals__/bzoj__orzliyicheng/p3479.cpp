#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
struct zsm{
	int u, v, w;
}l[2000001];
long long ans;
int n, c, x[2001], y[2001], fa[2001], cnt=0;
int sqr(int x){return x*x;}
bool cmp(zsm a, zsm b){return a.w<b.w;}
int father(int x){return fa[x]==x ? x : fa[x]=father(fa[x]);}
int main(){
	scanf("%d%d", &n, &c);
	for (int i=1;i<=n;i++){
		scanf("%d%d", &x[i], &y[i]);
		for (int j=i-1;j;j--)
			if (sqr(x[i]-x[j])+sqr(y[i]-y[j])>=c)
				l[++cnt].u=i, l[cnt].v=j, l[cnt].w=sqr(x[i]-x[j])+sqr(y[i]-y[j]);
	}
	sort(l+1,l+1+cnt,cmp);
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=cnt;i++)
		if (father(l[i].u)!=father(l[i].v)){
			ans=ans+l[i].w;
			fa[fa[l[i].u]]=fa[l[i].v];
			n--;
			if (n==1) break;
		}
	if (n==1)cout<<ans<<endl;else cout<<-1<<endl;
	return 0;
}
