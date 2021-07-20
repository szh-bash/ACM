#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
#define A 16384
#define N 40005
#define M (N*2)
int dp[20][A];
int n, cnt, last, fa[N], sz[N], son[N], tg[N], sum[N], a[N], b[N], ans[N];
int nex[M], nu[M];
char op[4];
const int inf = 2099999999;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        ch=='-'?q=-1:0,
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
void add(int u, int v){
    nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;
}
void dfs_split(int u){
    sz[u]=1;
    son[u]=0;
    for (int j=nex[u];j;j=nex[j]){
        int v=nu[j];
        sum[v]=sum[u]+b[v];
        dfs_split(v);
        sz[u]+=sz[v];
        if (sz[v]>sz[son[u]])
            son[u]=v;
    }
}
void dfs(int u, int dep){
    for (int i=0;i<A;i++)
        dp[dep][i]=max(dp[dep-1][i],dp[dep-1][i^a[u]]+b[u]);
    if (son[fa[u]]==u){
        dep--;
        for (int i=0;i<A;i++)
            dp[dep][i]=dp[dep+1][i];
    }
    ans[u]=sum[u]-dp[dep][0];
    for (int j=nex[u];j;j=nex[j]){
        int v=nu[j];
        if (v==son[u]) continue;
        dfs(v,dep+1);
    }
    if (son[u]) dfs(son[u],dep+1);
}
int main(){
    cnt=n=read();
    for (int i=1;i<=n;i++){
        scanf("%s", op);
        if (op[0]=='A'){
            a[i]=read(),b[i]=read();
            if (last) add(last,i);
            fa[i]=last;
            last=i;
        }
        else last = fa[last];
        tg[i]=last;
    }
    sum[1]=b[1];
    dfs_split(1);
    for (int i=1;i<A;i++) dp[0][i]=-inf;
    dfs(1,1);
    for (int i=1;i<=n;i++) printf("%d\n", ans[tg[i]]);
    return 0;
}