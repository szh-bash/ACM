#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, m, cnt, p, ans, f[200010], l[200010], an[200010], next[1000100], nu[1000100], fa[200010], a[200010];
void add(int u, int v){
    next[++cnt]=next[u];next[u]=cnt;nu[cnt]=v;
}
int father(int x){
    if (fa[x]==x) return x;
    fa[x]=father(fa[x]);
    return fa[x];
}
int main(){
    scanf("%d%d", &n, &m);
    cnt=n-1;
    int u, v;
    for (int i=1;i<=m;i++){
        scanf("%d%d", &u, &v);
        add(u, v);
        add(v, u);
    }
    scanf("%d", &p);
    for (int i=1;i<=p;i++){
        scanf("%d", &a[i]);
        f[a[i]]=1;
    }
    int le=1, ri=0;
    for (int i=0;i<n;i++){
        if (!f[i]) l[++ri]=i;
        fa[i]=i;
    }
    int tp=p;
    while (p!=-1){
        ans+=ri-le+1;
        for (int i=le;i<=ri;i++){
            u=l[i];
            int j=next[u];
            while (j){
                v=nu[j];
                if (!f[v] && father(u)!=father(v)){
                    fa[fa[u]]=fa[v];
                    ans--;
                }
                j=next[j];
            }
        }
        le=ri+1;
        if (p){
            l[++ri]=a[p];
            f[a[p]]=0;
        }
        an[p]=ans;
        p--;
    }
    for (int i=0;i<=tp;i++) printf("%d\n", an[i]);
    return 0;
}
