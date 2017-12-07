#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1111111;
typedef long long int lli;
lli num[N];
int main(){
    ios::sync_with_stdio(false);
    int n,m,k; cin>>n>>m>>k;
    n/=k; m/=k;
    memset(num,0,sizeof(num));
    lli res=(lli)n*(lli)m;
    for(int i=2;i<=n;i++){
        res-=(lli)(1-num[i])*(lli)(n/i)*(lli)(m/i);
        for(int j=2*i;j<=n;j+=i)
            num[j]+=(1-num[i]);
    }
    cout<<res<<'\n';
    return 0;
}
