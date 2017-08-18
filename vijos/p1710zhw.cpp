#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
int deep[20005],sum[20005],st[20005][20],fa[20005],n,m,A,B,d[20005];
int e[20005],next[20005],head[20005],LOG,i,j,o,q,root;
char C,s[20005];
long long ans,tree[65536][3];
void add(int a,int b,int c)
{
     e[a]=c;
     next[a]=head[b];
     head[b]=a;
}
void dfs(int k,int t)
{
     deep[k]=t;
     if (t % 2==0) d[k]=-d[k];
     sum[k]+=d[k];
     int now=head[k];
     while (now!=0)
     {
           fa[e[now]]=k;
           sum[e[now]]=sum[k];
           dfs(e[now],t+1);
           now=next[now];
     }
}
void work(int root,int k,int t)
{
     if (tree[root][0]==tree[root][1]) {tree[root][2]+=t; return;}
     int mid=(tree[root][0]+tree[root][1])/2;
     if (k<=mid) work(root*2,k,t); else work(root*2+1,k,t);
     tree[root][2]=tree[root*2][2]+tree[root*2+1][2];
}
long long Find(int root,int l,int r)
{
    if (tree[root][0]==l && tree[root][1]==r) return tree[root][2];
    int mid=(tree[root][0]+tree[root][1])/2; long long p=0,q=0;
    if (l<=mid) p=Find(root*2,l,min(mid,r));
    if (r>mid) q=Find(root*2+1,max(mid+1,l),r);
    return p+q;
}
int lca(int A,int B)
{
    if (A==B) return A;
    if (deep[A]==deep[B])for (int i=LOG; i>=0; i--) if (st[A][i]!=st[B][i]) return lca(st[A][i],st[B][i]);
    if (deep[A]==deep[B]) return fa[A];
    if (deep[A]<deep[B]) swap(A,B);
    for (int i=LOG; i>=0; i--) if (st[A][i]!=0 && deep[st[A][i]]>=deep[B]) return lca(st[A][i],B);
}
int main()
{
    freopen("p1710.in","r",stdin);
    freopen("p1710zhw.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (i=1; i<=n; i++) scanf("%d",&d[i]);
    for (i=1; i<=n; i++)
    {
        scanf("%d",&A);
        if (A!=-1) add(++o,A,i); else root=i;
    }
    dfs(root,1);
    for (i=1; i<=n; i++) st[i][0]=fa[i];
    LOG=int(log(n)/log(2)+0.00000001);
    for (i=1; i<=LOG; i++)
      for (j=1; j<=n; j++)
        st[j][i]=st[st[j][i-1]][i-1];
    getchar();
    for (i=32768; i<=65535; i++) tree[i][0]=tree[i][1]=i;
    for (i=32767; i>=1; i--) {tree[i][0]=tree[i*2][0]; tree[i][1]=tree[i*2+1][1];} 
    for (i=1; i<=m; i++)
    {
        scanf("%c %d %d",&C,&A,&B);
        if (C=='A') q=lca(A,B);
        if (C=='M') {if (A % 2==1)work(1,A+32767,B); else work(1,A+32767,-B); }else 
        {ans=sum[A]+sum[B]-sum[q]-sum[fa[q]];
        ans=ans+Find(1,deep[q]+32767,deep[A]+32767)+
        Find(1,deep[q]+32767,deep[B]+32767)-Find(1,deep[q]+32767,deep[q]+32767);
        cout<<abs(ans)<<endl;}
        getchar();
    }
   // system("pause");
    return 0;
}
