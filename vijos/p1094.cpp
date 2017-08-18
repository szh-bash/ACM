#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
int next[3000000], nu[3000000], va[3000000], l[600010], flag[600000], cnt, n, m, k, ll, r, c, f[600000], st, end;
long long s[600000];
void add(int u, int v, int vv){
     next[++cnt]=next[u];next[u]=cnt;nu[cnt]=v;va[cnt]=vv;
}
void init(){
     freopen("test.in","r",stdin);
     freopen("test.out","w",stdout);
    scanf("%d%d", &n, &m);
    cnt=n;
    memset(next,0,sizeof(next));
    for (int i=1;i<=m;i++){
        scanf("%d%d%d", &ll, &r, &c);
        if (c==1) add(ll,r,-1);
        if (!c) {add(ll,r,0);add(r,ll,0);}
        if (c==-1) add(r,ll,-1);
    }
}
long long spfa(){
     int le, ri, u, j, v;
     for (int i=1;i<=n;i++) s[i]=(long long)300*10000000;
     memset(flag,0,sizeof(flag));
     memset(f,0,sizeof(f));
     flag[st]=ri=f[st]=1;
     s[st]=le=0;
     l[1]=st;
     while (le!=ri){
           le=le%600000+1;
           u=l[le];
           flag[u]=0;
           j=next[u];
           while (j){
                 v=nu[j];
                 if (s[u]+va[j]<s[v]){
                                      s[v]=s[u]+va[j];
                                      if (!flag[v]){
                                                    flag[v]=1;
                                                    if (++f[v]==n) return -1;
                                                    ri=ri%600000+1;
                                                    l[ri]=v;
                                                    }
                                      }
                 j=next[j];
           }
     }
     if (s[end]>0 && end==1) {
                  st=1;end=n;
                  return spfa();
                  }
     return -s[end];
}
int main()
{
    init();
    st=n;end=1;
    long long tmp=spfa();
    if (tmp>=0) cout<<tmp<<endl;else cout<<"NO"<<endl;
    return 0;
}
