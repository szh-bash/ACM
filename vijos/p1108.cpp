#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
int mid, ff[100], flag[100], s[100], l[2000], next[600], cnt, va[600], nu[600], f[100], r[100], n, t;
void init();
void add(int u, int v, int vv);
void build();
void work();
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d", &t);
    while (t){
          t--;
          init();
          work();
    }
    return 0;
}
inline void init()
{
          for (int i=0;i<=23;i++) scanf("%d", &r[i]);
          scanf("%d", &n);
          memset(ff,0,sizeof(ff));
          for (int i=1;i<=n;i++){
              int u;
              scanf("%d", &u);
              ff[u]++;
          }
 }
void add(int u, int v, int vv){
     next[++cnt]=next[u];next[u]=cnt;nu[cnt]=v;va[cnt]=vv;
}
inline void build(){
     cnt=24;
     memset(next,0,sizeof(next));
     for (int i=1;i<=23;i++) {add(i-1,i,ff[i]);add(i,i-1,0);}///////???
     add(24,0,ff[0]);add(0,24,0);
     for (int i=8;i<=23;i++) add(i,i-8,-r[i]);
     for (int i=0;i<=7;i++) add(i,i+16,-r[i]+mid);
 }
inline int spfa(){
    for (int i=0;i<=22;i++)s[i]=9999999;s[24]=s[0];
    memset(flag,0,sizeof(flag));
    memset(f,0,sizeof(f));
    int le=0, ri=1, u, j, v;
    l[1]=23;f[23]=flag[23]=1;s[23]=0;
    while (le!=ri){
          u=l[++le];
          flag[u]=0;
          j=next[u];
          while (j){
                v=nu[j];
                if (s[u]+va[j]<s[v]){
                    s[v]=s[u]+va[j];
                    if (!flag[v]){
                                 flag[v]=1;
                                 f[v]++;
                                 if (f[v]==24) return 0;
                                 l[++ri]=v;
                                 }
                                 
                }
                j=next[j];
          }
    }
    return 1;
}
inline void work()
{
     int le=-1,ri=n+1;
     while (le<ri-1){
           mid=(le+ri)/2;
           build();
           if (spfa()) ri=mid;else le=mid;
           }
     if (ri==n+1) cout<<"No Solution"<<endl;
     else printf("%d\n", ri);
 }
