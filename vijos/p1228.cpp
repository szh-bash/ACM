#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n, next[600], cnt, nu[600], f[600], x[600], y[600];
double ans, va[600];
int sqr(int x){return x*x;}
void init()
{
     freopen("test.in","r",stdin);
     freopen("test.out","w",stdout);
     scanf("%d", &n);
     for (int i=1;i<=n;i++)
       scanf("%d%d", &x[i], &y[i]);
     for (int i=1;i<=n;i++)
       scanf("%d%d", &x[i+n], &y[i+n]);
     cnt=2*n+1;
     for (int i=1;i<=n;i++)
       for (int j=n+1;j<=2*n;j++){
           next[++cnt]=next[i];next[i]=cnt;nu[cnt]=j;va[cnt]=sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]));f[cnt]=1;
           next[++cnt]=next[j];next[j]=cnt;nu[cnt]=i;va[cnt]=-sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]));
       }
     for (int i=1;i<=n;i++){
         next[++cnt]=next[0];next[0]=cnt;nu[cnt]=i;f[cnt]=1;
         next[++cnt]=next[i];next[i]=cnt;
         next[++cnt]=next[n+i];next[i+n]=cnt;nu[cnt]=2*n+1;f[cnt]=1;
         next[++cnt]=next[2*n+1];next[2*n+1]=cnt;nu[cnt]=i+n;
     }
 }
int work(){
     int e=0, tail=1, list[2000], u, v, fa[50], flag[50], j, fa2[50];
     double dist[50];
     memset(fa,0,sizeof(fa));
     memset(fa2,0,sizeof(fa2));
     memset(flag,0,sizeof(flag));
     for (int i=1;i<=2*n+1;i++) dist[i]=999999;
     flag[0]=1;
     dist[0]=0;
     list[1]=0;
     while (e!=tail){
       u=list[++e];
       flag[u]=0;
       j=next[u];
       while (j){
             v=nu[j];
             if (f[j] && dist[u]+va[j]<dist[v]){
                                        dist[v]=dist[u]+va[j];
                                        fa[v]=j;
                                        fa2[v]=u;
                                        if (!flag[v]){
                                                      flag[v]=1;
                                                      list[++tail]=v;
                                                      }
                                        }
             j=next[j];
             }
     }
     if (999999-dist[2*n+1]<0.00001) return 0;
     v=2*n+1;j=fa[v];
     while (v){
           f[j]--;
           f[j^1]++;
           ans+=va[j];
           v=fa2[v];
           j=fa[v];
           }
     return 1;
}
void mfmc()
{
     while (work());
     printf("%.3lf\n", ans);
 }
int main()
{
    init();
    mfmc();
    return 0;
}
