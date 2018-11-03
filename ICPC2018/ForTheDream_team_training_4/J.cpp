#include <bits/stdc++.h>
#define inf 10000001
#define N 210
#define LL long long
using namespace std;

int sum[N],f[N][N][N],vis[N][N][N];
int n,L,R;

void pd(int &x,int y)
{
	if (x==-1||x>y) x=y;
}

int dfs(int l,int r,int c)
{
	if (vis[l][r][c]) return f[l][r][c];
	f[l][r][c]=inf; vis[l][r][c]=1;
	if (c==1)
	{
		for (int mid=l;mid<r;mid++)
		    for (int x=L;x<=R;x++) 
		        pd(f[l][r][c],dfs(l,mid,x-1)+dfs(mid+1,r,1)+sum[r]-sum[l-1]);
	}
	else 
	{
		for (int mid=l;mid<r;mid++)
		    for (int x=2;x<=n;x++)
			    pd(f[l][r][c],dfs(l,mid,x-1)+dfs(mid+1,r,1));
	}
	return f[l][r][c];
}

void work()
{
	memset(vis,0,sizeof(vis));
	for (int i=1;i<=n;i++)
	{
		int x; scanf("%d",&x);
		sum[i]=sum[i-1]+x;
		vis[i][i][1]=1; f[i][i][1]=0;
	}
	int ans=dfs(1,n,1);
	printf("%d\n",ans);
}

int main()
{
	freopen("1.in","r",stdin);
	while (scanf("%d %d %d",&n,&L,&R)!=EOF) work();
}
