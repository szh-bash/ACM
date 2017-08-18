#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
 
using namespace std;
 
const int MaxL = 500000 + 5;
 
typedef long long LL;
 
LL Ans, Temp;
LL f[MaxL];
 
int n, Top;
int A[MaxL], Rank[MaxL], SA[MaxL], Height[MaxL], St[MaxL];
int VA[MaxL], VB[MaxL], VC[MaxL], Sum[MaxL];
 
char S[MaxL];
 
inline bool Cmp(int *a, int x, int y, int l) {
    return (a[x] == a[y]) && (a[x + l] == a[y + l]);
}
 
void DA(int *A, int n, int m) {
    int *x, *y, *t;
    x = VA; y = VB;
    for (int i = 1; i <= m; ++i) Sum[i] = 0;
    for (int i = 1; i <= n; ++i) ++Sum[x[i] = A[i]];
    for (int i = 2; i <= m; ++i) Sum[i] += Sum[i - 1];
    for (int i = n; i >= 1; --i) SA[Sum[x[i]]--] = i;
    int p, q;
    p = 0;
    for (int j = 1; p < n; j <<= 1, m = p) {   
        q = 0;
        for (int i = n - j + 1; i <= n; ++i) y[++q] = i;
        for (int i = 1; i <= n; ++i) {
            if (SA[i] <= j) continue;
            y[++q] = SA[i] - j;
        }
        for (int i = 1; i <= m; ++i) Sum[i] = 0;
        for (int i = 1; i <= n; ++i) VC[i] = x[y[i]];
        for (int i = 1; i <= n; ++i) ++Sum[VC[i]];
        for (int i = 2; i <= m; ++i) Sum[i] += Sum[i - 1];
        for (int i = n; i >= 1; --i) SA[Sum[VC[i]]--] = y[i];
        t = x; x = y; y = t; p = 1;
        x[SA[1]] = 1;
        for (int i = 2; i <= n; ++i) 
            x[SA[i]] = Cmp(y, SA[i], SA[i - 1], j) ? p : ++p;
    }
    for (int i = 1; i <= n; ++i) Rank[SA[i]] = i;
     
    //GetHeight
    int h = 0, o;
    for (int i = 1; i <= n; ++i) {
        if (Rank[i] == 1) continue;
        o = SA[Rank[i] - 1];
        while (A[i + h] == A[o + h]) ++h;
        Height[Rank[i]] = h;
        if (h > 0) --h;
    }
}
 
int main() 
{
	freopen("1.in","r",stdin);
	freopen("std.out","w",stdout);
    scanf("%s", S + 1);
    n = strlen(S + 1);
    for (int i = 1; i <= n; ++i) A[i] = S[i] - 'a' + 1;
    DA(A, n, 26);
    Ans = 0ll; Temp = 0ll;
    for (int i = 1; i <= n; ++i) 
        Ans += (LL)(n - i + 1) * (LL)(n - 1);
    Top = 0;
    St[++Top] = n + 1;
    for (int i = n; i >= 2; --i) {
        while (Top > 0 && Height[St[Top]] > Height[i]) --Top;
        int x = St[Top];
        f[i] = (LL)Height[i] + (LL)Height[i] * (x - i - 1) + (LL)f[x];
        Temp += f[i];
        St[++Top] = i;
    }
    Ans -= Temp * 2ll;
    printf("%lld\n", Ans);
    return 0;
}
