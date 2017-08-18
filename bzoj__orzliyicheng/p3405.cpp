#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n, s, tp, p[1500];
long long ans;
int main(){
    scanf("%d%d", &n, &s);
    for (int i=0;i<n;i++) scanf("%d", &p[i]);
    sort(p,p+n);
    int tmp=(s-1)/(n-1);
    for (int i=1;i<n;i++){
        if (p[i]-p[i-1]<tmp){
            tp+=tmp-p[i]+p[i-1];
            ans+=(long long)(n-i)*(tmp-p[i]+p[i-1]);
        }
        if (p[i]-p[i-1]>tmp){
            tp-=p[i]-p[i-1]-tmp;
            ans-=(long long)(n-i)*(p[i]-p[i-1]-tmp);
        }
    }
    cout<<tp+p[n-1]<<endl;
    //if (tp+p[n-1]>s) ans-=(long long)(1+tp+p[n-1]-s)*(tp+p[n-1]-s)/2;
    printf("%lld\n", ans);
    return 0;
}
