#include <bits/stdc++.h>
#define N 155
#define inf 51000001
using namespace std;

int mat[N][N],sumr[N][N],sumc[N][N];
int up[N],down[N],lft[N],rght[N];
int n,m,p,mx;

void getup()
{
	for (int i=1;i<=n;i++) up[i]=-inf;
	for (int l=1;l<=m;l++) for (int r=l;r<=m;r++) 
	{
		int now=0;
		for (int i=1;i<=n;i++)
		{
			now=max(now,0)+sumr[i][r]-sumr[i][l-1];
			up[i+1]=max(up[i+1],now);
		}
	}
	for (int i=1;i<n;i++) up[i+1]=max(up[i],up[i+1]);
	mx=up[n+1];
}

void getdown()
{
	for (int i=1;i<=n;i++) down[i]=-inf;
	for (int l=1;l<=m;l++) for (int r=l;r<=m;r++) 
	{
		int now=0;
		for (int i=n;i>1;i--)
		{
			now=max(now,0)+sumr[i][r]-sumr[i][l-1];
			down[i-1]=max(down[i-1],now);
		}
	}
	for (int i=n;i>1;i--) down[i-1]=max(down[i],down[i-1]);
}

void getleft()
{
	for (int j=1;j<=m;j++) lft[j]=-inf;
	for (int l=1;l<=n;l++) for (int r=l;r<=n;r++)
	{
		int now=0;
		for (int j=1;j<m;j++)
		{
			now=max(now,0)+sumc[j][r]-sumc[j][l-1];
			lft[j+1]=max(lft[j+1],now);
		}
	}
	for (int j=1;j<m;j++) lft[j+1]=max(lft[j],lft[j+1]);
}

void getright()
{
	for (int j=1;j<=m;j++) rght[j]=-inf;
	for (int l=1;l<=n;l++) for (int r=l;r<=n;r++)
	{
		int now=0;
		for (int j=m;j>1;j--)
		{
			now=max(now,0)+sumc[j][r]-sumc[j][l-1];
			rght[j-1]=max(rght[j-1],now);
		}
	}
	for (int j=m;j>1;j--) rght[j-1]=max(rght[j],rght[j-1]);
}

void work()
{
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) scanf("%d",&mat[i][j]); 
	for (int i=1;i<=n;i++)
	{
		sumr[i][0]=0;
		for (int j=1;j<=m;j++) sumr[i][j]=sumr[i][j-1]+mat[i][j];
	}
	for (int i=1;i<=m;i++)
	{
		sumc[i][0]=0;
		for (int j=1;j<=n;j++) sumc[i][j]=sumc[i][j-1]+mat[j][i];
	}
	mx=-inf;
	getup();
	getdown();
	getleft();
	getright();
	int ans=mx;
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) 
	{
		int now=-inf;
		now=max(now,lft[j]); now=max(now,rght[j]);
		now=max(now,up[i]);   now=max(now,down[i]);
		now=max(now,mx-mat[i][j]+p);
		ans=min(ans,now);
	}
	printf("%d\n",ans);
}

int main()
{
	while (scanf("%d %d %d",&n,&m,&p)!=EOF) work();
}
