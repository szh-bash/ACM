#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define LL long long
 
inline LL read(){
    char ch = getchar(); LL x = 0, f = 1;
    while(ch < '0' || ch > '9'){
        if(ch == '-') f = -1;
        ch = getchar();
    }
    while('0' <= ch && ch <= '9'){
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
 
LL y, lo;
 
inline LL check(LL x, LL o){
    LL ret = 0;
    ret += o % 10;
    ret += o % 100 / 10 * x;
    ret += o / 100 * x * x;
    return ret;
}
 
inline bool checker(LL u, LL t){
    LL x = t, tot = 0, ot = 0;
    t = 1;
    while(x){
        if(x % u >= 10) return true;
        ot = ot + x % u * t;
        t = t * 10; x /= u;
    }
    if(ot < lo) return true;
    return false;
}
 
 
int main(){
    //freopen("for.in", "r", stdin);
    //freopen("for.out", "w", stdout);
    LL ans = 0;
    y = read(), lo = read();
    for(LL i = lo; i <= 999; i ++){//sou number
        LL l = 1, r = 1e9, t = 1;
        if(i < 100) r = 1e18;
        while(l <= r){
            LL mid = (l + r) / 2;
            if(check(mid, i) <= y) l = (t = mid) + 1;
            else r = mid - 1;
        }
        if(check(t, i) == y){
            ans = max(ans, t);
        }
    //  if(i == 10) printf("%lld %lld\n", t, ans);
    }
    for(LL i = 1000000; i >= ans; i --){
    //    printf("%d\n", i);
        if(i < 2) continue;
        if(checker(i, y)) continue;
        printf("%d\n", i);
        return 0;
    }
    printf("%lld\n", ans);
    return 0;
}
