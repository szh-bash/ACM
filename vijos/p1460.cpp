#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
int w, m, total=0, n, u, v, va[10002][2000], s[10002][2000], nu[10002], fa[10002][20], dep[10002];
long long ans=0, f[10002];
void dfs(int t, int d)
{
     
     dep[t]=d;
     for (int i=1;i<=20;i++)
       {
              fa[t][i]=fa[fa[t][i-1]][i-1];
              if (fa[t][i]==0) break;
       }
     for (int i=1;i<=nu[t];i++)
     {
          f[s[t][i]]= long(long(va[t][i])+f[t]);
          dfs(s[t][i],d+1);
     }
 }
void work(int v, int deep)
{
    int tmp=v;
    for (int i=0;i<=20;i++)
        if (deep&1<<i) tmp=fa[tmp][i];
    if (tmp!=u) return;
    total++;
    ans= long(ans+f[v]-f[u]);
}
int main()
{
    freopen("p1460.in","r",stdin);
    freopen("p1460.out","w",stdout);
    scanf("%d%d", &n, &m);
    for (int i=1;i<=n-1;i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        nu[u]++;
        s[u][nu[u]]=v;
        va[u][nu[u]]=w;
        fa[v][0]=u;
    }
    dfs(1,1);
    for (int i=1;i<=m;i++)
    {
        scanf("%d%d", &u, &v);
        if (dep[u]>=dep[v]) continue;
        work(v,dep[v]-dep[u]);
    }
    printf("%d\n%lld\n", total, ans);
    return 0;
}
