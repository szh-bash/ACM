#include<set>
#include<map>
#include<ctime>
#include<queue>
#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define inf 9000000000000000000LL
#define mp make_pair
#define pa pair<ll,int>
#define ll long long 
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,K;
ll sum[100005],f[100005],g[100005];
int a[100005],q[100005];
int main()
{
	freopen("1.in","r",stdin);
	freopen("std.out","w",stdout); 
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++) cout<<a[i]<<' ';cout<<endl;
	return 0;
}
