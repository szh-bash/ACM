#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n, a[20000];
long long ans, f[20000][10];
int ff(int t, int aa){
    int tot=0;
    while (aa) tot+=aa%2,aa=aa/2;
    if (a[t]==tot) return 1;return 0;
}
int flag(int t, int aa, int b){
    if (t==2 && b%2) return 0;
    if (t==n && aa/4) return 0;
    if (((aa/4*4)^aa)==b/2 && ff(t,aa) && ff(t-1,b)) return 1;
    return 0;
}
int main(){
    scanf("%d", &n);
    for (int i=1;i<=n;i++) scanf("%d", &a[i]);
    if (a[1]==0) f[1][0]=1;
    if (a[1]==1) f[1][2]=f[1][4]=1;
    if (a[1]==2) f[1][6]=1;
    for (int i=2;i<=n;i++)
      for (int j=0;j<=7;j++)
        for (int k=0;k<=7;k++)
          if (flag(i,j,k)) f[i][j]+=f[i-1][k];
    if (a[n]==0)ans+=f[n][0];
    if (a[n]==1)ans+=f[n][1]+f[n][2];
    if (a[n]==2)ans+=f[n][3];
    cout<<ans<<endl;
    system("pause");
    return 0;
}
