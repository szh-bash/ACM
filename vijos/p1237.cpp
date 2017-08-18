#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const double pi=0.6180339887498949;
int n, ans1, ans2, a[40000];
double abs(double t){if (t>0) return t;else return -t;}
int cmp(int a, int b){return a<b;}
int main(){
    scanf("%d", &n);
    for (int i=1;i<=n;i++) scanf("%d", &a[i]);
    sort(a+1,a+1+n,cmp);
    ans1=0;ans2=1;
    for (int i=1;i<=n;i++){
        int le=i, ri=n;
        while (le<ri-1){
            int mid=(le+ri)/2;
            if (a[i]<pi*a[mid]) ri=mid;else le=mid;
        }
        if (abs(pi-(double)a[i]/a[le])>abs(pi-(double)a[i]/a[ri])) le=ri;
        if (abs(pi-(double)a[i]/a[le])<abs(pi-(double)ans1/ans2)){
            ans1=a[i];
            ans2=a[le];
        }
    }
    printf("%d\n%d\n", ans1, ans2);
    return 0;
}
