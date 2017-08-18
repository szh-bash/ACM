#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, f[100010], list[100010], l[100010], r[100010], flag[100010], s[100010], cnt, root, fa[100010];
void pushdown(int x){
    if (!flag[x]) return;
    flag[x]=0;
    if (l[x])flag[l[x]]^=1;
    if (r[x])flag[r[x]]^=1;
    swap(l[x], r[x]);
}
void zig(int t){
    int f1=fa[t];
    fa[t]=fa[f1];
    fa[f1]=t;
    l[f1]=r[t]; if (l[f1]) fa[l[f1]]=f1;
    r[t]=f1;
    s[t]=s[f1];
    s[f1]=s[l[f1]]+s[r[f1]]+1;
}
void zag(int t){
    int f1=fa[t];
    fa[t]=fa[f1];
    fa[f1]=t;
    r[f1]=l[t]; if (r[f1]) fa[r[f1]]=f1;
    l[t]=f1;
    s[t]=s[f1];
    s[f1]=s[l[f1]]+s[r[f1]]+1;
}
void splay(int t){
    int f1, f2, tf;
    f1=fa[t];f2=fa[f1];tf=fa[f2];
    int x=t, cnt=0;
    while (x) {list[++cnt]=x;x=fa[x];}
    for (int i=cnt;i>=1;i--)pushdown(list[i]);
    while (f2){
        if (l[tf]==f2) l[tf]=t;else r[tf]=t;
        if (l[f2]==f1)
            if (l[f1]==t) {zig(f1);zig(t);}
            else {zag(t);zig(t);}
        else
            if (l[f1]==t){zig(t);zag(t);}
            else {zag(f1);zag(t);}
        f1=fa[t];f2=fa[f1];tf=fa[f2];
    }
    root=t;
    if (!f1) return;
    if (l[f1]==t) zig(t);else zag(t);
}
int find(int t, int p){
    pushdown(t);
    if (p==s[l[t]]+1) return t;
    if (p<=s[l[t]]) return find(l[t], p);
    return find(r[t], p-s[l[t]]-1);
}
void print(int t){
    pushdown(t);
    if (!t) return;
    print(l[t]);
    if (t<=n)printf("%d ", f[t]);
    print(r[t]);
}
int main(){
    freopen("p3223.in","r",stdin);
    freopen("p3223.out","w",stdout);
    scanf("%d%d", &n, &m);
    root=n+2;s[n+2]=1;
    memset(flag, 0, sizeof(flag));
    for (int i=1;i<=n+1;i++){
        f[i]=cnt=i;
        int x=root;
        while (r[x]){
            s[x]++;
            x=r[x];
        }
        s[x]++;
        r[x]=cnt;
        s[cnt]=1;
        fa[cnt]=x;
        splay(cnt);
 /*       print(root);
        cout<<endl;*/
    }
   /* splay(1);
    cout<<root<<' '<<l[1]<<' '<<r[1]<<endl;
    print(root);
    cout<<endl;*/
    int le, ri;
    for (int i=1;i<=m;i++){
        scanf("%d%d", &le, &ri);
        le=find(root, le);
        ri=find(root, ri+2);
        splay(le);
        fa[r[le]]=0;
        splay(ri);
        fa[root]=le;
        r[le]=root;
        root=le;
        flag[l[r[le]]]^=1;
    }
    print(root);
    return 0;
}
