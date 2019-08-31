#include <bits/stdc++.h>
#define ll long long
#define N 110
using namespace std;

ll a[N],b[N];
ll m,k,r;
int n;

ll exgcd(ll a,ll b,ll &x,ll &y)
{
	if (!b) {x=1; y=0; return a;}
	ll d=exgcd(b,a%b,x,y); 
	ll t=x; x=y; y=t-a/b*y;
	return d;
}

int check(int i,int j)
{
	ll x,y;
	ll d=exgcd(a[i],a[j],x,y);
	if ((b[i]-b[j])%d) return 1;
}

int main()
{
	freopen("1.in","r",stdin);
	scanf("%d %lld",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d %d",&a[i],&b[i]);
	for (int i=1;i<=n;i++) for (int j=i+1;j<=n;j++) if (check(i,j))
	{
		puts("he was definitely lying");
		return 0;
	}
	k=a[1]; r=b[1];
	for (int i=2;i<=n;i++)
	{
		ll x,y; ll d=exgcd(k,a[i],x,y);
		x=(x*(r-b[i])/d+a[i]/d)%(a[i]/d); y=k/d*a;
		r=(x*k+r)%y; 
		k=y;
	}
}
