#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
int n, m;
long long a[6000], f[6000][2000];
long long sqr(long long a) {return a*a;}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i=m;i>=1;i--) scanf("%d", &a[i]);
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++) f[i][j]=999999999;
    for (int i=3;i<=m;i++)
      for (int j=1;j<=i/3;j++)
        f[i][j]=min(f[i-1][j],f[i-2][j-1]+sqr(a[i]-a[i-1]));
    cout<<f[m][n]<<endl;
    system("pause");
    return 0;
}
