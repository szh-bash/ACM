#include <bits/stdc++.h>
#define LL long long
#define N 100100
#define inf 1000000007
using namespace std;

char s[N],t[N];
int f[N],pre[N][2],tmp[N][2],cnt[N];
int n,k,l,r;

struct node1
{
	int p[N],v[N];
	int l,r;
	void init()
	{
		p[1]=v[1]=0; l=r=1;
	}
	
	void ins(int x,int y)
	{
		while (l<=r&&y<=v[r]) r--;
		p[++r]=x; v[r]=y;
	}
	
	int get(int x)
	{
		while (l<=r&&x-p[l]>k) l++;
		return v[l];
	}
}que[2];


int main()
{
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	scanf("%d %d\n",&n,&k);
	scanf("%s\n",t+1);
	scanf("%s\n",s+1);
	for (int c=0;c<=1;c++)
	{
		char ch;
		if (c==0) ch='B'; else ch='W';
		pre[0][0]=0; cnt[0]=0;
		for (int i=1;i<=n;i++)
		{
			cnt[i]=cnt[i-1];
			if (s[i]==ch&&s[i-1]!=s[i]) cnt[i]++;
			pre[i][c]=cnt[i];
			tmp[i][c]=-cnt[i]+(s[i]==ch&&s[i+1]==ch);
		}
	}
	que[0].init(); que[1].init();
	for (int i=1;i<=n;i++)
	{
		f[i]=inf;
		if (s[i]==t[i]) f[i]=f[i-1];
		for (int c=0;c<=1;c++) f[i]=min(f[i],que[c].get(i)+1+pre[i][c]);
		for (int c=0;c<=1;c++) que[c].ins(i,f[i]+tmp[i][c]);
	}
	printf("%d\n",f[n]);
}
