#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
struct zsm{
       int x, y, v;
}l[200000];
int n, m, ff, cnt, next[200000], nu[200000], f[30000];
void add(int u, int v){
     next[++cnt]=next[u];next[u]=cnt;nu[cnt]=v;
}
void dye(int u){
     int j, v;
     j=next[u];
     while (j){
           v=nu[j];
           if (f[v]>-1){
                     if ((f[v]^f[u])==0){
                                       ff=1;
                                       return;
                                       }
                     }
           else{
                f[v]=1^f[u];
                dye(v);
                if (ff) return;
                }
           j=next[j];
           }
}
int flag(int t){
    memset(f,-1,sizeof(f));
    memset(next,0,sizeof(next));
    cnt=n;
    for (int i=1;i<=m;i++)
        if (l[i].v>t){
            add(l[i].x,l[i].y);
            add(l[i].y,l[i].x);
        }
    ff=0;
    for (int i=1;i<=n;i++)
        if (f[i]==-1){
            f[i]=1;
            dye(i);
            if (ff) return 0;
        }
    return 1;
}
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d%d", &n, &m);
    int le=-1, ri, mid;
    for (int i=1;i<=m;i++) {scanf("%d%d%d", &l[i].x, &l[i].y, &l[i].v);ri=max(ri, l[i].v);}
    while (le<ri-1){
          mid=(le+ri)/2;
          if (flag(mid))ri=mid;else le=mid;
          }
    printf("%d\n", ri);
    return 0;
}
