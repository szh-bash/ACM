#include <cstdio>
#include <iostream>
using namespace std;
long long f[10010];
int v, n;
int main(){
    cin>>v>>n;
    f[0]=1;
    for (int i=1;i<=v;i++){
        int a;
        cin>>a;
        for (int j=a;j<=n;j++)
            f[j]+=f[j-a];
    }
    cout<<f[n]<<endl;
    return 0;
}
