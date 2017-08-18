#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
struct zsm{
	int a, v;
}l[50010];
int n, f[100010], ans, b;
bool cmp(zsm a, zsm b){return a.a<b.a;}
int main(){
    scanf("%d", &n);
    for (int i=1;i<=n;i++){
        scanf("%d%d", &l[i].v, &l[i].a);
        if (!l[i].v) l[i].v=-1;
    }
    sort(l+1, l+1+n, cmp);
    b=n;
    f[0]=l[1].a;
    for (int i=1;i<=n;i++){
        b=b+l[i].v;
        if (!f[b]) f[b]=l[i+1].a;
            else ans=max(l[i].a-f[b], ans);
    }
    printf("%d\n", ans);
}
