#include <bits/stdc++.h>
#define maxn 1000000
#define mod 9999991
#define LL long long
typedef unsigned long long ull;
using namespace std;

ull bit[maxn+5],bit2[maxn+5], hashh[maxn+5], g[maxn+5], hs[maxn+5], gt[maxn+5];
int pos[maxn+5],countt[maxn+5];
int n, len,cnt;
char s[maxn+5];
struct qlz{
	int n;
	ull hs, gt;
}l[maxn+5];


bool cmphx(qlz a, qlz b){
	return a.hs<b.hs || a.hs==b.hs && a.gt<b.gt || a.hs==b.hs && a.gt==b.gt && a.n<b.n;
}

bool cmp2(int a, int b){
	return l[a].n<l[b].n;
}
void put(int x, int k)  
{
	if (k) putchar(' ');
 	if (x==0) {printf("0"); return;}   
    int num = 0; char c[15];
    while(x) c[++num] = (x%10)+48, x /= 10;
    while(num) putchar(c[num--]);
}
int main()
{
//	freopen("1.in","r",stdin);
//	freopen("std.out","w",stdout);
	gets(s);
	len=strlen(s);
	bit[0]=bit2[0]=1;
	for (int i=1;i<=len;i++) bit[i]=bit[i-1]*26, bit2[i]=bit2[i-1]*41;
	hashh[0]=hs[0]=s[0]-'a';
	for (int i=1;i<len;i++) 
		hashh[i]=hashh[i-1]+bit[i]*(s[i]-'a'),
		hs[i]=hs[i-1]+bit2[i]*(s[i]-'a');
	for (int i=len-1;i>=0;i--)
		g[i]=g[i+1]*26+(s[i]-'a'),
		gt[i]=gt[i+1]*41+(s[i]-'a');
	for (int i=0;i<len;i++)
	{
		ull k=g[i]+(i?hashh[i-1]*bit[len-i]:0), k2=gt[i]+(i?hs[i-1]*bit2[len-i]:0);
		//int y=k%mod, y2=k2%mod;
		l[i].hs=k;
		l[i].gt=k2;
		l[i].n=i;
		//cout<<i<<' '<<y<<' '<<y2<<endl;
	}
	n=len;
	sort(l,l+n,cmphx);
	pos[countt[1]=cnt=1]=0;
	for (int i=1;i<n;i++){
		if (l[i].hs!=l[i-1].hs || l[i].gt!=l[i-1].gt) pos[++cnt]=i;
		countt[cnt]++;
	}
	sort(pos+1,pos+1+cnt,cmp2);
	printf("%d\n", cnt);
	for (int i=1;i<=cnt;i++){
		put(countt[i],0);
		for (int j=1;j<=countt[i];j++)
			put(l[pos[i]+j-1].n,1);printf("\n");
	}
	return 0;
}
