#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define ll long long
#define inf 1000000000 
using namespace std;
inline int read()
{
    int x=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x;
}
int n,m,cnt;
int p[200005],t[100005];
char ch[100005],a[200005];
struct seg{
	int l,r;
}l[100005];
int query(int x)
{
	if(!x)return 0;
	int tmp=inf;
	for(int i=x;i<=n;i+=i&-i)tmp=min(t[i],tmp);
	return tmp;
}
void modify(int x,int val)
{
	for(int i=x;i;i-=i&-i)t[i]=min(t[i],val);
}
bool operator<(seg a,seg b)
{
	return a.r<b.r;
}
void add(int x,int y)
{
	x=x/2+1;y=y/2-1;
	if(x>y)return;
	l[++cnt]=(seg){x,y};
}
void manacher()
{
	m=2*n+1;
	for(int i=1;i<=n;i++)
	{
		a[i<<1]=ch[i];
		a[i<<1|1]='#';
	}
	a[0]='+';a[1]='#';a[m+1]='-';
	int mx=0,id;
	for(int i=1;i<=m;i++)
	{
		if(mx>i)p[i]=min(mx-i,p[2*id-i]);
		else p[i]=1;
		for(;a[i-p[i]]==a[i+p[i]];p[i]++);
		add(i-p[i],i+p[i]);
		if(p[i]+i>mx)mx=p[i]+i,id=i;
	}
}
int main()
{
	freopen("1.in","r",stdin);
	//freopen("std.out","w",stdout);
	while(~scanf("%s",ch+1))
	{
		cnt=0;
		n=strlen(ch+1);for(int i=1;i<=n;i++)t[i]=inf;
		manacher();
		sort(l+1,l+cnt+1);
		int ans=inf;
		for(int i=1;i<=cnt;i++)
		{	cout<<l[i].l<<' '<<l[i].r<<endl;
			int x=query(l[i].l-1)+1;
			modify(l[i].r,x);
			if(l[i].r==n)ans=min(ans,x);
		}
		printf("%d\n",ans-1);
	}
	return 0;
}
