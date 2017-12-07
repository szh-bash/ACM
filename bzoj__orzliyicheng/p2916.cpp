#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
#define MAXN (1000+10)
int n,m,a[MAXN];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		a[u]++,a[v]++;
	}
	long long ans=(long long)n*(n-1)*(n-2)/6;
	for(int i=1;i<=n;i++) ans-=a[i]*(n-a[i]-1)/2;
	cout<<ans<<endl;
	return 0;
}
