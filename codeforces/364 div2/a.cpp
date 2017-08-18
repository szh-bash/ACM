#include  <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, sum, a[200], f[200];
int main(){
    scanf("%d", &n);
    for (int i=1;i<=n;i++) cin>>a[i], sum+=a[i], f[i]=1;
    n/=2;
    sum/=n;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n*2;j++)
            if (f[j]){
                      for (int k=j+1;k<=n*2;k++)
                          if (f[k] && a[j]+a[k]==sum){
                             cout<<j<<' '<<k<<endl;
                             f[j]=f[k]=0;
                             break;
                          }
                      break;
                      }
    return 0;
}
