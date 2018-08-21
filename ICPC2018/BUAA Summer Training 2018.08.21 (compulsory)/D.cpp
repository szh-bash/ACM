#include <bits/stdc++.h>
#define mod 1000000007
#define LL long long
#define N 300100
using namespace std;

char s[N];
int v[N];
int n,m,cnt;
LL ans;

LL qpow(LL a,int b)
{
	LL res=1;
	while (b)
	{
		if (b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}

int main()
{
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
    scanf("%d %d",&n,&m);
    scanf("%s",&s);
    for (int i=1;i<=n;i++) v[i]=s[i-1]-'0';
    LL now=0; cnt=0;
    for (int i=1;i<=n;i++)
    {
    	now=(now*10+v[i])%m;
    	if (now==0) cnt++;
    }
    if (cnt>0 && !now) ans=qpow(2,cnt-1); else ans=0;
	cout<<ans<<endl;
}
