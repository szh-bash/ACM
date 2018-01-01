#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#define maxn 80000
#define maxm 3000000
#define inf 2147483647
using namespace std;
struct et
{
    int s,t,val,next;
}e[maxm];
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
int fir[maxn],dis[maxn],gap[maxn],last[maxn];
int v,s[60][60][60];
int st,ed,n,m,h,num,tot,D,cnt;
int dfs(int now,int flow)
{
    if (now==ed) return flow;
    int sap=0;
    for (int j=last[now];j;j=e[j].next)
    {
        int k=e[j].t;
        if (e[j].val&&dis[now]==dis[k]+1)
        {
            last[now]=j;
            int tmp=dfs(k,min(e[j].val,flow-sap));
            e[j].val-=tmp;
            e[j^1].val+=tmp;
            sap+=tmp;
            if (sap==flow) return sap;
        }
    }
    if (dis[st]>=num) return sap;
    if (!(--gap[dis[now]])) dis[st]=num;
    ++gap[++dis[now]];
    last[now]=fir[now];
    return sap;
}
void add(int x,int y,int z)
{
    e[++tot].s=x; e[tot].t=y; e[tot].val=z; e[tot].next=fir[x]; fir[x]=tot;
    e[++tot].s=y; e[tot].t=x; e[tot].val=0; e[tot].next=fir[y]; fir[y]=tot;
}
int main()
{
    scanf("%d%d%d",&n,&m,&h);
    scanf("%d",&D);
    for (int k=1;k<=h+1;k++)
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                s[k][i][j]=++cnt;
    st=0; ed=cnt+1; num=cnt+2; tot=1;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            add(st,s[1][i][j],inf),add(s[h+1][i][j],ed,inf);
    for (int k=1;k<=h;k++)
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                scanf("%d",&v),add(s[k][i][j],s[k+1][i][j],v);
    for (int k=1;k<=h;k++)
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                for (int p=0;p<4;p++)
                    if (s[k+D][i+dx[p]][j+dy[p]])
                        add(s[k+D][i+dx[p]][j+dy[p]],s[k][i][j],inf);
    memset(dis,0,sizeof(dis));
    memset(gap,0,sizeof(gap));
    gap[0]=num;
    for (int i=st;i<=ed;i++) last[i]=fir[i];
    int ans=0;
    while (dis[st]<num) ans+=dfs(st,inf);
    printf("%d\n",ans);
    return 0;
}
