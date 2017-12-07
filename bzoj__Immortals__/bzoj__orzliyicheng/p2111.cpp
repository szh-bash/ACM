#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
const double eps=1e-8;
using namespace std;
long long f[1000100], c[1000100];
int d[1000100], n, m, p;
int power(int a, int b){
    long long tmp=1;
    while (b){
          if (b%2) tmp=tmp*a % p;
          a=(long long)a*a %p;
          b/=2;
    }
    return tmp;
}
int C(int m, int n){
    return (c[n]*power(c[m], p-2)%p)*power(c[n-m], p-2)%p;
}
int calc(int x){
    int len=int (log(x)/log(2)+eps)+1;
    int y=d[len-1]-1+d[len-1]/2;
    if (x>=y) return d[len-1]-1;
    return x-d[len-1]+d[len-1]/2;
}
int main(){
    scanf("%d%d", &n, &p);
    c[0]=1;
    for (int i=1;i<=n;i++) c[i]=(long long)c[i-1]*i % p;
    d[0]=1;
    for (int i=1;i<=22;i++) d[i]=d[i-1]*2;
    f[0]=1;
    for (int i=1;i<=n;i++){
        int ls=calc(i);
        int rs=i-ls-1;
        f[i]=(f[ls]*f[rs]%p)*C(ls, i-1)%p;
        //cout<<ls<<' '<<rs<<' '<<C(ls, i-1)<<' '<<f[i]<<endl;
    }
    cout<<f[n]<<endl;
    system("pause");
    return 0;
}
