#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct zsm{
    int u, v, va;
}l[20000];
int n, m, cnt, fa[1001], ans;
bool cmp(zsm a, zsm b){return a.va>b.va;}
int father(int x){
    if (fa[x]==x) return x;
    return fa[x]=father(fa[x]);
}
void bin(int x){
    int u=l[x].u, v=l[x].v, va=l[x].va;
    fa[fa[u]]=fa[v];
    cnt++;
    ans+=va;
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i=0;i<m;i++) scanf("%d%d%d", &l[i].u, &l[i].v, &l[i].va);
    sort(l,l+m,cmp);
    for (int i=1;i<=n;i++) fa[i]=i;
    for (int i=0;i<m;i++)
        if (father(l[i].u)!=father(l[i].v)){
            bin(i);
            if (cnt==n-1) break;
        }
    if (cnt<n-1) printf("-1\n");else printf("%d\n", ans);
    return 0;
}
