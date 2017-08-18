#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <set>
#include <map>
#include <cstring>
#include <time.h>
#define rep(i,n) for(int i=0;i<n;i++)
const int inf=~0U>>1,maxn=201;
using namespace std;
int A[maxn],B[maxn],P[maxn],n;
bool cmp(int i,int j)
{
return B[i]>B[j];
}
int Dp[2][maxn*maxn];
inline void Update(int&t,int c)
{
if(t==-1||t>c)t=c;
}
int main()
{
cin>>n;
rep(i,n)
{
cin>>A[i]>>B[i];
P[i]=i;
}
sort(P,P+n,cmp);
int now=0,next=1,sum=0;
memset(Dp[next],-1,sizeof Dp[next]);
Dp[next][0]=0;
for(int i=0;i<n;i++)
{
int t=P[i],c,first,second,nc;
swap(now,next);
memset(Dp[next],-1,sizeof Dp[next]);
rep(j,sum+1)
if((c=Dp[now][j])!=-1)
{
first=j;
second=sum-j;
nc=max(first+A[t]+B[t],c);
Update(Dp[next][j+A[t]],nc);
nc=max(second+A[t]+B[t],c);
Update(Dp[next][j],nc);
}
sum+=A[t];
}
int ans=inf;
rep(i,sum+1)if(Dp[next][i]!=-1)ans=min(ans,Dp[next][i]);
cout<<ans<<endl;
}
