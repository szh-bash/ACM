#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
int n, m, k, ans=999, g[110][110], x1[200], y1[200], x2[200], y2[200], can[110][110][110], dp[110], maxt[110][110], reachable[110][110], cnt=0, l[20000], a[200], b[200], vis[200];
void init();
int sqr(int t);
void prepare();
int find(int v);
void search(int s);
int main(){
    init();
    prepare();
    search(1);
    printf("%d\n", ans);
    return 0;
}
void init(){
    freopen("std.in","r",stdin);
    freopen("std.out","w",stdout);
    scanf("%d%d%d", &m, &n, &k);
    for (int i=1;i<=m;i++) scanf("%d%d", &x1[i], &y1[i]);
    for (int i=1;i<=n;i++) scanf("%d%d", &x2[i], &y2[i]);
}
int sqr(int t){return t*t;}
void prepare(){
    for (int i=1;i<=m;i++)
         for (int j=1;j<=n;j++)
             reachable[i][j]=( sqr( x1[i]- x2[j] )+ sqr( y1[i]- y2[j])<= k*k);
    for (int i=1;i<=m;i++)
        for (int j=i;j<=m;j++)
            for (int k=1;k<=n;k++){
                can[i][i-1][k]=1;
                can[i][j][k]=can[i][j-1][k] && reachable[j][k];
            }
    for (int i=m;i>=1;i--){
        dp[i]=999;
        for (int j=i+1;j<=m+1;j++)
            for (int k=1;k<=n;k++)
                if (can[i][j- 1][k]) dp[i]= min(dp[i], dp[j]+ 1);
        for (int k=1;k<=n;k++){
            maxt[i][k]=i-1;
            for (int j=i;j<=m;j++)
                if (can[i][j][k]) maxt[i][k]=j;
        }
    }
}
int find(int v){
    for (int i=1;i<=n;i++)
        if (!vis[i] && g[v][i]){
            vis[i]=1;
            if (!b[i] || find(b[i] ) ){
                b[i]=v;
                a[v]=i;
                return 1;
            }
        }
    return 0;
}
void search(int s){
    if ( dp[s]+ cnt>= ans) return;
    if (s>m){
        ans=cnt;
        return;
    }
    memset(vis, 0, sizeof( vis) );
    int le=0, ri=0, maxl=0;
    for (int i=1;i<=n;i++)
        if (!b[i]){
            vis[i]=1;
            l[++ri]=i;
        }
    while (le<ri){
        int u=l[++le];
        maxl=max(maxl, maxt[s][u]);
        for (int i=1;i<=cnt;i++)
            if (g[i][u] && !(vis[a[i] ] ) ){
                l[++ri]=a[i];
                vis[a[i] ]=1;
            }
    }
    if (!maxl) return;
    int atmp[200], btmp[200];
    memcpy(atmp, a, sizeof(a) );
    memcpy(btmp, b, sizeof(b) );
    memset(vis, 0, sizeof(vis) );
    cnt++;
    for (int i=1;i<=n;i++)
        g[cnt][i]=can[s][maxl][i];
    find(cnt);
    for (int i=maxl;i>=s;i--){
        for (int j=1;j<=n;j++)
            g[cnt][j]=can[s][i][j];
        search(i+1);
    }
    cnt--;
    memcpy(a, atmp, sizeof(atmp) );
    memcpy(b, btmp, sizeof(btmp) );
}
