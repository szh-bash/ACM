#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
int s, t, n, ans, tot, cnt, next[49500], nu[49500], va[49500]
, co[49500], d[5100], cur[49500], flag[5100], a[101][101]
, l[4951], r[4951], dd[101];
void add(int u, int v, int fl, int c){
	next[++cnt]=next[u];next[u]=cnt;nu[cnt]=v;va[cnt]=fl;co[cnt]=c;
	next[++cnt]=next[v];next[v]=cnt;nu[cnt]=u;va[cnt]=0;co[cnt]=-c;
}
int aug(int u, int flow){
	if (u==t) return flow;
	flag[u]=1;
	for (int i=cur[u];i;i=next[i])
		if (va[i] && !flag[nu[i]] && d[u]==d[nu[i]]+co[i])
			if (int tmp=aug(nu[i],min(flow,va[i])))
				return va[i]-=tmp,va[i^1]+=tmp,cur[u]=i,tmp;
	return 0;
}
bool updata(){
	int tmp=1e8;
	for (int i=0;i<t;i++)
		if (flag[i])
		for (int j=next[i];j;j=next[j])
			if (!flag[nu[j]] && va[j]) tmp=min(tmp,d[nu[j]]+co[j]-d[i]);
	if (tmp==1e8) return 1;
	for (int i=0;i<t;i++)
		if (flag[i]) flag[i]=0,d[i]+=tmp;
	return 0;
}
int costflow(){
	int ans=0, tmp;
	while (1){
		for (int i=0;i<t;i++) cur[i]=next[i];
		while (tmp=aug(s,1e8)){
			ans+=tmp*d[s];
			memset(flag,0,sizeof(flag));
		}
		if (updata()) break;
	}
	return ans;
}
int main(){
	scanf("%d", &n);
	ans=n*(n-1)*(n-2)/3+n*(n-1)/2;
	tot=n*(n-1)/2;
	t=cnt=n*(n-1)/2+n+1;cnt+=(cnt+1)%2;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++){
			int x;
			scanf("%d", &x);a[i][j]=x;
			if (j>i){
				if (x==1) dd[j]++;
				if (!x) dd[i]++;
				if (x==2){
					int v=(n-1+n-i)*i/2-n+j;
					l[v]=i;r[v]=j;
					add(v,tot+i,1,0);
					add(v,tot+j,1,0);
					add(s,v,1,0);
				}
			}
		}
	for (int i=1;i<=n;i++){
		for (int j=dd[i]+1;j<n;j++) add(tot+i,t,1,2*j-1);
		ans-=dd[i]*dd[i];
	}
	printf("%d\n", (ans-costflow())/2);
	for (int i=1;i<=tot;i++)
	if (next[i]){
		int j=next[i];
		while (j && !nu[j]) j=next[j];
		int tp1=nu[j]-tot, tp2=nu[next[j]]-tot;
		a[tp1][tp2]=va[j];a[tp2][tp1]=va[j]^1;
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++) printf("%d ", a[i][j]);
		printf("\n");
	}
	return 0;
}
