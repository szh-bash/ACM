#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
struct zsm{
    int x, y, yy, v;
}l[100100];
int n, m, k, cnt, f[100100];
inline bool cmp1(zsm a, zsm b){return a.y<b.y;}
inline bool cmp2(zsm a, zsm b){
    if (a.x<b.x) return 1;
    if (a.x>b.x) return 0;
    return a.yy<b.yy;
}
inline int lowbit(int x){return x&(-x);}
inline int sum(int x){
    int v=0;
    while (x){
        v=max(v, f[x]);
        x-=lowbit(x);
    }
    return v;
}
void update(int x, int v){
    while (x<=cnt){
        f[x]=max(f[x], v);
        x+=lowbit(x);
    }
}
int main(){
    scanf("%d%d%d", &n, &m, &k);
    for (int i=1;i<=k;i++) scanf("%d%d%d", &l[i].x, &l[i].y, &l[i].v);
    sort(l+1, l+1+k, cmp1);
    for (int i=1;i<=k;i++)
        if (l[i].y!=l[i-1].y) l[i].yy=++cnt; else l[i].yy=cnt;
    sort(l+1, l+1+k, cmp2);
    for (int i=1;i<=k;i++) update(l[i].yy, sum(l[i].yy)+l[i].v);
    printf("%d", sum(cnt));
    return 0;
}
