#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, m, tx, ty, f[101000], f2[101000];
long long ans;
int main(){
    scanf("%d%d", &n, &m);
    ans=(long long)n*n;tx=ty=0;
    for (int i=1;i<=m;i++){
        int x, y;
        scanf("%d%d", &x, &y);
        if (!f[x] && !f2[y]){
                  ans-=n-tx+n-ty-1;
                  tx++;ty++;
                  }
        if (!f[x] && f2[y]){
                  ans-=n-ty;
                  tx++;
                  }
        if (f[x] && !f2[y]){
                 ans-=n-tx;
                 ty++;
                 }
        f[x]=f2[y]=1;
        cout<<ans<<endl;
    }
    return 0;
}
