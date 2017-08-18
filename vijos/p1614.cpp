#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
int n, m, p[30], flag[4100];
long long ans, dp[15][4100];
int main()
{
    scanf("%d", &n);
    int tmp=n;
    n=1+(int)(log(n)/log(4));
    int a=1, b, x[30], cnt;
    for (int i=0;i<=n;i++){
        b=a;
        p[i]=0;
        while (b<=tmp){
              p[i]++;
              b*=5;
              }
        a*=4;
    }
    for (int i=0;i<=(1<<p[0]);i++){
        a=i;cnt=0;
        while (a){x[++cnt]=a%2;a/=2;}
        flag[i]=1;
        for (int j=1;j<cnt;j++)
            if (x[j]==x[j+1] && x[j]) flag[i]=0;
    }
    for (int i=0;i<=(1<<p[0])-1;i++) dp[0][i]=1;
    for (int i=1;i<=n;i++){
        for (int j=0;j<=(1<<p[i-1])-1;j++) 
          for (int k=0;k<=(1<<p[i])-1;k++)
            if (flag[j] && flag[k] && !(j&k)){
                dp[i][k]+=dp[i-1][j];
                dp[i][k]=dp[i][k]%100000000;
            }
    }
    for (int i=0;i<=(1<<p[n])-1;i++)
        if (flag[i]) ans=(ans+dp[n][i])%100000000;
    printf("%d\n", ans);
    system("pause");
    return 0;
}
