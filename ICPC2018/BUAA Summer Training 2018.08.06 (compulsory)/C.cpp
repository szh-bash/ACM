#include<bits/stdc++.h>
#define maxn 500100
#define LL long long
using namespace std;

set < LL > f1,f2,ans;
set < LL > ::iterator j;
LL v[maxn];
int n;

LL getgcd(LL a,LL b)
{
	while (b>0) {LL t=a; a=b; b=t%b;}
	return a;
}

int main()
{
	scanf("%d",&n); f1.clear(); f2.clear(); ans.clear();
	for (int i=1;i<=n;i++) scanf("%lld",&v[i]);
	for (int i=1;i<=n;i++)
	{
		if (i&1)
		{
			f1.clear();
			for (j=f2.begin();j!=f2.end();j++)
			{
				LL k=getgcd(v[i],*j);
				f1.insert(k); ans.insert(k);
			}
			f1.insert(v[i]); ans.insert(v[i]);
		}
		else
		{
			f2.clear();
			for (j=f1.begin();j!=f1.end();j++)
			{
				LL k=getgcd(v[i],*j);
				f2.insert(k); ans.insert(k);
			}
			f2.insert(v[i]); ans.insert(v[i]);
		}
	}
	cout<<ans.size()<<endl;
}
