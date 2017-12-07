#include <cstdio>
#include <algorithm>
using namespace std;
const int mo=1000000009;
int n, d, a[620010], j=1;
long long ans=1;
int main(){
    scanf("%d%d", &n, &d);
    for (int i=1;i<=n;i++) scanf("%d", &a[i]);
    sort(a+1, a+1+n);
    for (int i=2;i<=n;i++){
        for (;j<i;j++)
            if (a[i]-a[j]<=d) break;
        ans=ans*(i-j+1)%mo;
    }
    printf("%lld", ans);
    return 0;
}
