#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, k;
long long ans, f[10][510][510];
int main(){
    scanf("%d%d", &n, &k);
    for (int i=1;i<=n;i++) f[1][i][i]=1;
    for (int i=1;i<k;i++)
        for (int j=1;j<=n;j++)
            for (int sum=j;sum<=n;sum++)
                for (int k=j;k<=n;k++)
                    f[i+1][k][sum+k]+=f[i][j][sum];
    for (int i=1;i<=n;i++)
        ans+=f[k][i][n];
    printf("%lld\n", ans);
    return 0;
}
