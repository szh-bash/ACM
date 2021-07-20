#include <set>
#include <ctime>
#include <cmath>
#include <queue>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
#define N 5005
#define M 5005
const int inf = 999999;
const double inf_double = 1e9;
bool mp[N*2][N], exist[N*2];
int n, m, k, cnt, nex[N+M*2], nu[N+M*2];
int l[N], dist[N], f[N][N];
int x[4];
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
void insert(int nd0, int nd1){
    int sig = min(f[nd0][x[0]]+f[nd1][x[1]],f[nd0][x[1]]+f[nd1][x[0]])
            + min(f[nd0][x[2]]+f[nd1][x[3]],f[nd0][x[3]]+f[nd1][x[2]]);
    int com = f[nd0][nd1];
    if (com>=N*2 || sig>=N) return;
    mp[sig][com]=1;
    exist[sig]=1;
}
double calc(int x, int y, int a1){
    if (a1>k || a1<0) return inf_double;
    if (!x && !y) return 0;
    int a2=k-a1;
    int a1base=1, a1high=0;
    int a2base=1, a2high=0;

    if (x) a1base=a1/x+1, a1high=a1%x;
    if (y) a2base=a2/y+1, a2high=a2%y;
    
    double res=0;
    res+=1.0/a1base*(x-a1high)+a1high*1.0/(a1base+1);
    res+=2.0/a2base*(y-a2high)+a2high*2.0/(a2base+1);
    return res;
}
double erfen(int x, int y){
    int le=-1, ri=k+1;
    double ans_l=inf_double, ans_r=inf_double;
    while (le<ri-1){
        int mid=le+ri>>1;
        ans_l=calc(x,y,mid);
        ans_r=calc(x,y,mid+1);
        if (ans_l-ans_r>0) le=mid;
        else ri=mid;
    }
    return min(ans_l,ans_r);
}
double sanfen(int x, int y){
    int le=-1, ri=k+1;
    while (le<ri-2){
        int len=ri-le, dm=len/3;
        int midl=le+dm, midr=le+2*dm;
        if (calc(x,y,midl)<calc(x,y,midr)) ri=midr;
        else le=midl;
    }
    return min(calc(x,y,le+1), calc(x,y,ri-1));
}
double solve(int x, int y){
    // return erfen(x,y);
    return sanfen(x,y);
}
void bfs(int root){
    for (int i=1;i<=n;i++) dist[i]=inf;
    dist[root]=0;
    l[1]=root;
    for (int le=1, ri=1;le<=ri;le++){
        int u=l[le];
        for (int j=nex[u];j;j=nex[j]){
            int v=nu[j];
            if (dist[v]>dist[u]+1)
                dist[v]=dist[u]+1,
                l[++ri]=v;
        }
    }
}
int main(){
    cnt=n=read(), m=read(), k=read();
    for (int i=1;i<=m;i++){
        int u=read(), v=read();
        add(u,v);
        add(v,u);
    }
    for (int i=0;i<4;i++) x[i]=read();
    for (int i=1;i<=n;i++){
        bfs(i);
        for (int j=1;j<=n;j++)
            f[i][j]=dist[j];
    }
    double ans=inf_double;
    mp[f[x[0]][x[1]]+f[x[2]][x[3]]][0]=exist[f[x[0]][x[1]]+f[x[2]][x[3]]]=1;
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
            insert(i,j);
    for (int i=0;i<N*2;i++)
        if (exist[i])
            for (int j=0;j<N;j++)
                if (mp[i][j]){
                    ans=min(ans,solve(i,j));
                    break;
                }
    printf("%.12lf\n", ans);
    return 0;
}