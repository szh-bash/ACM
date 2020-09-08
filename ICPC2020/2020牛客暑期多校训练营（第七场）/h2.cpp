#include<bits/stdc++.h>
using namespace std;
const int P=1000000007;
 
long long ans;
void work(long long N,long long K){
    long long r;
    for(long long i=2;i<=N;i=r+1){
        r=N/(N/i);
        ans=(ans+((r-i+1)%P)*((N/i)%P)%P)%P;
    }
}
int main(){
    long long N,K;
    cin>>N>>K;
    ans=(N+K-1)%P;
    work(N,K);
    work(N-1,K);
    cout<<ans<<endl;
    return 0;
}
