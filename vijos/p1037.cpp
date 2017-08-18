#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
int n,f[200][4000],h[110];
int maxxx(int a,int b,int c)
{
    if (a>b) 
      {if (a>c) return a; else return c;}
    else
      {if (b>c) return b; else return c;}
}
int main()
{
    scanf("%d", &n);
    for (int i=1;i<=n;i++) 
        scanf("%d", &h[i]);
    for (int i=0;i<=n;i++)
      for (int j=0;j<=4000;j++)
        f[i][j]=-9999999;
    f[0][0]=0;
    for (int i=1;i<=n;i++)
      for (int j=0;j<=2000;j++){
          if (j<=h[i])
              f[i][j]=maxxx(f[i-1][j],f[i-1][h[i]-j]+j,f[i-1][j+h[i]]);
          else
              f[i][j]=maxxx(f[i-1][j],f[i-1][j-h[i]]+h[i],f[i-1][j+h[i]]);
      }
    if (f[n][0]<=0) cout<<"Impossible"<<endl;else cout<<f[n][0]<<endl;
    system("pause");
    return 0;
}
