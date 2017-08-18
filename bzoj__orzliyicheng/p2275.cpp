#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<cctype>
#include<cassert>
#include<climits>
using namespace std;
#define For(i,n) for(int i=1;i<=n;i++)
#define Rep(i,n) for(int i=0;i<n;i++)
#define Fork(i,k,n) for(int i=k;i<=n;i++)
#define ForD(i,n) for(int i=n;i;i--)
#define Forp(x) for(int p=pre[x];p;p=next[p])
#define RepD(i,n) for(int i=n;i>=0;i--)
#define MEM(a) memset(a,0,sizeof(a))
#define MEMI(a) memset(a,127,sizeof(a))
#define MEMi(a) memset(a,128,sizeof(a))
#define INF (2139062143)
#define F (1000000009)
#define MAXN (10000+10)
typedef long long ll;
ll f[MAXN];
int main()
{
//	freopen("bzoj2275.in","r",stdin);
	//freopen(".out","w",stdout);
	ll n;
	cin>>n;
	f[0]=f[1]=1;
	int size=1;y
	while (f[size]<n) size++,f[size]=f[size-1]+f[size-2];
	if (f[size]==n) {cout<<n<<endl; 
	system("pause");return 0;}
	while (n)
	{
		while (f[size]>n) size--;
		if (f[size]==n) 
		{
			cout<<f[size]<<endl;
	system("pause");return 0;
		}
		n-=f[size];
	}
	
	return 0;
}
