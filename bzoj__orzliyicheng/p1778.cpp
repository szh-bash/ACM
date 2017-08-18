#include <cstdio>  
#include <cmath>  
#include <algorithm>  
  
using namespace std;  
  
typedef long double LD;  
  
const int maxn = 305, maxm = 50005;  
const LD eps = 1e-13;  
  
int n, m, head[maxn], cnt, du[maxn];  
LD p, q, A[maxn][maxn];  
  
struct _edge {  
    int v, next;  
} g[maxm << 1];  
  
inline int iread() {  
    int f = 1, x = 0; char ch = getchar();  
    for(; ch < '0' || ch > '9'; ch = getchar()) f = ch == '-' ? -1 : 1;  
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';  
    return f * x;  
}  
  
inline void add(int u, int v) {  
    g[cnt] = (_edge){v, head[u]};  
    head[u] = cnt++;  
}  
  
inline void gauss() {  
    for(int i = 1; i <= n; i++) {  
        if(fabs(A[i][i]) < eps) for(int j = i + 1; j <= n; j++) if(fabs(A[j][i]) > eps) {  
            for(int k = 1; k <= m; k++) swap(A[i][k], A[j][k]);  
            break;  
        }  
        for(int j = 1; j <= n; j++) if(i ^ j && fabs(A[j][i]) > eps) {  
            LD t = A[j][i] / A[i][i];  
            for(int k = 1; k <= m; k++) A[j][k] -= t * A[i][k];  
        }  
    }  
    for(int i = 1; i <= n; i++) A[i][m] /= A[i][i];  
}  
  
int main() {  
    n = iread(); m = iread(); p = iread(); q = iread(); LD pro = p / q, antipro = 1.0 - pro;  
    for(int i = 1; i <= n; i++) head[i] = -1; cnt = 0;  
  
    for(int i = 1; i <= m; i++) {  
        int u = iread(), v = iread();  
        add(u, v); add(v, u);  
        du[u]++; du[v]++;  
    }  
  
    m = n + 1;  
    for(int i = 1; i <= n; i++) {  
        A[i][i] = 1.0;  
        for(int j = head[i]; ~j; j = g[j].next) A[i][g[j].v] = -antipro / (LD)du[g[j].v];  
    }  
    A[1][m] = 1.0;  
  
    gauss();  
  
    for(int i = 1; i <= n; i++) printf("%.9Lf\n", A[i][m] * pro);  
    return 0;  
}  
