#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define INF 200
using namespace std;
int n, a[200], f[200][5];
int main(){
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) f[i][1]=f[i][2]=f[i][0]=INF;
    for (int i=1;i<=n;i++){
        if (a[i]==0) f[i][0]=min(f[i-1][1],min(f[i-1][0],f[i-1][2]))+1;
        if (a[i]==1){
                     f[i][1]=min(f[i-1][0],f[i-1][2]);
                     f[i][0]=min(f[i-1][0],min(f[i-1][1],f[i-1][2]))+1;
                     }
        if (a[i]==2){
                     f[i][2]=min(f[i-1][0],f[i-1][1]);
                     f[i][0]=min(f[i-1][0],min(f[i-1][2],f[i-1][1]))+1;
                     }
        if (a[i]==3){
                     f[i][1]=min(f[i-1][0],f[i-1][2]);
                     f[i][2]=min(f[i-1][0],f[i-1][1]);
                     f[i][0]=min(f[i-1][0],min(f[i-1][2],f[i-1][1]))+1;
                     }
    }
    int ans=min(f[n][0],min(f[n][1],f[n][2]));
    cout<<ans<<endl;
    return 0;
}
