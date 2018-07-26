#include <bits/stdc++.h>
#define maxn 10000000
#define LL long long
using namespace std;

int prime[maxn+5],p[maxn+5];
int n,pos;
LL ans;

int main()
{
	scanf("%d",&n);
	for (int i=2;i<=n;i++) 
	{
		if (p[i]==0) prime[++prime[0]]=i;
		for (int j=1;j<=prime[0];j++)
		{
			if (i*prime[j]>n) break;
			p[i*prime[j]]=1;
			if (i%prime[j]==0) break;
		}
	}
	pos=prime[0]; ans=0;
	for (int g=1;g<=n;g++)
	{
		while (g*prime[pos]>n&&pos>0) pos--; if (pos==0) break;
		ans+=(LL)pos*(pos-1)/2;
	}
	ans=ans*2;
	printf("%lld\n",ans);
}
