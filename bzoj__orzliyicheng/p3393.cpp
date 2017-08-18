#include <iostream>
#include <queue>
#include <cstdio>
#define MAXN 100

using namespace std;

struct Point
{
	int x,y;
} p[2];

const int d[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

int n,m,mark[MAXN][MAXN],cnt;
char mat[MAXN][MAXN];
void floodfill()
{
	mark[p[0].y][p[0].x]=1;
	queue<Point> q;
	q.push(p[0]);

	for ( ; ; )
	{
		Point pt=q.front();
		q.pop();
		cnt=mark[pt.y][pt.x];
		for (int k=0; k<4; k++)
			for (int i=pt.y+d[k][0],j=pt.x+d[k][1]; i>=0 && j>=0 && i<n && j<m; i+=d[k][0],j+=d[k][1])
			{
				if (mat[i][j]=='*') break;
				if (!mark[i][j])
				{
					mark[i][j]=cnt+1;
					Point pn;
					pn.y=i, pn.x=j;
					q.push(pn);
				}
				if (i==p[1].y && j==p[1].x) return;
            }
	}
}

int main()
{
	cin >> m >> n;
	int k=0;
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
		{
			cin >> mat[i][j];
			if (mat[i][j]=='C') p[k].y=i,p[k++].x=j;
		}
	floodfill();
	cout << cnt-1 << endl;
}
