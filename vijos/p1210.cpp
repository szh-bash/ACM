#include<cstdio>
#include<iostream>
using namespace std;
int n,r;
int f[20][20];
int minn(int a,int b)
{
    if (a<b) return a;return b;
}
int main()
{
    scanf("%d%d", &n, &r);
    f[1][1]=1;
    for (int i=2;i<=n;i++)
      for (int j=1;j<=min(i,r);j++)
        f[i][j]=(f[i-1][j-1]+f[i-1][j])*j;
    cout<<f[n][r]<<endl;
    system("pause");
    return 0;
}
