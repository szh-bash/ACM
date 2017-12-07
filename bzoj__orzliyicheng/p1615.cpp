#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int root, end, n, xt, yt, x[2000], y[2000], r[2000], l[2000];
double dist[2000], v[2000];
inline double abss(double a){if (a>0) return a;return -a;}
inline int sqr(int a){return a*a;}
inline bool flag(int u, int v){
    return sqr(x[u]-x[v])+sqr(y[u]-y[v])==sqr(r[u]+r[v]);
}
int main(){
    freopen("baler.in","r",stdin);
    scanf("%d%d%d", &n, &xt, &yt);
    for (int i=1;i<=n;i++){
        scanf("%d%d%d", &x[i], &y[i], &r[i]);
        if (!x[i] && !y[i]) root=i;
        if (x[i]==xt && y[i]==yt) end=i;
    }
    int le=0, ri=1, u;
    dist[root]=v[root]=10000;
    l[1]=root;
    while (le<ri){
        u=l[++le];
        for (int i=1;i<=n;i++)
            if (!v[i] && flag(u, i)){
                v[i]=-v[u]/r[i]*r[u];
                dist[i]=dist[u]+abss(v[i]);
                l[++ri]=i;
            }
    }
    int a=floor(dist[end]);
    cout<<a<<endl;
}
