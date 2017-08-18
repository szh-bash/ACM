#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
int n, m, mid, ri, le, a[100010];
bool flag(int x){
    int tmp=0, tp=m-1;
    for (int i=1;i<=n;i++)
        if (tmp+a[i]<=x) tmp+=a[i];
        else{
            tp--;
            if (tp<0) break;
            tmp=a[i];
        }
    return tp>=0;
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i=1;i<=n;i++) scanf("%d", &a[i]), ri+=a[i], le=max(le, a[i]);
    le--;
    while (le<ri-1){
        mid=le + ri >>1;
        if (flag(mid)) ri=mid;else le=mid;
    }
    printf("%d\n", ri);
    return 0;
}
