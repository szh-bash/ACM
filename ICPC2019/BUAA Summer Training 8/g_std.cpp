
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cstring>
#include <stdio.h>
#include <cmath>
#include <math.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define rrep(i,b,a) for(int i = (b); i >= (a); --i)
#define clr(a,x) memset(a,(x),sizeof(a))
#define LL unsigned long long
#define eps 1e-8
using namespace std;
const int maxn = 200 + 5;
bool adj[maxn][maxn];
bool adj2[maxn][maxn];
int d[maxn];
int node[maxn];
int n;
bool cmp(int x,int y)
{
    return d[x] < d[y];
}
 
vector<int> G[maxn];
int pre[maxn];
 
void out(bool adj[maxn][maxn])
{
    bool first = true;
    rep(i,1,n+1) {
        rep(j,i+1,n+1) if (adj[i][j]) {
            if (first) first = false;
            else printf(" ");
            printf("%d",i);
        }
    }
    puts("");
    first = true;
    rep(i,1,n+1) {
        rep(j,i+1,n+1) if (adj[i][j]) {
            if (first) first = false;
            else printf(" ");
            printf("%d",j);
        }
    }
    puts("");
}
 
int q[maxn],l,r;
bool vis[maxn];
bool bfs(int s)
{
    l = r = 0; q[r++] = s;
    clr(vis,0); vis[s] = true;
    while (l < r) {
        int u = q[l++];
        rep(i,0,G[u].size()) {
            int v = G[u][i];
            if (vis[v]) continue;
            vis[v] = true;
            pre[v] = u;
            q[r++] = v;
        }
    }
    rep(i,n+1,n+1+n) if (i-n != s && vis[i]) {
        if (!adj[i-n][s]) {
            int t = i;
            memcpy(adj2,adj,sizeof(adj));
            adj2[i-n][s] = adj2[s][i-n] = true;
            while (t != s) {
                int x = pre[t], y = t;
                if (x > n) x -= n;
                if (y > n) y -= n;
                adj2[y][x] ^= 1;
                adj2[x][y] ^= 1;
                t = pre[t];
            }
            return true;
        }
    }
    return false;
}
 
bool multiple()
{
    rep(i,1,n+1) if (bfs(i))
        return true;
    return false;
}
 
bool solve(int sum)
{
    clr(adj,0);
    rep(i,0,n) node[i] = i+1;
    sort(node,node+n,cmp);
    rep(i,0,n) {
        sort(node+i,node+n,cmp);
        int u = node[i];
        if (d[u] == 0) continue;
        rrep(j,n-1,i+1) {
            int v = node[j];
            if (d[v] == 0) continue;
            --d[v]; --d[u];
            adj[u][v] = adj[v][u] = true;
            if (d[u] == 0) break;
        }
        if (d[u] > 0) return false;
    }
    rep(i,0,maxn) G[i].clear();
    rep(i,1,n+1) rep(j,1,n+1) if (adj[i][j]) G[i].push_back(j+n);
    rep(i,1,n+1) rep(j,1,n+1) if (i != j && !adj[i][j]) G[i+n].push_back(j);
    bool m = false;
    if (m = multiple()) puts("MULTIPLE");
    else puts("UNIQUE");
    printf("%d %d\n",n,sum / 2);
    out(adj);
    if (!m) return true;
    int d2[maxn] = { 0 };
    printf("%d %d\n",n,sum / 2);
 
    out(adj2);
    rep(i,1,n+1) rep(j,i+1,n+1) if (adj2[i][j]) ++d2[i],++d2[j];
 
    return true;
}
 
int main()
{
   // cout << qpow(5,(mod - 1)/2,mod) << endl;
    #ifdef ACM
        freopen("in.txt", "r", stdin);
    #endif // ACM
    while (scanf("%d",&n)==1) {
        rep(i,1,n+1) scanf("%d",d+i);
        int sum = 0;
        rep(i,1,n+1) sum += d[i];
        if (sum % 2 || sum > n*(n-1) || !solve(sum)) puts("IMPOSSIBLE");
    }
}
