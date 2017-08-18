#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, a[300010], f[300010][30], x, y, m, ans;
int main(){
    scanf("%d", &n);
    for (int i=1;i<=n;i++) scanf("%d", &a[i]);
    for (int i=n;i>=1;i--){
        f[i][0]=a[i];
        for (int j=1;j<=ceil(log(n-i+1)/log(2));j++)
            f[i][j]=max(f[i][j-1],f[i+(1<<j-1)][j-1]);
    }
    scanf("%d", &m);
    for (int i=1;i<=m;i++){
        scanf("%d%d", &x, &y);
        ans=-999999999;
        for (int j=ceil(log(y-x+1)/log(2));j>=0;j--)
            if (x+(1<<j)<=y+1){
                ans=max(ans, f[x][j]);
                x=x+(1<<j);
            }
        printf("%d\n", ans);
    }
    return 0;
}
