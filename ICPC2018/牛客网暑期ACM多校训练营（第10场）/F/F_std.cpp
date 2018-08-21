#include <cstdio>
#include <cstring>
#include <algorithm>
#define MN 555
using namespace std;
 
#define min(a,b) (a < b ? a : b)
 
int ans, a[MN][MN], b[MN][MN], c[MN], n, t;
 
const int MOD = 998244353;
 
void floyd() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                b[i][j] = min(b[i][j], b[i][k] + b[k][j]);
            }
        }
    }
}
 
int main()
{
  freopen("5.in","r",stdin);
  freopen("f.std","w",stdout);
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        ans = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j++) {
                scanf("%d",&a[i][j]);
                b[i][j] = a[i][j];
                if (i < j)
                ans += (int)((1ll * a[i][j] * ((n * (n-1)) / 2 - 1)) % MOD);
                ans %= MOD;
            }
        }
        floyd();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    c[k] = min(b[i][k], b[j][k]);
                }
                sort(c,c+n);
                for (int k = 0; k < n; k++) {
                    ans += (int)((1ll * c[k] * (n - k - 1))%MOD);
                    ans %= MOD;
                }
            }
        }
        printf("%d\n",ans);
    }
}
