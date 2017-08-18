#include <cstdio> 
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int t[1000000],son[1000000],next[1000000],pass[1000000],tot[1000000];
int n,m,i,j,k,l,num,p,point,ans;
bool finish;

int main()
{
scanf("%d%d",&n,&m);
for(i=1;i<=n;++i)        //½¨Ê÷
{
	scanf("%d",&l);
	p=0;
	for(j=1;j<=l;++j)
	{
	scanf("%d",&num);
	for(k=son[p];k;k=next[k])
	if(t[k]==num)break;
	if(k!=0)
	{
	p=k;
	++pass[k];
	}
	else
	{
	++point;
	next[point]=son[p];
	son[p]=point;
	p=point;
	t[p]=num;
	++pass[p];
	}
	}
	--pass[p];
	++tot[p];
	}
	for(i=1;i<=m;++i)     //²éÑ¯
	{
	ans=0;
	scanf("%d",&l);
	p=0;
	finish=true;
	for(j=1;j<=l;++j)
	{
		scanf("%d",&num);
		for(k=son[p];k;k=next[k])
		if(t[k]==num)break;
		if(k!=0)
		{
			p=k;
			if(tot[k]!=0)ans+=tot[p];
		}
		else
		{
			finish=false;
			break;
		}
	}
	if(finish)ans+=pass[p];
	for(k=j+1;k<=l;++k)scanf("%d",&num);
	printf("%d\n",ans);
	}	
	system("pause");
}
	
