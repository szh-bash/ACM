#include <bits/stdc++.h>
#define mod 998244353
#define N 3010
#define ll long long
using namespace std;

ll fac[N+10],inv[N+10];
int f1[N+10],f2[N+10];
ll bit[N*N+10], q[N][N];
int n,m,A,B;

ll qpow(ll a,int b)
{
	ll res=1;
	while (b>0)
	{
		if (b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}

void prework()
{
	fac[0]=1; for (int i=1;i<=N;i++) fac[i]=fac[i-1]*i%mod;
	inv[0]=1; for (int i=1;i<=N;i++) inv[i]=inv[i-1]*qpow(i,mod-2)%mod;
	//inv[N]=qpow(N,mod-2); for (int i=N-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
	bit[0]=1; for (int i=1;i<=N*N;i++) bit[i]=(bit[i-1]+bit[i-1]), bit[i]>=mod?(bit[i]-=mod):0;
	for (int i=0;i<N;i++)
		for (int j=0;j<N;j++){
			ll tmp=1;
			tmp=tmp*inv[i]%mod;
			tmp=tmp*inv[j]%mod;
			tmp=tmp*bit[i*j]%mod;
			q[i][j]=tmp;
		}
}
int add(int x, int y){
	if (x+y>=mod) return x+y-mod;
	return x+y;
}
int sub(int x, int y){
	if (x-y<0) return x-y+mod;
	return x-y;
}
void work()
{
	for (int i=0;i<=n-A;i++) 
	{
		f1[i]=0;
		for (int j=0;j<=n-A-i;++j)
			if (!(j&1)) f1[i]=add(f1[i],1LL*inv[n-i-j]*inv[j]%mod);
				else f1[i]=sub(f1[i],1LL*inv[n-i-j]*inv[j]%mod);
	}
	for (int i=0;i<=m-B;++i)
	{
		f2[i]=0;
		for (int j=0;j<=m-B-i;++j) 
			if (!(j&1)) f2[i]=add(f2[i],1LL*inv[m-i-j]*inv[j]);
				else f2[i]=sub(f2[i],1LL*inv[m-i-j]*inv[j]);
	}
	ll ans=0;
	for (int i=0;i<=n-A;i++)
		for (int j=0;j<=m-B;j++) 
		{
			ll tmp=1LL*f1[i]*f2[j]%mod;
			ans=(ans+tmp*q[i][j])%mod;
		}
	ans=ans*fac[n]%mod;
	ans=ans*fac[m]%mod;
	printf("%lld\n",ans);
}

int main()
{
	freopen("f.in","r",stdin);
	prework();
	while (scanf("%d %d %d %d",&n,&m,&A,&B)!=EOF) work();
}
