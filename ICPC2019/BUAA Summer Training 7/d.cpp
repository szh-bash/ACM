#include <bits/stdc++.h>
#define N 1000100
#define K 210
#define ll long long
using namespace std;

int cnt[K];
ll sum[K];
int n;

int calc(int x)
{
	int res=0;
	while (x>0)
	{
		res=res+x%10;
		x/=10;
	}
	return res;
}

int main()
{
	freopen("digits.in","r",stdin);
	freopen("digits.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=N;i++)
	{
		int p=calc(i);
		cnt[p]++; sum[p]=sum[p]+i;
		if (cnt[p]==n)
		{
			printf("%lld\n",sum[p]);
			return 0;
		}
	}
}
