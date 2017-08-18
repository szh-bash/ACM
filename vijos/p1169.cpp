#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
struct zsm{
       int x, y;
       char n[100];
}l[100];
int k, n, a[100][100], f[100][100], ans;
int sqr(int x)
{
    return x*x;
}
int ff(int u, int v)
{
    if (sqr(l[u].x-l[v].x)+sqr(l[u].y-l[v].y)>k*k) return 0;
    for (int i=1;i<=2*n;i++)
      if (i!=u && i!=v &&
      (l[i].x-l[u].x)*(l[i].x-l[v].x)<=0 &&
      (l[i].y-l[v].y)*(l[i].y-l[u].y)<=0 &&
      (l[i].y-l[u].y)*(l[i].x-l[v].x)==(l[i].y-l[v].y)*(l[i].x-l[u].x)) return 0;
    return 1;
}
void predoing(char *s)
{
     int len=strlen(s);
     for (int i=0;i<len;i++) s[i]=tolower(s[i]);
 }
void init()
{
     freopen("test.in","r",stdin);
     freopen("test.out","w",stdout);
    scanf("%d%d\n", &k, &n);
    for (int i=1;i<=2*n;i++) scanf("%d%d%s\n", &l[i].x, &l[i].y, l[i].n);
    for (int i=1;i<=2*n;i++) predoing(l[i].n);
    char aa[100], b[100];
    int p, u, v;
    scanf("%s", aa);
    while (strcmp("End",aa)){
          scanf("%s%d\n", b, &p);
          predoing(aa);predoing(b);
          for (int i=1;i<=n*2;i++)if (!strcmp(l[i].n,aa)) {u=i;break;}
          for (int i=1;i<=n*2;i++)if (!strcmp(l[i].n,b)) {v=i;break;}
          int tmp=min(u,v);v=u+v-tmp;
          a[tmp][v]=p;a[v][tmp]=-p;
          scanf("%s", aa);
          }
    for (int i=1;i<=n;i++)
        for (int j=n+1;j<=n*2;j++)
            if (!a[i][j]) {a[i][j]=1;a[j][i]=-1;}
    for (int i=1;i<=n;i++)
      for (int j=n+1;j<=2*n;j++)
        if (ff(i,j))f[i][j]=1;
    for (int i=1;i<=n;i++)f[0][i]=f[i+n][n*2+1]=1;
}
int work()
{
    int e=0, tail=1, list[50000], flag[100], dist[100], fa[100];
    memset(flag,0,sizeof(flag));
    for (int i=1;i<=2*n+1;i++)
      dist[i]=-999999;
    dist[0]=0;
    flag[0]=1;
    int u;
    list[1]=0;
    while (e!=tail){
          u=list[++e];
          flag[u]=0;
          for (int i=0;i<=2*n+1;i++)
            if (f[u][i] && dist[u]+a[u][i]>dist[i]){
                        dist[i]=dist[u]+a[u][i];
                        fa[i]=u;
                        if (!flag[i]){
                                      flag[i]=1;
                                      list[++tail]=i;
                                      }
                         }
          }
    if (dist[n*2+1]==-999999) return 0;
    int j=2*n+1;
    while (j){
          u=fa[j];
          f[u][j]--;
          f[j][u]++;
          ans+=a[u][j];
          j=u;
          }
    return 1;
}
void mfmc()
{
     while (work());
     cout<<ans<<endl;
 }
int main()
{
    init();
    mfmc();
    return 0;
}
