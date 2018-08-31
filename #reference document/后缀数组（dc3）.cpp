#include <bits/stdc++.h>
#define N 50100
#define F(x) ((x)/3+((x)%3==1?0:tb))
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)
using namespace std;

char s[N];
int sa[10*N],rk[N],h[N];
int r[10*N],wa[10*N],wb[10*N],wv[10*N];
int wws[10*N];
int n;

void sort(int *r,int *a,int *b,int n,int m)
{
    int i;
    for(i=0;i<n;i++) wv[i]=r[a[i]];
    for(i=0;i<m;i++) wws[i]=0;
    for(i=0;i<n;i++) wws[wv[i]]++;
    for(i=1;i<m;i++) wws[i]+=wws[i-1];
    for(i=n-1;i>=0;i--) b[--wws[wv[i]]]=a[i];
    return;
}
int c0(int *r,int a,int b) {return r[a]==r[b]&&r[a+1]==r[b+1]&&r[a+2]==r[b+2];}

int c12(int k,int *r,int a,int b)
{
    if(k==2) return r[a]<r[b]||(r[a]==r[b]&&c12(1,r,a+1,b+1));
    else     return r[a]<r[b]||(r[a]==r[b]&&wv[a+1]<wv[b+1]);
}


void dc3(int *r,int *sa,int n,int m)
{
    int i,j,*rn=r+n,*san=sa+n,ta=0,tb=(n+1)/3,tbc=0,p;
    r[n]=r[n+1]=0;
    for(i=0;i<n;i++) if(i%3!=0) wa[tbc++]=i;
    sort(r+2,wa,wb,tbc,m);
    sort(r+1,wb,wa,tbc,m);
    sort(r,wa,wb,tbc,m);
    for(p=1,rn[F(wb[0])]=0,i=1;i<tbc;i++) rn[F(wb[i])]=c0(r,wb[i-1],wb[i])?p-1:p++;
    if(p<tbc) dc3(rn,san,tbc,p);
    else for(i=0;i<tbc;i++) san[rn[i]]=i;
    for(i=0;i<tbc;i++) if(san[i]<tb) wb[ta++]=san[i]*3;
    if(n%3==1) wb[ta++]=n-1;
    sort(r,wb,wa,ta,m);
    for(i=0;i<tbc;i++) wv[wb[i]=G(san[i])]=i;
    for(i=0,j=0,p=0;i<ta && j<tbc;p++)
          sa[p]=c12(wb[j]%3,r,wa[i],wb[j])?wa[i++]:wb[j++];
    for(;i<ta;p++) sa[p]=wa[i++];
    for(;j<tbc;p++) sa[p]=wb[j++];
}

void geth()
{
	int j=0,k; h[1]=0;
	for (int i=1;i<=n;i++) if (rk[i]>1)
	{
		k=sa[rk[i]-1];
		while (i+j<=n&&k+j<=n&&s[i+j-1]==s[k+j-1]) j++;
		h[rk[i]]=j; if (j>0) j--;
	}
}


int main()
{
	scanf("%s\n",s); 
	n=strlen(s); int m=255;                   //s从0开始   n长度  m字符集大小 
	for (int i=0;i<n;i++) r[i]=(int)s[i]; r[n]=0;
	dc3(r,sa,n+1,m+1);			              //dc3过程后r会被破坏  
	for (int i=1;i<=n;i++) rk[sa[i]]=i;
	for (int i=1;i<=n;i++) sa[i]++;
	for (int i=n;i>0;i--) rk[i]=rk[i-1];      //sa、rk均从下标1开始 
	geth();									  
	for (int i=1;i<=n;i++) printf("%d ",rk[i]); puts("");
	for (int i=1;i<=n;i++) printf("%d ",h[i]);  puts("");
}
