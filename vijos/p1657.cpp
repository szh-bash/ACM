#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
char name[300][1000];
int n, a[300], p[300], dist[300][300], next[200000], nu[200000], cnt, res[500], ff[500];
void init(){
     freopen("test.in","r",stdin);
     freopen("test.out","w",stdout);
     scanf("%d", &n);
     for (int i=1;i<=n;i++) scanf("%d", &a[i]);
     for (int i=1;i<=n;i++) scanf("%d", &p[i]);
     scanf("\n");
     for (int i=1;i<=n;i++) scanf("%s", name[i]);
     for (int i=1;i<=n;i++)
       for (int j=1;j<=n;j++) scanf("%d", &dist[i][j]);
}
void floyd(){
     for (int i=1;i<=n;i++)
       for (int j=1;j<=n;j++)  if (!dist[i][j])dist[i][j]=600000000;
     for (int i=1;i<=n;i++) dist[i][i]=0;
     for (int k=1;k<=n;k++)
       for (int i=1;i<=n;i++)
         for (int j=1;j<=n;j++)
           dist[i][j]=min(dist[i][k]+dist[k][j],dist[i][j]);
}
void add(int u, int v){
     next[++cnt]=next[u];next[u]=cnt;nu[cnt]=v;
     next[++cnt]=next[v];next[v]=cnt;nu[cnt]=u;
}
int dfs(int t){
    int j=next[t];
    while(j){
        int v=nu[j];
        if (!ff[v]){
                      ff[v]=1;
                      if (!res[v] || dfs(res[v])){
                                  res[v]=t;
                                  return 1;
                                  }
                      }
        j=next[j];
    }
    return 0;
}
int flag(int t){
    cnt=n*2;
    memset(next,0,sizeof(next));
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
          if (a[i]-dist[p[i]][j]<=t) add(i+n,j);
    memset(res,0,sizeof(res));
    for (int i=1;i<=n;i++){
        memset(ff,0,sizeof(ff));
        if (!dfs(i)) return 0;
    }
    return 1;
}
void erfen(){
     int le=0, ri=50000001;
     while (le<ri-1){
           int mid=(le+ri)/2;
           if (flag(mid)) ri=mid;else le=mid;
     }
     printf("%d\n", ri);
     for (int i=n+1;i<=2*n;i++)
         printf("%s\n", name[res[i]]);
}
int main(){
    init();
    floyd();
    erfen();
    return 0;
}
