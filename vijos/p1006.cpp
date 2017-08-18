#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
const int INF=0xfffffff;
bool flag;
int a[1002][1002], f[1002][1002];
int min(int a,int b)
{
    if (a>b)
    {
            flag=true;
            return(b);
    }
    else return(a);
}
int main()
{
    freopen("p1006.in","r",stdin);
    freopen("p1006.out","w",stdout);
    int n;
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
      {
              for (int j=1; j<=i; j++)
                {
                       scanf("%d", &a[i][j]);
                       f[i][j]=INF;
                }
       }
    f[1][1]=f[1][2]=f[1][0]=a[1][1];
    for (int i=2; i<=n; i++)
    {
        flag=true;
        while (flag)
        {
             f[i][0]=f[i][i];f[i][i+1]=f[i][1]; 
             flag=false;
             for (int j=1; j<=i; j++)
             {
                 f[i][j]=min(f[i][j],f[i-1][j-1]+a[i][j]);
                 f[i][j]=min(f[i][j],f[i-1][j]+a[i][j]);
                 f[i][j]=min(f[i][j],f[i][j-1]+a[i][j]);
                 f[i][j]=min(f[i][j],f[i][j+1]+a[i][j]);
             }
        }
    }
    printf("%d\n", f[n][1]);
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=i;j++)
          printf("%d ", f[i][j]);printf("\n");
    }
    return 0;
}
