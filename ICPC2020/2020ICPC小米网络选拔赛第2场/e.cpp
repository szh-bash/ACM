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
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
ll readll(){
    ll p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
inline void ins(int x){
    a[++cnt]=x;
}
struct node{
    int n, tp, x, y;
}l[N+M];
inline void add(int u, int x, int y){
    l[++cnt].n=u;
    l[cnt].tp=u>n;
    l[cnt].x=x;
    l[cnt].y=y;
}
bool cmp(node &a, node &b){
    if (a.x>b.x) return 1;
    if (a.x<b.x) return 0;
    return a.y>b.y;
}
void proceed(){
    cnt=0;
    for (int i=1;i<=n;i++)
        
    for (int i=n+1;i<=n+m;i++) add(i,fx[i],fy[i]);
    sort(l+1,l+1+cnt,cmp);
    for (int i=1;i<=cnt;i++)
}
void aswap(){
}
void solve(){
    a[cnt=0]=-999999999;
    for (int i=1;i<=n;i++) ins(x[i]=read()), ins(y[i]=read());
    for (int i=1;i<=m;i++) ins(x[i+n]=read()), ins(y[i+n]=read());
    sort(a+1,a+1+cnt);
    for (int i=1;i<=cnt;i++)
        if (a[i]!=a[i-1]) trans[mp[a[i]]=++ct]=a[i];
    for (int i=1;i<=n+m;i++) fx[i]=mp[x[i]], fy[i]=mp[y[i]];
    proceed();
    aswap();
    proceed();
}
int main(){
    for ((n=read()) && (m=read())) solve();
    return 0;
}
