#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
const long long INF=(long long)20000000*10000000;
int n;
double x[1001], y[1001], f[1001][1001], dist[1001][1001];
double min(double a, double b)
{
       if (a<b) return a;else return b;
}
void qsort(int l, int r)
{
         int i=l, j=r, mid=(i+j)/2;
         double xx=x[mid], tmp;
         do{
             while (x[i]<xx) i++;
             while (x[j]>xx) j--;
             if (i<=j){
                 tmp=x[i];x[i]=x[j];x[j]=tmp;
                 tmp=y[i];y[i]=y[j];y[j]=tmp;
                 i++;j--;
             }
         }while (i<=j);
         if (i<r) qsort(i,r);
         if (l<j) qsort(l,j);
}
int main()
{
    freopen("p1014.in","r",stdin);
    freopen("p1014.out","w",stdout);
    int n;
    scanf("%d", &n);
    for (int i=1;i<=n;i++)  
         cin>> x[i]>> y[i];
    qsort(1, n);
    for (int i=1;i<=n;i++)
       for (int j=1;j<=n;j++)
          dist[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
    for (int i=0;i<=n;i++)
      for (int j=0;j<=n;j++)
        f[i][j]=INF;
    f[1][1]=0;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=i;j++)
        {
            if (i==j)
              f[i][j]=min(f[i][i-1]+dist[i][i-1],f[i][j]);
            if (i==j+1)
              for (int k=1;k<=j;k++)
                f[i][j]=min(f[i][j], f[j][k]+dist[k][i]);
            if (i>j+1)
              f[i][j]=min(f[i][j],f[i-1][j]+dist[i-1][i]);
        }
    }
    printf("%.2lf\n", f[n][n]);
    return 0;
}
