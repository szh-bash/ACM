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
#define mo 1000000007
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
#define N 2000*2000+5
#define M 200005
#define DATA M*35
int idx;
char input[DATA+5];
const ll inf = 1ll*999999999*999999999;
int n, m, a[N], q[N], cnt;
ll f[N], sum[N], ans[M];
int read(){
    int p=0, q=1;
    while (!num(input[idx])) input[idx++]=='-'?q=-1:0;
    while (num(input[idx])) p=p*10+input[idx++]-'0';
    return p*q;
}
ll readll(){
    ll p=0, q=1;
    while (!num(input[idx])) input[idx++]=='-'?q=-1:0;
    while (num(input[idx])) p=p*10+input[idx++]-'0';
    return p*q;
}
struct node{
    int le, ri, num;
    ll val;
}l[N+M], c[N];
void add(int u, int v, ll val, int num){
    ++cnt;
    l[cnt].le=u;
    l[cnt].ri=v;
    l[cnt].val=val;
    l[cnt].num=num;
}
bool cmp(node a, node b){
    if (a.val!=b.val)
        return a.val<b.val;
    else if (a.le!=b.le)
        return a.le<b.le;
    else if (a.ri!=b.ri)
        return a.ri<b.ri;
    else return a.num<b.num;
}
void cmax(ll &a, ll b){
    if (a<b) a=b;
}
void upd(int x, ll v){
    for (;x<=n;x+=x&(-x)) cmax(f[x], v);
}
void reset(int x){
    for (;x<=n;x+=x&(-x)) f[x]=-inf;
}
ll query(int x){
    ll res = -inf;
    for (;x;x-=x&(-x)) cmax(res,f[x]);
    return res;
}
void cdq(int le, int ri){
    if (le>=ri) return;
    int mid = (le+ri) >> 1;
    cdq(le,mid);
    cdq(mid+1,ri);
    int ct=le-1;
    int cnt=0;
    for (int i=le, j=mid+1;i<=mid || j<=ri;)
        if (j>ri || (i<=mid && l[i].le<=l[j].le)){
            c[++ct]=l[i];
            if (!l[i].num)
                q[++cnt]=i,
                upd(l[i].ri, l[i].val);
            i++;
        }
        else{
            c[++ct]=l[j];
            if (l[j].num)
                cmax(ans[l[j].num],query(l[j].ri));
            j++;
        }
    for (int i=1;i<=cnt;i++)
        reset(l[q[i]].ri);
    for (int i=le;i<=ri;i++)
        l[i]=c[i];
}
int main(){
    fread(input,1,DATA,stdin);
    n=read(), m=read();
    for (int i=1;i<=n;i++) a[i]=read(), sum[i]=sum[i-1]+a[i];
    for (int i=1;i<=m;i++){
        int u=read(), v=read();
        ll w=readll();
        add(-u,v,w,i);
        ans[i]=-inf;
    }
    for (int i=1;i<=n;i++)
        for (int j=i;j<=n;j++)
            add(-i,j,sum[j]-sum[i-1],0);
    for (int i=1;i<=n;i++) f[i]=-inf;
    sort(l+1,l+1+cnt,cmp);
    cdq(1,cnt);
    for (int i=1;i<=m;i++) 
        if (ans[i]==-inf) puts("NONE");
        else printf("%lld\n", ans[i]);
    return 0;
}
