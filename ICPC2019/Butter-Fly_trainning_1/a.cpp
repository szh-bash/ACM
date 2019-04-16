#include<cstdio>

char g[200][200];

int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		for (int i = 1; i <= n; i++) scanf("%s", g[i]+1); 
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			bool state = 0;
			for (int j = 1; j <= m; j++)
			{
				if(g[i][j] == '/' || g[i][j] == '\\')
				{
					ans++;
					state = !state;
				}
				else
				{
					if(state)
					{
						ans+=2;
					}
				}
			}
		}
		printf("%d", ans/2);
	}
}
