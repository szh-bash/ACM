#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
struct zsm{
       int v,w;
}l[300000];
int n,m,fa[600],cnt,next[300000];
long long f[600][600],dist[600],va[600],qf[600],ans;
bool flag[600];
long long max(long long a,long long b){
     if (a>b)return a;return b;
}
long long min(long long a,long long b){
     if (a<b)return a;return b;
}
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d%d", &n, &m);
    int u,v,w;
    cnt=n;
    if (n%2==0) cnt++;
    for (int i=1;i<=m;i++){
        scanf("%d%d%d", &u, &v, &w);
        cnt++;next[cnt]=next[u];next[u]=cnt;l[cnt].v=v;l[cnt].w=w;
        cnt++;next[cnt]=next[v];next[v]=cnt;l[cnt].v=u;l[cnt].w=w;
    }
    memset(f,0,sizeof(f));
    memset(flag,0,sizeof(flag));
    long long INF=(long long)999999*10000000,q=INF;
    for (int i=2;i<=n;i++)
      dist[i]=INF;
    dist[1]=0;flag[1]=1;
    int tp=1;
          int j=next[tp];
          while (j>0){
                int v=l[j].v;
                if (flag[v]==0){
                    if (l[j].w<dist[v]){
                        dist[v]=l[j].w;
                        fa[v]=tp;
                        va[v]=l[j].w;
                        qf[v]=j;
                    }
                }
                j=next[j];
          }
    bool ff=1;
    int p=1;
    while (p<n){
          ff=false;
          long long tmp=INF;
          for (int i=1;i<=n;i++)
            if ((flag[i]==0)&&(dist[i]<tmp)){
                tmp=dist[i];
                tp=i;
            }
          if (tmp==INF) break;
          ff=true;
          int u=fa[tp];
          for (int i=1;i<=n;i++)
            if (flag[i])  f[i][tp]=f[tp][i]=max(f[i][fa[tp]],va[tp]);
          flag[tp]=1;
          ans+=dist[tp];
          j=next[tp];
          while (j>0){
                int v=l[j].v;
                if (flag[v]==0){
                    if (l[j].w<dist[v]){
                        dist[v]=l[j].w;
                        fa[v]=tp;
                        va[v]=l[j].w;
                        qf[v]=j;
                    }
                }
                else if ((j^qf[tp])!=1)q=min(q,l[j].w-f[v][tp]);
                j=next[j];
          }
          p++;
    }
    if (ff==false){
        cout<<"Cost: -1"<<endl<<"Cost: -1"<<endl;
    }
    else{
         cout<<"Cost: "<<ans<<endl;
         if (q==INF) cout<<"Cost: -1"<<endl;else cout<<"Cost: "<<ans+q<<endl;
    }
    return 0;
}
