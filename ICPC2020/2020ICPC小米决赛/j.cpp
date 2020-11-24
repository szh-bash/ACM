#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <tr1/unordered_map>
#define num(x) (((x)>='0' && (x)<='9'))
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
using namespace std;
using namespace std::tr1;
#define N 22
#define M 1<<N
int n, l[N], w[N], s[M];
ld f[M];
int main(){
    cin>>n;
    for (int i=0;i<n;i++) cin>>l[i];
    for (int i=0;i<n;i++) cin>>w[i];
    int T=1<<n;
    for (int i=1;i<T;i++)
        for (int j=0;j<n;j++)
            if ((1<<j)&i){
                s[i]=s[i^(1<<j)]+w[j];
                break;
            }
    for (int i=0;i<T;i++)
        for (int j=0;j<n;j++)
            if (!((1<<j)&i))
                f[i|(1<<j)] = max(f[i|(1<<j)], 
                                max(f[i]+l[j]/(ld)2*w[j]/s[i|(1<<j)], 
                                    l[j]-l[j]/(ld)2*w[j]/s[i|(1<<j)]));
    // cout<<f[T-1]<<endl;
    printf("%.9Lf\n", f[T-1]);
    return 0;
}