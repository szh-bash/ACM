#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
struct zsm{
    int x, y, yy, v;
}l[100100];
int n, m, k, cnt, x, val, f[400100];
inline bool cmp1(zsm a, zsm b){return a.y<b.y;}
inline bool cmp2(zsm a, zsm b){
    if (a.x<b.x) return 1;
    if (a.x>b.x) return 0;
    return a.yy<b.yy;
}
inline int query(int t, int l, int r){
    if (r<=x) return f[t];
    int mid=l+r >>1, tmp=query(t*2, l, mid);
    if (x>mid) tmp=max(tmp, query(t*2+1, mid+1, r));
    return tmp;
}
void update(int t, int l, int r){
    if (l==r){
        f[t]=val;
        return;
    }
    int mid=l+r >>1;
    if (x>mid) update (t*2+1, mid+1, r);
    else update (t*2, l, mid);
    f[t]=max(f[t*2], f[t*2+1]);
}
int main(){
    freopen("p1537.in","r",stdin);
    freopen("std.out","w",stdout);
    scanf("%d%d%d", &n, &m, &k);
    for (int i=1;i<=k;i++) scanf("%d%d%d", &l[i].x, &l[i].y, &l[i].v);
    sort(l+1, l+1+k, cmp1);
    for (int i=1;i<=k;i++)
        if (l[i].y!=l[i-1].y) l[i].yy=++cnt; else l[i].yy=cnt;
    sort(l+1, l+1+k, cmp2);
    for (int i=1;i<=k;i++){
        x=l[i].yy;
        val=query(1, 1, cnt)+l[i].v;
        update(1, 1, cnt);
    }
    x=cnt;
    printf("%d", query(1, 1, cnt));
    return 0;
}
