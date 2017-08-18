#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, F, T, sg[2000000], mark[3000000], x, ans, t;
void get_SG(){
     for (int i=0;i<F;i++) sg[i]=0;
     for (int i=F;i<=200000;i++){
         int sq=ceil(sqrt(i));
         for (int j=2;j<=sq && i/j>=F-1;j++){
             int x=i/j;int y=x+1;
             int a=i-x*j, b=x-a;
             mark[sg[x*(1&a)]^sg[y*(1&b)]]=i;
         }
         for (int j=1;j<=sq;j++){
             int x=i/j;
             int a=i-x*j, b=x-a;
             mark[sg[(1&a)*(j+1)]^sg[(1&b)*j]]=i;
             if ((j&1==0) && (j+1)<=b) mark[sg[(1&a)*(j+1)]^sg[(1&b)*j]^sg[j]]=i;
             if ((j&1) && (j+1)<=b )mark[sg[(1&a)*(j+1)]^sg[(1&b)*j]^sg[j+1]]=i;
         }
         for (int j=0;;j++)
             if (mark[j]!=i){
                sg[i]=j;
                break;
             }
     }
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d%d", &T, &F);
    get_SG();
    while (T){
          T--;ans=0;
          scanf("%d", &n);
          for (int i=1;i<=n;i++) scanf("%d", &x), ans^=sg[x];
          printf("%d%c",ans==0?0:1,T?' ':'\n');
    }
    return 0;
}
