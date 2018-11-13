#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define N 6000000
#define INF 999999999
using namespace std;
long long root, n, m, flag2[N], list[N], fa[N], l[N], r[N], size[N], f[N][3], g[N], flag[N], sum[N], a[N];
char s[20];
long long read(){
    long long p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9'){
        if (ch=='-') q=-1;
        ch=getchar();
    }
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
void update(long long t){
    if (l[t]) fa[l[t]]=t;
    if (r[t]) fa[r[t]]=t;
    sum[t]=sum[l[t]]+sum[r[t]]+a[t];
    size[t]=size[l[t]]+size[r[t]]+1;
    f[t][0]=max(f[l[t]][0],sum[l[t]]+f[r[t]][0]+a[t]);
    f[t][1]=max(f[r[t]][1],sum[r[t]]+f[l[t]][1]+a[t]);
    f[t][2]=f[l[t]][1]+f[r[t]][0]+a[t];
    f[t][2]=max(f[t][2],max(f[l[t]][2],f[r[t]][2]));
}
void pushdown(long long t){
    if (flag[t]){
        if (l[t]) flag[l[t]]^=1;
        if (r[t]) flag[r[t]]^=1;
        swap(l[t],r[t]);
		swap(f[l[t]][0],f[l[t]][1]);
		swap(f[r[t]][0],f[r[t]][1]);
        flag[t]=0;
    }
    if (flag2[t]){
        if (l[t]){
            sum[l[t]]=g[t]*size[l[t]];
            if (g[t]>0)
                f[l[t]][0]=f[l[t]][1]=f[l[t]][2]=sum[l[t]];
            else
                f[l[t]][0]=f[l[t]][1]=0, f[l[t]][2]=g[t];
            g[l[t]]=a[l[t]]=g[t];
            flag2[l[t]]=1;
        }
        if (r[t]){
            sum[r[t]]=g[t]*size[r[t]];
            if (g[t]>0)
                f[r[t]][0]=f[r[t]][1]=f[r[t]][2]=sum[r[t]];
            else
                f[r[t]][0]=f[r[t]][1]=0, f[r[t]][2]=g[t];
            g[r[t]]=a[r[t]]=g[t];
            flag2[r[t]]=1;
        }
        flag2[t]=g[t]=0;
    }
}
long long build(long long le, long long ri){
    if (le>ri) return 0;
    long long mid=le+ri>>1;
    l[mid]=build(le,mid-1);
    r[mid]=build(mid+1,ri);
    update(mid);
    return mid;
}
void insert(long long &t, long long k, long long p){
    if (!t){
        if (!size[t=p]){
            size[t]=1;
            f[t][0]=f[t][1]=a[t]>0?a[t]:0;
            f[t][2]=sum[t]=a[t];
        }
        return;
    }
    pushdown(t);
    if (size[l[t]]+1<=k) insert(r[t],k-size[l[t]]-1,p);
    else insert(l[t],k,p);
    update(t);
}
void zig(long long t){
    long long f1=fa[t], f2=fa[f1];
    if (f2)
        if (l[f2]==f1) l[f2]=t;else r[f2]=t;
    fa[t]=f2;
    l[f1]=r[t];
    r[t]=f1;
    update(f1);
    update(t);
}
void zag(long long t){
    long long f1=fa[t], f2=fa[f1];
    if (f2)
        if (l[f2]==f1) l[f2]=t;else r[f2]=t;
    fa[t]=f2;
    r[f1]=l[t];
    l[t]=f1;
    update(f1);
    update(t);
}
void splay(long long t){
    long long ri=1;
    list[1]=t;
    for (long long i=1;fa[list[i]];i++) list[++ri]=fa[list[i]];
    for (long long i=ri;i;i--) pushdown(list[i]);
    long long f1=fa[t], f2=fa[f1];
    while (f2){
        if (l[f2]==f1)
            if (l[f1]==t) zig(f1), zig(t);
            else zag(t), zig(t);
        else
            if (r[f1]==t) zag(f1), zag(t);
            else zig(t), zag(t);
        f1=fa[t];f2=fa[f1];
    }
    if (f1)
        if (l[f1]==t) zig(t);else zag(t);
    root=t;
}
long long find(long long t, long long k){
    pushdown(t);
    while (size[l[t]]+1!=k){
        if (size[l[t]]+1<k)
            k-=size[l[t]]+1, t=r[t];
        else
            t=l[t];
        pushdown(t);
    }
    return t;
}
void del(long long x, long long y){
    splay(x);
    fa[r[x]]=0;
    splay(y);
    l[r[root=x]=y]=0;
    update(y);
    update(x);
}
void modify(long long x, long long y, long long z){
    splay(x);
    fa[r[x]]=0;
    splay(y);
    r[root=x]=y;
    flag2[l[y]]=1;
    g[l[y]]=a[l[y]]=z;
    sum[l[y]]=size[l[y]]*z;
    if (z>0)
        f[l[y]][0]=f[l[y]][1]=f[l[y]][2]=sum[l[y]];
    else
        f[l[y]][0]=f[l[y]][1]=0, f[l[y]][2]=z;
    update(y);
    update(x);
}
void reverse(long long x, long long y){
    splay(x);
    fa[r[x]]=0;
    splay(y);
    fa[r[root=x]=y]=x;
    flag[l[y]]^=1;
    swap(f[l[y]][0],f[l[y]][1]);
    update(y);
    update(x);
}
void calc(long long x, long long y){
    splay(x);
    fa[r[x]]=0;
    splay(y);
    fa[r[root=x]=y]=x;
    printf("%d\n", sum[l[y]]);
    update(y);
    update(x);
}
void print(long long t){
    if (!t) return;
    pushdown(t);
    print(l[t]);
    printf("%d ", a[t]);
    print(r[t]);
}
int main(){
	freopen("sequence4.in","r",stdin);
	freopen("1.ans","w",stdout);
    n=read();m=read();
    for (long long i=1;i<=n;i++) a[i]=read();
    f[0][2]=-INF;
    root=build(1,n);
    a[N-3]=a[N-2]=-INF;
    insert(root,0,N-3);
    insert(root,n+1,N-2);
    for (long long i=1;i<=m;i++){
        scanf("%s", s);
        if (s[0]=='I'){
            long long pos=read(), tot=read(), n2=n+tot, root2;
            if (!tot) continue;
            for (long long i=n+1;i<=n2;i++) a[i]=read();
            root2=build(n+1,n2);
            insert(root,pos+1,root2);
            splay(root2);
            n=n2;
        }
        if (s[0]=='D'){
            long long x=read(), y=read()+x+1;
            if (x+1==y) continue;
            x=find(root,x);
            y=find(root,y);
            del(x,y);
        }
        if (s[2]=='K'){
            long long x=read(), y=read()+x+1, z=read();
            if (x+1==y) continue;
            x=find(root,x);
            y=find(root,y);
            modify(x,y,z);
        }
        if (s[0]=='R'){
            long long x=read(), y=read()+x+1;
            if (x+1==y) continue;
            x=find(root,x);
            y=find(root,y);
            reverse(x,y);
        }
        if (s[0]=='G'){
            long long x=read(), y=read()+x+1;
            x=find(root,x);
            y=find(root,y);
            calc(x,y);
        }
        if (s[2]=='X'){
            printf("%d\n", f[root][2]);
        }
    }
    return 0;
}
