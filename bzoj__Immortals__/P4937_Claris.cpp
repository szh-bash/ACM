/*
f[i][j]前i个测试点划分成j个子任务，得分的最小值
g[i][j]表示第j个选手，在第i个测试点之前最晚一次fail的位置
那么w(k,i]=sum_{x=1}^n [g[i][x]<=k]
f[i][j]=min(f[k][j-1]+w(k,i])*(s[i]-s[k]))=min(min(f[k][j-1]-w*s[k])+w*s[i])
枚举w至多是多少，查询前缀最小值
时间复杂度O(nts)
*/
#include<cstdio>
#include<algorithm>
const int N=20005,M=55,inf=2000000010;
int n,m,K,o,i,j,k,t,x,a[N],g[N][M],f[2][N],v[N][M];char s[N];
inline void up(int&x,int y){if(x>y)x=y;}
int main(){
  scanf("%d%d%d",&n,&m,&K);
  for(i=1;i<=m;i++)scanf("%d",&a[i]),a[i]+=a[i-1];
  for(i=0;i<n;i++)for(scanf("%s",s+1),j=1;j<=m;j++)g[j][i]=s[j]=='0'?j:g[j-1][i];
  for(i=1;i<=m;i++)std::sort(g[i],g[i]+n),f[0][i]=inf;
  while(K--){
    for(j=0;j<=n;j++)v[0][j]=f[o][0];
    for(f[o^=1][0]=inf,i=1;i<=m;i++){
      t=inf,k=a[i];
      if(v[i-1][n]<inf)t=v[i-1][n]+n*k;
      for(j=0;j<n;j++)if(x=g[i][j])if(v[x-1][j]<inf)up(t,v[x-1][j]+j*k);
      f[o][i]=t;
      t=f[o^1][i];
      if(t==inf)for(j=0;j<=n;j++)v[i][j]=v[i-1][j];
      else for(j=0;j<=n;j++)up(v[i][j]=v[i-1][j],t-j*k);
    }
    printf("%d\n",f[o][m]);
  }
  return 0;
}