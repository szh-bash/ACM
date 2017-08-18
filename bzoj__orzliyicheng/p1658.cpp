#include <cstdio>
#include <algorithm>
 
using namespace std;
 
int n, m, ans, cnt1, cnt2, X, Y;
int deg[15000], start[15000], stop[15000], pos[15000];
 
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", pos + i);
    for (int i = 1; i <= m; ++i){
        scanf("%d%d", &X, &Y);
        ++deg[X], --deg[Y];
    }
 
    for (int i = 1; i <= n; ++i){
        for(; deg[i] > 0; --deg[i]) start[++cnt1] = pos[i];
        for(; deg[i] < 0; ++deg[i]) stop[++cnt2] = pos[i];
    }
 
    sort(start + 1, start + cnt1 + 1);
    sort(stop + 1, stop + cnt2 + 1);
     
    for (int i = 1; i <= cnt1; ++i)
        ans += abs(start[i] - stop[i]);
    printf("%d\n", ans);
    return 0;
}
