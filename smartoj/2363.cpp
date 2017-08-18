#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
const int INF=0x7ffffff;
int n, m, q;
int v[300], num[300];
/*int cmp(int i,int j) {return i<j;}*/
int max(int a, int b, int c)
{
   if (a>b)
     if (a>c) return a; else return c;
   else
     if (b>c) return b; else return c;
}
void qsort(int l, int r)
{
     int i, j, x, t;
     i=l;j=r;x=v[(l+r)/2];
     while (i<=j)
     {
           while (v[i]<=x) i++;
           while (v[j]>=x) j--;
           if (i<=j) 
           {
                t=v[i];v[i]=v[j];v[j]=t;
                t=num[i];num[i]=num[j];num[j]=t;
                i++;j--;
            }
      }
     if (i<r) qsort(i,r);
     if (l<j) qsort(l,j);
 }
int main()
{
    freopen("2363.in", "r", stdin);
    freopen("2363.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &q);
    int i, j, k;
    for (i=1; i<=n; i++)
    {
        scanf("%d", &v[i]);
        num[i]= i;
     }
    qsort(1, n);
    int u0, v0, w0;
    int dis[300][300];
    for (i=1; i<=n; i++)
      for (j=1; j<=n; j++)
        if (i!=j) dis[i][j]=dis[j][i]=INF; 
    for (i=1; i<=n; i++)
        dis[num[i]][num[i]]=v[i];
    for (i=1; i<=m; i++)
    {
        scanf("%d%d%d", &u0, &v0, &w0);
        dis[u0][v0]= w0+max(v[u0], v[v0], 0);
        dis[v0][u0]= w0+max(v[u0], v[v0], 0);
    }
    int a, b, c;
    for (k=1; k<=n; k++)
      for (i=1; i<=n; i++)
        for (j=1; j<=n; j++)
        {
            a=num[i];b=num[j];c=num[k];
             if (dis[a][b]>dis[a][c]+dis[c][b]+max(v[a],v[b],v[c])-max(v[a],v[c],0)-max(v[c],v[b],0))
             {
                 dis[a][b]= dis[a][c]+dis[c][b]+max(v[a],v[b],v[c])-max(v[a],v[c],0)-max(v[c],v[b],0);
              }
        }
    for (i=1; i<=q; i++)
    {
        scanf("%d%d", &u0, &v0);
        printf("%d\n", dis[u0][v0]);
     }
  return 0;
}
