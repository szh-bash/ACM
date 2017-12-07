#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n, x, a[1000001], tot;
long long ans, p[1000001];
long long sum(int t, int l, int r){
    if (x==r) return p[t];
    int mid=l+r >>1;
    if (x>mid) return p[t*2]+ sum(t*2+1, mid+1, r);
    else return sum(t*2, l, mid);
}
void updata(int t, int l, int r){
     if (l==r){
               p[t]++;
               return;
               }
     int mid=l+r >>1;
     if (x>mid) updata(t*2+1, mid+1, r);else updata(t*2, l, mid);
     p[t]=p[t*2]+p[t*2+1];
}
int main(){
    scanf("%d", &n);
    for (int i=1;i<=n;i++) scanf("%d", &a[i]);
    tot=-1;
    for (int i=n;i;i--){
        if (a[i]<=a[i+1]) tot=0, ans++;else tot++;
        x=a[i]-1;
        if (x) ans+=sum(1, 1, n)-tot;
        x=a[i];
        updata(1, 1, n);
    }
    cout<<++ans<<endl;
    return 0;
}
