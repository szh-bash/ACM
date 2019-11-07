#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define dep(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define mem(x,num) memset(x,num,sizeof x)
#define reg(x) for(int i=last[x];i;i=e[i].next)
using namespace std;
inline ll read()
{
    ll f=1,x=0;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
inline ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
const int maxn=1e5+6,maxk=4e6+6;
int ls[maxk],rs[maxk],sum[maxk],n,m,cnt=0,ind,sz;
int last[maxn],deep[maxn],root[200006],in[maxn],out[maxn],fa[maxn][17];
vector<int>a[maxn];
struct query{int x,y;}que[maxn];
struct edge{int to,next;}e[200006];
ll A,B;
bool operator < (query a,query b){return a.x==b.x?a.y<b.y:a.x<b.x;} 
void insert(int u,int v){
    e[++cnt]=(edge){v,last[u]};last[u]=cnt;
    e[++cnt]=(edge){u,last[v]};last[v]=cnt;
}
int insert(int x,int l,int r,int pos,int v){
    int t=++sz,mid=(l+r)>>1;ls[t]=ls[x];rs[t]=rs[x];
    if(l==r){sum[t]=sum[x]+v;return t;}
    if(pos<=mid)ls[t]=insert(ls[t],l,mid,pos,v);else rs[t]=insert(rs[t],mid+1,r,pos,v);
    sum[t]=sum[ls[t]]+sum[rs[t]];return t;
}
int query(int p1,int p2,int p3,int p4,int l,int r,int L,int R){
    int mid=(l+r)>>1;
    if(l==L&&r==R)return sum[p1]+sum[p2]-sum[p3]-sum[p4];
    if(R<=mid)return query(ls[p1],ls[p2],ls[p3],ls[p4],l,mid,L,R);
    else if(L>mid)return query(rs[p1],rs[p2],rs[p3],rs[p4],mid+1,r,L,R);
    else return query(ls[p1],ls[p2],ls[p3],ls[p4],l,mid,L,mid)+query(rs[p1],rs[p2],rs[p3],rs[p4],mid+1,r,mid+1,R);
}
void dfs(int x){
    in[x]=++ind;
    rep(i,1,16)if((1<<i)<=deep[x])fa[x][i]=fa[fa[x][i-1]][i-1];else break;
    reg(x)
        if(e[i].to!=fa[x][0]){
            fa[e[i].to][0]=x;
            deep[e[i].to]=deep[x]+1;
            dfs(e[i].to);
        }
    out[x]=++ind;
}
void dfs2(int x){
    root[x]=root[fa[x][0]];
    for(int i=0;i<a[x].size();i++){
        root[x]=insert(root[x],1,ind,in[a[x][i]],1);
        root[x]=insert(root[x],1,ind,out[a[x][i]],-1);
    }
    reg(x)if(e[i].to!=fa[x][0])dfs2(e[i].to);
}
inline int lca(int x,int y){
    if(deep[x]<deep[y])swap(x,y);
    int t=deep[x]-deep[y];
    rep(i,0,16)if((1<<i)&t)x=fa[x][i];
    dep(i,16,0)if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
    if(x==y)return x;else return fa[x][0];
}
void solve(){
    rep(i,1,m){
        int x=que[i].x,y=que[i].y,t=lca(x,y);
        A+=query(root[x],root[y],root[t],root[fa[t][0]],1,ind,in[t],in[x]);
        A+=query(root[x],root[y],root[t],root[fa[t][0]],1,ind,in[t],in[y]);
        A-=query(root[x],root[y],root[t],root[fa[t][0]],1,ind,in[t],in[t]);
        A--;
    }
}
int main()
{
	freopen("data.in","r",stdin);
	freopen("std.out","w",stdout);
    n=read(),m=read();
    rep(i,1,n-1){
        int u=read(),v=read();insert(u,v);
    }
    rep(i,1,m){
        int x=read(),y=read();a[x].push_back(y);
        que[i].x=x,que[i].y=y;
    }
    sort(que+1,que+1+m);
    dfs(1);dfs2(1);solve();int j;
    for(int i=1;i<=m;i=j)
        for(j=i;que[j].x==que[i].x&&que[j].y==que[i].y;j++)A-=(ll)(j-i)*(j-i-1)/2;
    B=(ll)m*(m-1)/2;
    ll t=gcd(A,B);A/=t,B/=t;
    cout<<A<<'/'<<B<<endl;
    return 0;
}
