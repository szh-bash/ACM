#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long LL;
typedef double ld;
const int MAX=300000+10;
const ld EPS=1e-4;
const ld INF=1e10;
int n,L,R;
int begin[MAX],next[MAX],t[MAX],tot;
ld w[MAX],mm;
void add(int a,int b,int c)
{
    t[++tot]=b;
    next[tot]=begin[a];
    begin[a]=tot;
    w[tot]=c;mm=max((ld)c,mm);
}
 
int in[MAX],lab=0,size[MAX],val[MAX];
int q[MAX];
 
void dfs_size(int u,int fa)
{
    q[++q[0]]=u;
    size[u]=1;
    val[u]=0;
    int i,v;
    for(i=begin[u];i;i=next[i])
    {
        v=t[i];
        if(in[v]==lab && v!=fa)
        {
            dfs_size(v,u);
            size[u]+=size[v];
            val[u]=max(val[u],size[v]);
        }
    }
}
int number[MAX],len[MAX];
ld aa[MAX],bb[MAX],come[MAX];
void dfs_sum(int u,int fa,int deep,ld sum)
{
    bb[deep]=max(bb[deep],sum);
    int i,v;
    for(i=begin[u];i;i=next[i])
        if(in[v=t[i]]==lab && v!=fa)
            dfs_sum(v,u,deep+1,sum+w[i]);
}
int dfs_deep(int u,int fa,int deep)
{
    int i,v,ans=deep;
    for(i=begin[u];i;i=next[i])
        if(in[v=t[i]]==lab && v!=fa)
            ans=max(ans,dfs_deep(v,u,deep+1));
    return ans;
}
 
int cmp(int a,int b)
{
    return len[a]<len[b];
}
int st[MAX],head,top;
ld calc(ld* aa,int numa,ld* bb,int numb,ld mid)
{
    int i;
    for(i=1;i<=numa;++i)aa[i]-=mid*i;
    for(i=1;i<=numb;++i)bb[i]-=mid*i;
    ld ans=-INF;
    head=1,top=1;
    for(i=1;i<R-numa && i<=numb;++i)
    {
        while(top>head && bb[i]>=bb[st[top-1]])--top;
        st[top++]=i;
    }
    for(i=numa;i>=1;--i)
    {
        if(R-i>=1 && R-i<=numb)
        {
            while(top>head && bb[R-i]>=bb[st[top-1]])--top;
            st[top++]=R-i;
        }
        while(head<top && st[head]+i<L)++head;
        if(top>head)
            ans=max(ans,bb[st[head]]+aa[i]);
    }
    for(i=1;i<=numa;++i)aa[i]+=mid*i;
    for(i=1;i<=numb;++i)bb[i]+=mid*i;
    return ans;
}
void update(ld* aa,int numa,ld* bb,int numb,ld& ans)
{
    ld left=ans,right=mm;
    while(left+EPS<right)
    {
        ld mid=(left+right+EPS)*0.5;
        if(calc(aa,numa,bb,numb,mid)>=0)left=mid;
        else right=mid-EPS;
    }
    ans=max(ans,left);
}
void dfsNewTree(int u,int fa,int nowlab)
{
    in[u]=lab;
    int i,v;
    for(i=begin[u];i;i=next[i])
        if((v=t[i])!=fa && in[v]==nowlab)
            dfsNewTree(v,u,nowlab);
}
void getAns(int u,int dep,ld& ans)
{
    int i,v,j;
    q[0]=0;
    dfs_size(u,0);
    int Root=u;
    for(i=1;i<=q[0];++i)
        if(max(val[Root],q[0]-size[Root])>max(val[q[i]],q[0]-size[q[i]]))
            Root=q[i];
    int num=0;
    for(i=begin[Root];i;i=next[i])
        if(in[v=t[i]]==lab)
        {
            come[v]=w[i];
            len[v]=dfs_deep(v,Root,1);
            number[++num]=v;
        }
    if(num)
    {
        sort(number+1,number+num+1,cmp);
        for(j=1;j<=len[number[num]];++j)
            aa[j]=-INF;
        int last=0;
        for(i=1;i<=num;++i)
        {
            v=number[i];
            for(j=1;j<=len[v];++j)
                bb[j]=-INF;
            dfs_sum(v,Root,1,come[v]);
            if(i>=2)
                if(len[v]+last>=L)
                    update(aa,last,bb,len[v],ans);
            for(j=1;j<=len[v];++j)
                aa[j]=max(aa[j],bb[j]);
            last=len[v];
        }
        for(i=L;i<=min(last,R);++i)
            ans=max(ans,aa[i]/i);
    }
    int nowlab=lab;
    for(i=begin[Root];i;i=next[i])
        if(in[v=t[i]]==nowlab)
        {
            ++lab;
            dfsNewTree(v,Root,nowlab);
            getAns(v,dep+1,ans);
        }
}
int main()
{
    int i,a,b,c;
    scanf("%d%d%d",&n,&L,&R);
    for(i=1;i<n;++i)
    {
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);add(b,a,c);
    }
    ld ans=-INF;
    getAns(1,0,ans);
    printf("%.3lf\n",ans);
    return 0;
}
