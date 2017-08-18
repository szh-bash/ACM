#include<cstdio>
#include<iostream>
using namespace std;
int n, f[60000], g[60000];
int main(){
    scanf("%d", &n);
    f[1]=1;f[2]=3;f[3]=5;
    int t=1; 
    for (int i=1;i<=n;i++) t*=2,g[i]=(t+9999)%10000, t=t%10000;
    for (int i=4;i<=n;i++){
        f[i]=999990;
        for (int j=1;j<i;j++)
          f[i]=min(f[i],(f[j]*2+g[i-j])%10000);
    }
    cout<<f[n]<<endl;
    system("pause");
    return 0;
}
