#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
long long n, l, v1, v2, k;
int main(){
    cin>>n>>l>>v1>>v2>>k;
    int m=n/k;
    if (n%k==0) m--;
    double t=(double)(v1+v2)*l/(2*v1*m+(v1+v2))/v2;
    double ans=(l-v2*t)/v1+t;
    printf("%.7lf\n", ans);
    while (1);
    return 0;
}
