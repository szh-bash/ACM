#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define inf 0x7fffffff
using namespace std;
int n,k,cnt,sum,root,ans;
struct data{int to,next,v;}e[80001];
int head[40001],son[40001],f[40001],d[40001],deep[40001];
bool done[40001];
void ins(int u,int v,int w)
{cnt++;e[cnt].to=v;e[cnt].v=w;e[cnt].next=head[u];head[u]=cnt;}
void getroot(int x,int fa)
{
    son[x]=1;f[x]=0;
    for(int i=head[x];i;i=e[i].next)
    {
        if(e[i].to==fa||done[e[i].to])continue;
        getroot(e[i].to,x);
        son[x]+=son[e[i].to];
        f[x]=max(f[x],son[e[i].to]);
    }
    f[x]=max(f[x],sum-son[x]);
    if(f[x]<f[root])root=x;
}
void getdep(int x,int fa)
{
    deep[0]++;deep[deep[0]]=d[x];
    for(int i=head[x];i;i=e[i].next)
    {
        if(e[i].to==fa||done[e[i].to])continue;
        d[e[i].to]=d[x]+e[i].v;
        getdep(e[i].to,x);
    }
}
int cal(int x,int now)
{
    d[x]=now;deep[0]=0;
    getdep(x,0);
    sort(deep+1,deep+deep[0]+1);
    int t=0,l,r;
    for(l=1,r=deep[0];l<r;)
    {
        if(deep[l]+deep[r]<=k){t+=r-l;l++;}
        else r--;
    }
    return t;
}
void work(int x)
{
    ans+=cal(x,0);
    done[x]=1;
    for(int i=head[x];i;i=e[i].next)
    {
        if(done[e[i].to])continue;
        ans-=cal(e[i].to,e[i].v);
        sum=son[e[i].to];
        f[0]=sum;root=0;
        getroot(e[i].to,root);
        work(root);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        ins(a,b,c);ins(b,a,c);
    }
    scanf("%d",&k);
    sum=n;f[0]=sum;
    getroot(1,0);
    work(root);
    printf("%d",ans);
    return 0;
}
