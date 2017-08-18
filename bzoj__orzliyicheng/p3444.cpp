#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
const int mo=989381;
int n, m, fa[500001], f[500001], p[500001][2];
int father(int x){
    if (fa[x]==x) return x;
    fa[x]=father(fa[x]);
    return father(fa[x]);
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i=1;i<=n;i++) fa[i]=i;
    int tot=n;
    for (int i=1;i<=m;i++){
        int u, v;
        scanf("%d%d", &u, &v);
        if (p[u][0]==v || p[u][1]==v) continue;
        f[u]++;
        f[v]++;
        if (f[u]>2 || f[v]>2){
                   cout<<0<<endl;
                   return 0;
        }
        if (!p[u][0]) p[u][0]=v;else p[u][1]=v;
        if (!p[v][0]) p[v][0]=u;else p[v][1]=u;
        if (father(u)!=father(v)) fa[fa[u]]=fa[v];
        else{
                   cout<<0<<endl;
                   return 0;
             }
    }
    int t1=0, t2=0;
    memset(f,0,sizeof(f));
    for (int i=1;i<=n;i++) f[father(i)]++;
    for (int i=1;i<=n;i++)
        if (f[i]>1) t1++;
        else
             if (f[i]==1) t2++;
    long long ans=1;
    for (int i=1;i<=t1+t2;i++)
        ans=(ans*i) % mo;
    for (int i=1;i<=t1;i++)
        ans=ans*2 % mo;
    printf("%lld", ans);
    return 0;
}
