#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
#define LL long long
int t, n;
LL f[1000100];
LL dfs(int n){
    if (n<=1000000) return f[n];
    return dfs(n/2) + dfs(n/3) + dfs(n/4);
}
int max(int a, int b){
    if (a>b)return a;return b;
}
int main(){
    scanf("%d", &t);
    for (int i=1;i<=1000000;i++) f[i]=max(i, f[i/2]+f[i/3]+f[i/4]);
    while (t){
        scanf("%d", &n);
        printf("%lld\n", dfs(n));
        t--;
    }
    return 0;
}
