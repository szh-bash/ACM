#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, root, a[200], fa[200][4],l[200], r[200], list[200], flag[200];
int work(int t){
    int le=0, ri=1, cnt=1;
    list[1]=t;
    memset(flag,0,sizeof(flag));
    flag[0]=flag[t]=1;
    while (le<ri){
          int v=list[++le];
          if (!flag[l[v]]) {list[++cnt]=l[v];flag[l[v]]=1;}
          if (!flag[r[v]]) {list[++cnt]=r[v];flag[r[v]]=1;}
    }
    return cnt;
}
int main(){
    int T;
    cin>>T;
    while (T--){
          cin>>n;
          memset(fa,0,sizeof(fa));
          memset(l,0,sizeof(l));
          memset(r,0,sizeof(r));
          for (int i=1;i<=n;i++) cin>>a[i];
          if (n==1){
                    cout<<"Alice"<<endl;
                    continue;
                    }
          if (n==2){
                    cout<<"Bob"<<endl;
                    continue;
                    }
          for (int i=2;i<n;i++){
              if (a[i]<a[i+1] && a[i]>a[i-1]){
                 l[i]=i-1;fa[i][1]=i+1;
              }
              if (a[i]<a[i+1] && a[i]<a[i-1]){
                 fa[i][1]=i-1;fa[i][2]=i+1;
              }
              if (a[i]>a[i+1] && a[i]>a[i-1]){
                 l[i]=i-1;r[i]=i+1;
              }
              if (a[i]>a[i+1] && a[i]<a[i-1]){
                 r[i]=i+1;fa[i][1]=i-1;
              }
          }
          if (a[1]>a[2]) r[1]=2;
          else fa[1][1]=2;
          if (a[n]>a[n-1]) l[n]=n-1;
          else fa[n][1]=n-1;
          for (int i=1;i<=n;i++)
              if (a[i]==1) {root=i;break;}
          if (!fa[root][2]){
                            int ans;
                            ans=n-work(fa[root][1])+2;
                            if (ans%2) cout<<"Alice"<<endl;
                            else cout<<"Bob"<<endl;
                            }
          else{
               int t0, t1, t2;
               t0=work(root);
               t1=work(fa[root][1])-t0-1;
               t2=work(fa[root][2])-t0-1;
               n=n-t0+1;
               if ((n-t1)%2 || (n-t2)%2) cout<<"Alice"<<endl;
               else cout<<"Bob"<<endl;
               }
              
    }
    return 0;
}
