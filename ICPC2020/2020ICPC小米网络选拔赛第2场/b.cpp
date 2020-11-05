#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
#define N 1000005
#define id(x,y) (((x)-1)*m+(y))
vector<int> g[N];
int n, m, a[N], up[N], dw[N], le[N], ri[N], flag[N];
inline bool intest(int u, int v){
    return le[u]<=le[v] && ri[v]<=ri[u] && up[u]<=up[v] && dw[v]<=dw[u];
}
inline bool outtest(int u, int v){
    return ri[u]<le[v] || ri[v]<le[u] || dw[u]<up[v] || dw[v]<up[u];
}
inline void inc(int u, int v){
    v=a[v];
    if (u==v || intest(u,v) || intest(v,u) || outtest(u,v)) return;
    g[u].push_back(v);
    g[v].push_back(u);
}
void solve(){
    int s=n*m;
    for (int i=1;i<=s;i++)
        up[i]=n+1, le[i]=m+1, dw[i]=ri[i]=flag[i]=0, g[i].clear();
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++){
            int x; scanf("%d", &x);
            a[id(i,j)]=x;
            up[x]=min(up[x], i);dw[x]=max(dw[x], i);
            le[x]=min(le[x], j);ri[x]=max(ri[x], j);
        }
    for (int i=1;i<=s;i++)
        if (dw[i]){
            int dn=dw[i]-up[i]+1, dm=ri[i]-le[i]+1;
            for (int j=max(1,le[i]-dm);j<=min(ri[i]+dm,m);j++)
                inc(i,id(up[i],j)),
                inc(i,id(dw[i],j));
            for (int j=max(1,up[i]-dn);j<=min(dw[i]+dn,n);j++)
                inc(i,id(j,le[i])),
                inc(i,id(j,ri[i]));
        }
    ll ans=0;
    for (int i=1, cnt=1;i<=s;i++, cnt++)
        if (dw[i]){
            ll res=0;
            for (int j:g[i]){
                int v=j;
                if (flag[v]==cnt) continue;
                res+=v;
                flag[v]=cnt;
            }
            ans+=res^i;
        }
    printf("%lld\n", ans);
}
int main(){
    while (~scanf("%d%d", &n, &m)) solve();
    return 0;
}