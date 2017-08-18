#include <bits/stdc++.h>
using namespace std;
#define N 110000
const double inf=1e15;
int n,L,R,tot;
int head[N],nex[N<<1],to[N<<1],val[N<<1];
int vis[N],f[N],size[N],root,rt,sum,mxd,top;
int deep[N],fa[N],st[N],q[N];
double now,sv[N],rec[N],ans;
vector<int>sr[N];
char getc()
{
    static const int LEN = 4096;
    static char buf[LEN],*S=buf,*T=buf;
    if(S == T)
    {
        T = (S=buf)+fread(buf,1,LEN,stdin);
        if(S == T)return EOF;
    }
    return *S++;
}
int read()
{
    static char ch;
    static int D;
    while(!isdigit(ch=getc()));
    for(D=ch-'0'; isdigit(ch=getc());)
        D=(D<<3)+(D<<1)+(ch-'0');
    return D;
}
void add(int x,int y,int z)
{
    tot++;
    nex[tot]=head[x];head[x]=tot;
    to[tot]=y;val[tot]=z;
}
void init()
{
    ans=-inf;
    memset(vis,0,sizeof(vis));
}
void dfs1(int x,int y)
{
    size[x]=1;
    for(int i=head[x];i;i=nex[i])
        if(to[i]!=y&&!vis[to[i]])
        {
            dfs1(to[i],x);
            size[x]+=size[to[i]];
        }
}
void dfs2(int x,int y)
{
    f[x]=0;
    for(int i=head[x];i;i=nex[i])
        if(to[i]!=y&&!vis[to[i]])
        {
            dfs2(to[i],x);
            f[x]=max(f[x],size[to[i]]);
        }
    f[x]=max(f[x],sum-size[x]);
    root=f[x]<f[root] ? x:root;
}
void get(int x,int v)
{
    st[top=1]=x;sv[1]=v;
    deep[1]=1;fa[1]=0;
    for(int i=1,t;i<=top;i++)
    {
        for(int j=head[t=st[i]];j;j=nex[j])
            if(!vis[to[j]]&&to[j]!=fa[i])
            {
                st[++top]=to[j];
                deep[top]=deep[i]+1;
                fa[top]=t;sv[top]=sv[i]+val[j];
            }
    }
    int h=1,r=0,pos=mxd;
    for(int i=1,j,t;i<=top;i=j)
    {
        double mx=-inf;t=deep[i];
        for(j=i;deep[j]==t&&j<=top;j++)
            mx=max(mx,sv[j]);
        while(pos>=0&&pos>=L-t)
        {
            while(h<=r&&rec[q[r]]<rec[pos])r--;
            q[++r]=pos;pos--;
        }
        while(h<=r&&q[h]>R-t)h++;
        if(h<=r)ans=max(ans,(rec[q[h]]+q[h]*now+mx)/(t+q[h]));
    }
    for(int i=1;i<=top;i++)
        rec[deep[i]]=max(rec[deep[i]],sv[i]-now*deep[i]);
    mxd=max(mxd,deep[top]);
}
void cal(int x)
{
    vis[x]=1;mxd=0;rec[0]=0;
    for(int i=head[x];i;i=nex[i])
        if(!vis[to[i]])
            get(to[i],val[i]);
    for(int i=0;i<=mxd;i++)rec[i]=-inf;
    for(int i=0;i<sr[x].size();i++)
        cal(sr[x][i]);
}
double check()
{
    init();
    cal(rt);
    return ans;
}
void pre(int x)
{
    vis[x]=1;
    for(int i=head[x];i;i=nex[i])
    if(!vis[to[i]])
    {
        dfs1(to[i],x);
        root=0;sum=size[to[i]];
        dfs2(to[i],x);
        sr[x].push_back(root);
        pre(root);
    }
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.ans","w",stdout);
    n=read();L=read();R=read();
    for(int i=1,x,y,z;i<n;i++)
    {
        x=read();y=read();z=read();
        add(x,y,z);add(y,x,z);
    }
    dfs1(1,0);
    f[0]=n+1;root=0;sum=n;
    dfs2(1,0);
    rt=root;pre(root);
    for(int i=0;i<=n;i++)rec[i]=-inf;
    double l=0,r=1e6;now=0;
    while(r-l>=5e-5)
    {
        l=now;
        now=check();
        r=now;
    }
    printf("%.3lf\n",l);
    return 0;
}
