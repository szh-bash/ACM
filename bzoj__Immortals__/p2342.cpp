#include<map>
#include<set>
#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define ll long long
#define mod 1000000007
#define inf 1000000000
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,ans;
char ch[500005];
int p[500005],q[500005];
set<int> t;
void manacher()
{
	int mx=0,id;
	for(int i=1;i<=n;i++)
	{
		if(mx>=i)p[i]=min(mx-i,p[2*id-i]);
		else 
			p[i]=0;
		for(;ch[i+p[i]+1]==ch[i-p[i]];p[i]++);
		if(p[i]+i>mx)id=i,mx=p[i]+i;
	}
}
bool cmp(int a,int b)
{
	return (a-p[a])<(b-p[b]);
}
int main()
{
	n=read();
	scanf("%s",ch+1);
	ch[0]='#';
	manacher();
	for (int i=1;i<=n;i++) cout<<i<<' '<<p[i]<<endl; 
    for(int i=1;i<=n;i++)q[i]=i;
	sort(q+1,q+n+1,cmp);
	int now=1;
	for(int i=1;i<=n;i++)
	{
		while(now<=n&&q[now]-p[q[now]]<=i)
		{
			t.insert(q[now]);
			now++;
		}
		set<int>::iterator tmp=t.upper_bound(i+p[i]/2);
		if(tmp!=t.begin())
		{
			ans=max(ans,(*--tmp-i)*4);
		}
	}
	printf("%d\n",ans);
	return 0;
}
