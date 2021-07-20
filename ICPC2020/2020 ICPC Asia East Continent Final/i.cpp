#include <set>
#include <ctime>
#include <cmath>
#include <queue>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <unordered_map>
typedef long long ll;
using namespace std;
#define Z 100005
#define S 100005
ll ans[Z];
ll n, m, v, k, d;
ll late, peers;
ll c[S];
const ll inf = 10000005ll*1000000007;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        ch=='-'?q=-1:0,
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
struct zombie{
    ll t, h, n;
}z[Z];
struct spikeweeds{
    ll p, a;
}s[S];
bool cmp_z(zombie a, zombie b){
    if (a.t<b.t) return 1;
    if (a.t>b.t) return 0;
    return a.n<b.n;
}
bool cmp_p(spikeweeds a, spikeweeds b){
    return a.p<b.p;
}
int find(ll x){
    int le=0, ri=m+1;
    while (le<ri-1){
        int mid=le+ri>>1;
        if (s[mid].p<=x) le=mid;
        else ri=mid;
    }
    return le;
}
ll getsum(ll x){
    ll res=0;
    for (int i=find(x);i;i-=i&(-i)) res+=c[i];
    return res;
}
int check(int i, ll x){
    ll pos = (x-z[i].t+1>2010000000ll?2010000000ll:x-z[i].t+1)*v;
    ll at = getsum(pos);
    ll hp = z[i].h - at;
    // if (hp<=0){
    //     return ;
    // }
    if (late>x){
        if (hp>0) return -1;
        return k;
    }
    if (late==x){
        if (hp+at-getsum(pos-v)<=0) return k;
        if (peers*d<hp) return -1;
        if (hp<=0) return peers;
        return peers-(hp-1)/d-1;
    }
    // if (hp+at-getsum(pos-v)<=0) return k;
    if (hp<=0) return k;
    ll tp=late<z[i].t?0:peers;
    ll time=x-max(late,z[i].t-1ll);
    if (time>1e9) time=1e9;
    if (((tp+k*time)>1e9?1e9:(tp+k*time))*d<hp) return -1;
    ll nd = (hp-1)/d+1;
    if (((tp+k*(time-1))>1e9?1e9:(tp+k*(time-1)))*d+getsum(pos-v)>=hp+at) return 0;
    ll res = k*time>inf?inf:k*time+tp-nd;
    return res>k?k:res;
}
int main(){
    n=read(), m=read(), v=read(), k=read(), d=read();
    for (int i=1;i<=n;i++){ 
        z[i].t=read();
        z[i].h=read();
        z[i].n=i;
    }
    for (int i=1;i<=m;i++){
        s[i].p=read();
        s[i].a=read();
    }
    sort(z+1,z+1+n,cmp_z);
    sort(s+1,s+1+m,cmp_p);
    for (int i=1;i<=m;i++)
        for (int j=i;j<=m;j+=j&(-j)) c[j]+=s[i].a;
    for (int i=1;i<=n;i++){
        ll le=z[i].t-1, ri=inf;
        while (le<ri-1){
            ll mid=le+ri>>1;
            if (check(i,mid)>=0) ri=mid;
            else le=mid;
        }
        ans[z[i].n]=ri;
        if (late<=ri)
            peers=check(i,ri),
            late=max(late, ri);
        // cout<<i<<' '<<z[i].n<<' '<<ri<<' '<<peers<<endl;
    }
    for (int i=1;i<=n;i++) printf("%lld%s", ans[i], (i==n?"\n":" "));
    return 0;
}

/*
1 2 1 2 2
1 11
1 2
2 4
*/