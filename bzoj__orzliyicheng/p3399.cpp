#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 25005;
int N, X, Y, total = 0, A [MAXN], B [MAXN];
inline int diff (int a, int b) {
    return a < b ? X * (b - a) : Y * (a - b);
}
int main () {
    scanf ("%d %d %d", &N, &X, &Y);
    for (int i = 0; i < N; i++)
        scanf ("%d %d", A + i, B + i);
    sort (A, A + N);
    sort (B, B + N);
    for (int i = 0; i < N; i++)
        total += diff (A [i], B [i]);
    printf ("%d\n", total);
    return 0;
}
