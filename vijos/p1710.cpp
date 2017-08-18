#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
int n, q, x, fa[20001][21], dep[20001], maxx=0;
long long y, f[20001], c[20001];
bool flag[20001];
void dfs(int t)
{
     if (fa[t][0]==-1) fa[t][0]=0;
     if (flag[fa[t][0]]==0) dfs(fa[t][0]);
     dep[t]=dep[fa[t][0]]+1;
     if (dep[t]>maxx) maxx=dep[t];
     if ((dep[t]&1)==0)c[t]=-c[t];
     f[t]=f[fa[t][0]]+c[t];
     flag[t]=1;
     for (int i=1;i<=20;i++)
         if (fa[t][i-1]) fa[t][i]=fa[fa[t][i-1]][i-1];
 } 
void up(int &x, int p)
{
     for (int i=0;i<=20;i++)
     if (p&(1<<i)) x=fa[x][i];
     
 }
int father(int x, int y)
{
    up(x,dep[x]-dep[y]);
    if (x==y) return(x);
    for (int i=20;i>=0;i--)
        if (fa[x][i]!=fa[y][i]) 
            {x=fa[x][i];y=fa[y][i];};
    return(fa[x][0]);
}
void update(int x, long long y)
{
     if ((x&1)==0) y=-y;
     while (x<=maxx)
     {
           c[x]=c[x]+y;
           x+=x&(x^(x-1));
     }
 }
long long sum(int x)
{
    long long j=0;
    while (x)
    {
          j=j+c[x];
          x-=x&(x^(x-1));
    }
    return j;
}
long long abss(long long x)
{
     if (x<0) x=-x;
     return(x);
 }
int main()
{
    freopen("p1710.in","r",stdin);
    freopen("p1710.out","w",stdout);
    scanf("%d%d\n", &n, &q);
    for (int i=1;i<=n;i++)
        scanf("%lld", &c[i]);
    for (int i=1;i<=n;i++)
        scanf("%d\n", &fa[i][0]);
    for (int i=1;i<=n;i++)
        flag[i]=0;
    flag[0]=1;
    for (int i=1;i<=n;i++)
        if (flag[i]==0) dfs(i);
    for (int i=0;i<=n;i++)
        c[i]=0;
    char ch;
    int tmp;
    for (int i=1;i<=q;i++)
    {
        scanf("%c%d%lld\n", &ch, &x, &y);
        if (ch=='M') update(x,y);
        else
        {
            if (dep[x]>dep[y]) tmp=father(x,y);
                          else tmp=father(y,x);
            printf("%lld\n", abss(f[y]+f[x]-f[tmp]-f[fa[tmp][0]]+sum(dep[y])+sum(dep[x])-sum(dep[tmp])-sum(dep[tmp]-1)));
        }
    }
    return 0;
}
