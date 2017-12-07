#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long LL;
typedef double ld;
const int MAX=100;
const LL INF=1000000000000000000LL;
LL f[MAX],k;
int p,num;
int work(LL a)
{
	if(!a)return 0;
	if(a==1)return 1;
	int i;
	for(i=num;i>=1;--i)
		if(f[i]<=a)
			return work(min(a-f[i],f[i+1]-a))+1;
	return 0;
}
int Main()
{
	scanf("%lld",&k);
	printf("%d\n",work(k));
	return 0;
}
int main()
{
	int i;
	for(f[0]=f[1]=1,i=2;f[i-1]<INF;++i)f[i]=f[i-1]+f[i-2];
	num=i-1;
	scanf("%d",&p);
	while(p--)
		Main();
	return 0;
}

