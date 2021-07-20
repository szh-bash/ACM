#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
#define BIT 29
#define N 100005
#define M (N*(BIT+5))
unordered_map <int,int> mp;
int n, cnt, root, nex[N*5], nu[N*5];
int num[N], fa[N], co[N], w[N], nodes[N];
int sz[M], ls[M], rs[M], xr[M][2];

struct node{
    int u, v, x;
}l[N*(BIT+2)];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        ch=='-'?q=-1:0,
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
int father(int x){
    return fa[x]==x?x:fa[x]=father(fa[x]);
}
void insert(int &t, int bit, int x){
    if (!t){
        t=++cnt;
        sz[t]=ls[t]=rs[t]=0;
        xr[t][0]=xr[t][1]=0;
    }
    if (bit<0){
        xr[t][sz[t]++]=x;
        // if (sz[t]>2) while(1);
        return;
    }
    xr[t][0]=xr[t][1]=0;
    bool y=w[x]&(1<<bit);
    if (!y) insert(ls[t],bit-1,x);
    else insert(rs[t],bit-1,x);
    sz[t]=sz[ls[t]]+sz[rs[t]];
}
void add(int u, int v){
    if (!u || !v) return;
    l[++cnt].u=u;
    l[cnt].v=v;
    l[cnt].x=w[u]^w[v];
}
void dfs(int t, int bit){
    if (!sz[t]) return;
    if (bit<0){
        add(xr[t][0],xr[t][1]);
        return ;
    }
    dfs(ls[t],bit-1);
    dfs(rs[t],bit-1);
    if (sz[t]==1){
        xr[t][0]=xr[ls[t]][0]+xr[rs[t]][0];
    }
    else if (sz[t]==2){
        if (sz[ls[t]]==1)
            add(xr[ls[t]][0],xr[rs[t]][0]),
            xr[t][0]=xr[ls[t]][0],
            xr[t][1]=xr[rs[t]][0];
        else if (sz[ls[t]]==2)
            xr[t][0]=xr[ls[t]][0],
            xr[t][1]=xr[ls[t]][1];
        else
            xr[t][0]=xr[rs[t]][0],
            xr[t][1]=xr[rs[t]][1];
    }
    else{
        if (sz[ls[t]]<=2 && sz[rs[t]]<=2)
            for (int i=0;i<=1;i++)
                for(int j=0;j<=1;j++)
                    add(xr[ls[t]][i], xr[rs[t]][j]);
    }
}
bool cmp(node a, node b){
    return a.x<b.x;
}
bool cmpw(int a, int b){
    return w[a]<w[b];
}
void add_edge(int u, int v){
    nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;
}
void paint(int x, int fr){
    for (int j=nex[x];j;j=nex[j]){
        int v=nu[j];
        if (v==fr) continue;
        co[v]=co[x]^1;
        paint(v,x);
    }
}
void merge(int a, int b){
    if (nodes[fa[a]]<nodes[fa[b]]) swap(a,b);
    nodes[fa[a]]+=nodes[fa[b]];
    fa[fa[b]]=fa[a];
    co[b]=co[a]^1;
    paint(b,0);
    add_edge(a,b);
    add_edge(b,a);
}
void solve(){
    int n=read();
    for (int i=1;i<=n;i++){
        w[i]=read();
        num[i]=i;
    }
    sort(num+1,num+1+n,cmpw);
    for (int i=2;i<n;i++)
        if (w[num[i-1]]==w[num[i]] && w[num[i]]==w[num[i+1]]){
            puts("0");
            for (int j=1;j<n;j++) printf("1");
            puts("2");
            return;
        }
    cnt=root=0;
    for (int i=1;i<=n;i++) insert(root,BIT,i);
    cnt=0;
    dfs(root,BIT);
    sort(l+1,l+1+cnt,cmp);
    int m=cnt;
    int ans=0;
    cnt=n;
    for (int i=1;i<=n;i++)
        fa[i]=i,
        co[i]=0,
        nex[i]=0,
        nodes[i]=0;
    for (int i=1;i<=m;i++){
        int u=l[i].u, v=l[i].v;
        ans=l[i].x;
        // cout<<i<<' '<<u<<' '<<v<<' '<<ans<<endl;
        if (father(u)!=father(v))
            merge(u,v);
        else
            if (co[u]==co[v]) break;
    }
    printf("%d\n", ans);
    for (int i=1;i<=n;i++)
        printf("%d%s", co[i]+1, i==n?"\n":"");
}
int main(){
    for (int _=read();_;_--) solve();
    return 0;
}