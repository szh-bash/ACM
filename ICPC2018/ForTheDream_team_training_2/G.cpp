#include <bits/stdc++.h>
#define LL long long
#define N 150100
#define K 21
using namespace std;

int n;
char s[N];
int nxt[N][K+10], bef[N][K+10];
int rk[N],sa[N],trk[N],tsa[N],tmp[N],sum[N],h[N];

inline void getsa(int n,int m)
{
	for (int i=1;i<=m;i++) sum[i]=0; 
	for (int i=1;i<=n;i++) trk[i]=(int)s[i-1],sum[trk[i]]++;
	for (int i=1;i<=m;i++) sum[i]+=sum[i-1];
	for (int i=n;i>=1;i--) sa[sum[trk[i]]--]=i;
	int p=1; rk[sa[1]]=1;
	for (int i=2;i<=n;i++)
	{
		if (trk[sa[i]]!=trk[sa[i-1]]) p++;
		rk[sa[i]]=p;
	}
	m=p; int j=0, o=1;
	while (o<n)
	{
		/*
		p=0;
		for (int i=n-j+1;i<=n;i++) tsa[++p]=i;
		for (int i=1;i<=n;i++) if (sa[i]>j) tsa[++p]=sa[i]-j;
		*/
		for (int i=1;i<=n;i++) tsa[i]=bef[sa[i]][j];
		//
		for (int i=1;i<=m;i++) sum[i]=0;
		for (int i=1;i<=n;i++) tmp[i]=rk[tsa[i]],++sum[tmp[i]];
		for (int i=1;i<=m;i++) sum[i]+=sum[i-1];
		for (int i=n;i>=1;i--) sa[sum[tmp[i]]--]=tsa[i];
		for (int i=1;i<=n;i++) trk[i]=rk[i]; p=1; rk[sa[1]]=1;
		for (int i=2;i<=n;i++)
		{
			if (trk[sa[i]]!=trk[sa[i-1]]||trk[nxt[sa[i]][j]]!=trk[nxt[sa[i-1]][j]]) ++p;
			rk[sa[i]]=p;
		}
		m=p; j++;o<<=1;
		//cout<<m<<' '<<o<<endl;
	}
	
}


inline void work()
{
	scanf("%d",&n); scanf("%s",s);
	for (int i=0;i<n;i++) nxt[i][0]=((LL)i*i+1)%n;
	for (int i=n;i>=1;i--) nxt[i][0]=nxt[i-1][0]+1;
	for (int j=1;j<=K;j++) 
		for (int i=1;i<=n;i++) nxt[i][j]=nxt[nxt[i][j-1]][j-1];
	for (int i=1;i<=n;i++)
		for (int j=0;j<=K;j++)
			bef[nxt[i][j]][j]=i;	
	getsa(n,255);
	int now=sa[n];
	for (int i=1;i<=n;i++) 
	{
		putchar(s[now-1]); now=nxt[now][0];
	}
	puts("");
}

int main()
{
	int cas; scanf("%d",&cas);
	for (int i=1;i<=cas;i++) 
	{
		printf("Case #%d: ",i);
	    work();
	}
}
