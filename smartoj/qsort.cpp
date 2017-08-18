#include<cstdio>
#include<iostream>
using namespace std;
int v[300];
void qsort(int l, int r)
{
     int i, j, x, t;
     i= l;j= r;x= v[(i+j)/2];
     while (i<=j)
     {
           while (v[i]<=x) i++;
           while (v[j]>=x) j--;
           if (i<=j)
           {
                    t=v[i];v[i]=v[j];v[j]=t;
                    i++;j--;
            }
      }
      if (i<r) qsort(i,r);
      if (l<j) qsort(l,j);
 }
int main()
{
    int n, i;
    scanf("%d", &n);
    for (i=1; i<=n; i++)
      scanf("%d", &v[i]);
    qsort(1,n);
    for (i=1; i<=n; i++)
      printf("%d ", v[i]);printf("\n");
    getchar();
    getchar();
}
