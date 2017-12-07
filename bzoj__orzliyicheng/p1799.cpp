#include <cmath> 
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
long long solve(int t, bool flag){
     max=9;if (flag) max=f[len+1-t];
     for (int i=0;i<=max;i++)
         
}
long long fx(long long x){
     if (!x) return 0;
     len=floor(log(x))+1;
     int tmp=x;
     memset(dp,0,sizeof(dp));
     for (int i=1;i<=len;i++) f[i]=tmp%10, tmp/=10;
     ans=0;
     for (int i=1;i<=tmp;i++) ans=ans+solve(2,i==f[len]);
     return ans;
}
int main(){
    scanf("%d%d", &n, &m);
    cout<<fx(m)-fx(n)<<endl;
    return 0;
}
