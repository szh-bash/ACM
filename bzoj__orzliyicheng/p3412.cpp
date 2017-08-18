#include <cstdio>
#include <algorithm>
using namespace std;
struct zsm{
    int t, n;
}l[50001];
int n, q, ans[50001], b[50001];
bool cmp(zsm a, zsm b){return a.t<b.t;}
int main(){
    scanf("%d%d", &n, &q);
    for (int i=1;i<=n;i++) scanf("%d", &b[i]);
    for (int i=1;i<=q;i++) scanf("%d", &l[i].t), l[i].n=i;
    sort(l+1,l+1+q,cmp);
    int j=1, temp=b[1];
    for (int i=1;i<=q;i++){
        while (l[i].t>=temp) temp+=b[++j];
        ans[l[i].n]=j;
    }
    for (int i=1;i<=q;i++) printf("%d\n", ans[i]);
    return 0;
}
