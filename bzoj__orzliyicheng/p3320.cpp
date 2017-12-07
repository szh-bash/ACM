#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i=1;i<=n;++i)
#define imax(x,y) (x>y?x:y)
#define imin(x,y) (x<y?x:y)
using namespace std;
const int N=100010,BIG=1000000000,M=100000;
struct D
{
   int dist,num;
}di[N];
int firste[N],nexte[N<<1],v[N<<1],w[N];
int sz[N],lim[N],b[N],numq[N],cnt[N<<1];
bool vis[N];
int n,e=0,root,tot,md,sum,allnum=0,ans=0;
bool cmp(D aa,D bb)
{
    return aa.dist<bb.dist;
}
void build_edge(int x,int y)
{
    ++e;
    nexte[e]=firste[x];
    firste[x]=e;
    v[e]=y;
}
void getroot(int u,int fa)
{
    sz[u]=1;
    lim[u]=0;
    for(int p=firste[u];p;p=nexte[p])
    if(v[p]!=fa&&!vis[v[p]])
    {
        getroot(v[p],u);
        sz[u]+=sz[v[p]];
        lim[u]=imax(lim[u],sz[v[p]]);
    }
    lim[u]=imax(lim[u],sum-sz[u]);
    if(lim[u]<lim[root])root=u;
}
void getdist(int u,int fa,int d)
{
    di[++tot].dist=d;
    di[tot].num=u;
    for(int p=firste[u];p;p=nexte[p])
    if(v[p]!=fa&&!vis[v[p]])
    getdist(v[p],u,d+w[v[p]]);
}
void calc(int u,int d,int dt)
{
    tot=0;
    getdist(u,0,0);
    int res=0;
    rep(i,tot)
    cnt[M+di[i].dist+d]+=dt;
    rep(i,tot)
    {
        numq[di[i].num]+=cnt[M-di[i].dist];
        allnum-=cnt[M-di[i].dist];
    }
    rep(i,tot)
    cnt[M+di[i].dist+d]-=dt;
}
void getans(int u)
{
    calc(u,w[u],1);
    vis[u]=1;
    for(int p=firste[u];p;p=nexte[p])
    if(!vis[v[p]])
    {
        calc(v[p],w[u]+w[v[p]]*2,-1);
        sum=sz[v[p]];
        lim[0]=sum;
        root=0;
        getroot(v[p],0);
        getans(root);
    }
}
int main()
{
    int x,y;
    scanf("%d",&n);
    rep(i,n)
    {
        scanf("%d",&w[i]);
        if(!w[i])--w[i];
    }
    for(int i=1;i<n;++i)
    {
        scanf("%d%d",&x,&y);
        build_edge(x,y);
        build_edge(y,x);
    }
    rep(i,n)
    scanf("%d",&b[i]);
    root=0;
    lim[0]=n;
    sum=n;
    getroot(1,0);
    getans(root);
    cout<<allnum<<endl;
    allnum/=2;
    for(int i=1;i<=n;i++) cout<<numq[b[i]]<<endl; 
    int j=0;
    rep(i,n)
    {
        while(allnum<=0&&j<n)
        {
            ++j;
            allnum+=numq[b[j]];
        }
        if(allnum>0)
            ans+=n-j+1;
        else break;
        allnum-=numq[b[i]];
    }
    printf("%d",ans);
    return 0;
}


