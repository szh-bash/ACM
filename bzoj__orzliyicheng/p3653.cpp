#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define LL long long
using namespace std;
struct zsm{
       int sz, dep;
}tr[300001];
int cl, x, cr, n, qq, cnt, p[300001], q[300001], le[9000000], ri[9000000], l[300001], r[300001], next[900001], nu[900001];
long long s[9000000];
inline int read() {
    int x = 0;
    char ch = getchar();
    while (ch < '0' || '9' < ch)
        ch = getchar();
    while ('0' <= ch && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x;
}
void add(int u, int v){next[++cnt]=next[u];next[u]=cnt;nu[cnt]=v;}
void dfs(int t, int f){
     int j=next[t];tr[t].sz=1;
     l[t]=++cnt;p[cnt]=t;
     tr[t].dep=tr[f].dep+1;
     while (j){
           if (nu[j]!=f){
              dfs(nu[j],t);
              tr[t].sz+=tr[nu[j]].sz;
           }
           j=next[j];
     }
     r[t]=cnt;
}
void build(int qt, int ll, int rr){
     int mid=ll+rr >>1;
     s[++cnt]=s[qt]+tr[x].sz-1;
     if (ll==rr) return;
     if (tr[x].dep>mid) le[cnt]=le[qt], ri[cnt]=cnt+1, build(ri[qt],mid+1,rr);
     if (tr[x].dep<=mid) ri[cnt]=ri[qt], le[cnt]=cnt+1,build(le[qt],ll,mid);
}
long long query(int t1, int t2, int ll, int rr){
     int mid=ll+rr>>1;
     long long tmp=0;
     if (cl<=ll && cr>=rr) return s[t1]-s[t2];
     if (cl<=mid) tmp+=query(le[t1],le[t2],ll,mid);
     if (cr>mid) tmp+=query(ri[t1],ri[t2],mid+1,rr);
     return tmp;
}
int main(){
	freopen("1.in","r",stdin);
    n=read();qq=read();cnt=n;
    for (int i=1;i<n;i++){
        int u=read(), v=read();
        add(u,v);add(v,u);
    }
    cnt=0;
    dfs(1,0);
    cnt=0;
    for (int i=1;i<=n;i++) x=p[i], q[x]=cnt+1,build(q[p[i-1]],1,n);
    for (int i=1;i<=qq;i++){
        int pp=read(), k=read();
        LL a, b;
        a=(LL)(tr[pp].sz-1)*min(tr[pp].dep-1,k);
        cl=tr[pp].dep+1;cr=tr[pp].dep+k;
        b=query(q[p[r[pp]]],q[p[l[pp]-1]],1,n);
        printf("%lld\n", a+b);
    }
    return 0;
} 
