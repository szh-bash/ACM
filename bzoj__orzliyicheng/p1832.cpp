#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=500100;
struct
{
    int v,next;
}edge[N<<1];
struct
{
    int a,b;
}ques[N];
int head[N],t=1,pre[N],lv[N],f[N][22],n,m,q[N];
inline void addedge(int a,int b)
{
    edge[++t].next=head[a];edge[t].v=b;head[a]=t;
    edge[++t].next=head[b];edge[t].v=a;head[b]=t;
}
void bfs()
{
    int h=1,tail=1,s,i;
    lv[1]=1;
    q[1]=1;
    pre[1]=1;
    while(h<=tail)
    {
        s=q[h++];
        for(i=head[s];i;i=edge[i].next)
        if(!pre[edge[i].v])
        {
            pre[edge[i].v]=s;
            lv[edge[i].v]=lv[s]+1;
            q[++tail]=edge[i].v;
        }
    }
    pre[1]=0;
}
void init()
{
    int i,j;
    memset(f,-1,sizeof(f));
    for(i=1;i<=n;i++)f[i][0]=pre[i];
    for(j=1;j<21;j++)for(i=1;i<=n;i++)
    if(f[i][j-1]!=-1)f[i][j]=f[f[i][j-1]][j-1];
}
int lca(int a,int b)
{
    int k;
    if(lv[a]>lv[b])swap(a,b);
    for(k=20;k>=0;k--)
    {
        if(lv[b]-(1<<k)>=lv[a])b=f[b][k];
        if(a==b)return a;
    }
    for(k=20;k>=0;k--)
    if(f[a][k]!=f[b][k]&&f[a][k]!=-1&&f[b][k]!=-1)
    {
        a=f[a][k];
        b=f[b][k];
    }
    return pre[a];
}
int main()
{
    int ansd,ans,i,a,b,c,d,dd,e;
    scanf("%d%d",&n,&m);
    for(i=1;i<n;i++)scanf("%d%d",&a,&b),addedge(a,b);
    bfs();
    init();
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        ansd=N<<1;
        d=lca(a,b);
        e=lca(d,c);
        if(lv[a]+lv[b]+lv[c]-lv[e]*2-lv[d]<ansd)ansd=lv[a]+lv[b]+lv[c]-lv[e]*2-lv[d],ans=d;
        d=lca(a,c);
        if(lv[a]+lv[b]+lv[c]-lv[e]*2-lv[d]<ansd)ansd=lv[a]+lv[b]+lv[c]-lv[e]*2-lv[d],ans=d;
        d=lca(b,c);
        if(lv[a]+lv[b]+lv[c]-lv[e]*2-lv[d]<ansd)ansd=lv[a]+lv[b]+lv[c]-lv[e]*2-lv[d],ans=d;
        printf("%d %d\n",ans,ansd);
    }
    return 0;
}
