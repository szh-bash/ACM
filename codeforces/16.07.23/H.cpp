#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
int n, m, f[110][9050], a[20];;
int main(){
    int T;
    cin>>T;
    while (T--){
          cin>>n>>m;
          for (int i=1;i<=m;i++) cin>>a[i];
          memset(f,-1,sizeof(f));
          f[0][n]=0;
          int ans=-1;
          for (int i=1;i<=100;i++){
              for (int j=0;j<=n;j++)
                  for (int k=1;k<=m;k++)      
                  if (f[i-1][j+a[k]*i]>=0)
                     f[i][j]=max(f[i][j],f[i-1][j+a[k]*i]+a[k]);
              if (f[i][0]>0) ans=max(ans,f[i][0]);
          }
          cout<<ans<<endl;
    }
    return 0;
}
