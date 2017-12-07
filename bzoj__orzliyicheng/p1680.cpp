#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
long long ans;
int n, s, m, a[20000], c[20000];
int main(){
    scanf("%d%d", &n, &s);
    for (int i=1;i<=n;i++) scanf("%d%d", &c[i], &a[i]);
    ans=c[1]*a[1];m=c[1]+s;
    for (int i=2;i<=n;i++){
        ans+=min(c[i],m)*a[i];
        m=min(c[i]+s,m+s);
    }
    printf("%lld", ans);
    return 0;
}
