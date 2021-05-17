#include <cstdlib>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
char s[22000007];
int pos;
ll read(){
    ll p=0, q=1;
    while (s[pos] && (s[pos]<'0' || s[pos]>'9')) s[pos++]=='-'?q=-1:0;
    while (s[pos] && s[pos]>='0' && s[pos]<='9') p=p*10+s[pos++]-'0';
    return p*q;
}
#define eps 1e-2
#define N 2000000
int n;
ld p[N], d, mi, ma, g[N];
ld calc(ld x){
//    ld res = 0;
//    for (int i=1;i<=n;i++)
//        res = max(fabs(p[i]-(x+(i-1)*d)), res);
//    return res;
    return max(abs(ma-x), abs(mi-x));
}
ld solve(){
    ld le=-3e16, ri=3e16;
    while (ri-le>eps){
        ld pcs = (ri-le)/3, ll = le+pcs, rr = ri-pcs;
        if (calc(ll)>calc(rr))
            le = ll;
        else ri = rr;
    }
    return calc(le);
}
int main() {
    fread(s,1,22000000,stdin);
    n=read(), d=read();
    for (int i=1;i<=n;i++) p[i]=read();
    ma = -3e17, mi=3e17;
    for (int i=1;i<=n;i++) g[i] = p[i]-(i-1)*d, ma=max(g[i],ma), mi=min(g[i],mi);
    ld ans = solve();
    for (int i=1;i*2<=n;i++) swap(p[i], p[n-i+1]);
    ma = -3e17, mi=3e17;
    for (int i=1;i<=n;i++) g[i] = p[i]-(i-1)*d, ma=max(g[i],ma), mi=min(g[i],mi);

    ans = min(ans, solve());
    cout.setf(ios::fixed);
    cout<<setprecision(1)<<ans<<endl;
}
