#include <bits/stdc++.h>
#define N 1010
#define ll long long
using namespace std;

int id[N];
ll c[N],now[N];
int n,m,k;
ll sum;

int solve()
{
	sum=0;
	for (int i=1;i<=n;i++)
	{
		ll d; scanf("%lld",&d);
		for (int j=1;j<=m;j++)
		{
			ll v; scanf("%lld",&v);
			if (v>c[id[j]]) return 0;
			now[id[j]]+=v;
			if (now[id[j]]>c[id[j]]) {sum-=now[id[j]]-c[id[j]]; if (sum<0) return 0; now[id[j]]=c[id[j]];}
		}
		sum+=d;
		ll tmp=0;
		for (int j=1;j<=k;j++) tmp+=now[j];
		if (tmp<=sum)
		{
			sum=0;
			for (int j=1;j<=k;j++) now[j]=0;
		}
	}
	for (int i=1;i<=m;i++) sum-=now[id[i]];
	return (sum>=0);
}

int main()
{
	scanf("%d %d %d",&n,&m,&k);
	for (int i=1;i<=k;i++) scanf("%d",&id[i]);
	for (int i=1;i<=m;i++) scanf("%lld",&c[i]);
	if (solve()) puts("possible"); else puts("impossible");
}
