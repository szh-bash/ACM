#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
 
using namespace std;
const int N = 12005;
const int M = 900001;
const int inf = (int) 1e9;
   
struct edges{
    int next, to, f;
    edges() {}
    edges(int _next, int _to, int _f) : next(_next), to(_to), f(_f) {}
} e[M];
long long ans;
int n, m, S, T;
int first[N], tot = 1;
int q[N], a[N >> 1], d[N];
 
inline int read() {
    int x = 0;
    char ch = getchar();
    while (ch < '0' || '9' < ch)
        ch = getchar();
    while ('0' <= ch && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x;
}
 
inline void add_edge(int x, int y, int z){
    e[++tot] = edges(first[x], y, z);
    first[x] = tot;
}
   
inline void Add_Edges(int x, int y, int z){
    add_edge(x, y, z);
    add_edge(y, x, 0);
}
   
bool bfs(){
    memset(d, 0, sizeof(d));
    q[1] = S, d[S] = 1;
    int l = 0, r = 1, x, y;
    while (l < r){
        ++l;
        for (x = first[q[l]]; x; x = e[x].next){
            y = e[x].to;
            if (!d[y] && e[x].f)
                q[++r] = y, d[y] = d[q[l]] + 1;
        }
    }
    return d[T];
}
   
int dinic(int p, int limit){
    if (p == T || !limit) return limit;
    int x, y, tmp, rest = limit;
    for (x = first[p]; x; x = e[x].next){
        y = e[x].to;
        if (d[y] == d[p] + 1 && e[x].f && rest){
            tmp = dinic(y, min(rest, e[x].f));
            rest -= tmp;
            e[x].f -= tmp, e[x ^ 1].f += tmp;
            if (!rest) return limit;
        }
    }
    if (limit == rest) d[p] = 0;
    return limit - rest;
}
   
int Dinic(){
    int res = 0, x;
    while (bfs())
        res += dinic(S, inf);
    return res;
}
 
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
 
inline int Sqr(int x) {
    return x * x;
}
 
inline bool check(int x, int y) {
    long long  t = (long long)x * x + y * y, a=sqrt(t);
    return a*a == t && gcd(x, y) == 1;
}
 
int main() {
    int i, j;
    n = read();
    S = n << 1 | 1, T = S + 1;
    for (i = 1; i <= n; ++i) a[i] = read();
    for (i = 1; i <= n; ++i) {
        int x = read();
        Add_Edges(S, i, x);
        Add_Edges(i + n, T, x);
        ans += x;
    }
    for (i = 1; i <= n; ++i)
        for (j = i + 1; j <= n; ++j)
            if (check(a[i], a[j]))
                Add_Edges(i, j + n, inf), Add_Edges(j, i + n, inf);
    printf("%lld\n", ans - Dinic() / 2);
    return 0;
}
