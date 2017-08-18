#include <cstdio>
#include <iostream>
using namespace std;
int n;
long double f[300000 + 9],T[300000 + 9];
int main()
{
    scanf("%d\n",&n);
    for (int i = 1; i <= n; ++i) {
        long double a;
        cin>>a;
            f[i] = f[i - 1] + (2 * T[i - 1] + 1) * a;
            T[i] = (T[i - 1] + 1) * a;
    }
    printf("%.10f\n", (double)f[n]);
}
