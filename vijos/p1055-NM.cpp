#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
int ll, ww, n, x, y, a[3000][3000], l[3000][3000], r[3000][3000], h[3000][3000];
int R[3000][3000], L[3000][3000], ans;
void init()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d%d%d", &ll, &ww, &n);
    ll++;ww++;
    for (int i=1;i<=n;i++){
        scanf("%d%d", &x, &y);
        a[++x][++y]=1;
    }
}
void work()
{
     for (int i=1;i<=ll;i++)
         for (int j=1;j<=ww;j++){
             if (a[i][j-1]) l[i][j]=j-1;else l[i][j]=l[i][j-1];
             if (j==1)l[i][j]=1;
         }
     for (int i=1;i<=ll;i++)
         for (int j=ww;j>=1;j--){
             if (a[i][j+1]) r[i][j]=j+1;else r[i][j]=r[i][j+1];
             if (j==ww) r[i][j]=ww;
         }
     for (int i=1;i<=ll;i++)
         for (int j=1;j<=ww;j++)
         if (a[i-1][j]){
              h[i][j]=1;
              L[i][j]=1;
              }
         else{
              h[i][j]=h[i-1][j]+1;
              L[i][j]=max(l[i-1][j],L[i-1][j]);
              }
     for (int i=1;i<=ll;i++)
         for (int j=ww;j>=1;j--)
         if (a[i-1][j])R[i][j]=ww;
         else R[i][j]=min(R[i-1][j],r[i-1][j]);
     for (int i=1;i<=ll;i++)
         for (int j=1;j<=ww;j++)
             ans=max(ans,(R[i][j]-L[i][j])*h[i][j]);
    printf("%d\n", ans);
 }
int main()
{
    init();
    work();
    return 0;
}
