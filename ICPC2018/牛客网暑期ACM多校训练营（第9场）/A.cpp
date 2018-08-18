#include <bits/stdc++.h>
#define maxn 300100
#define maxk 50
#define mod 1000000007
#define LL long long
using namespace std;

int x[maxn*maxk],pa[maxn*maxk],pb[maxn*maxk];
int a[maxn],b[maxn];
int n,tot1,tot2;

int qpow(int a,int b)
{
	int res=1;
	while (b)
	{
		if (b&1) res=(LL)res*a%mod;
		a=(LL)a*a%mod;
		b>>=1;
	}
	return res;
}

int dfs(int st,int step,int len)
{
	if (len==1)
	{
		tot1++; 
		x[tot1]=((LL)pb[st]*qpow(pa[st],mod-2))%mod;
		return tot1;
	}
	int now=tot2+1;
	for (int i=1;i<=len/2;i++)
	{
		pa[++tot2]=((LL)pa[st+len/2+i-1]-pa[st+i-1]+mod)%mod;
		pb[tot2]=(pb[st+len/2+i-1]-pb[st+i-1]+mod)%mod;
	}
	int t1=dfs(now,step+1,len/2);
	now=tot2+1; 
	for (int i=1;i<=len/2;i++)
	{
		pa[++tot2]=(pa[st+len/2+i-1]+pa[st+i-1])%mod;
		pb[tot2]=(pb[st+len/2+i-1]+pb[st+i-1])%mod;
	}
	int t2=dfs(now,step+1,len/2);
	int res=tot1+1;
	for (int i=1;i<=len/2;i++) x[++tot1]=(x[t2+i-1]+x[t1+i-1])/2;
	for (int i=1;i<=len/2;i++) x[++tot1]=(x[t2+i-1]-x[t1+i-1])/2;
	return res;
}

int main()
{
//	freopen("1.in","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),pa[i]=a[i];
	for (int i=1;i<=n;i++) scanf("%d",&b[i]),pb[i]=b[i];
	tot2=n;
	int pos=dfs(1,1,n);
	for (int i=0;i<n;i++) printf("%d\n",(x[pos+i]+mod)%mod);
}
