#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream> 
#include <algorithm>
using namespace std;
const int maxn = 100005;
struct point{
  double x, y;
}f[maxn], t[maxn];
struct st{
  double a, b, r;
}a[maxn];
int n, m, s[maxn], p[maxn];
double v[maxn];
bool operator<(point a, point b) { return a.x < b.x || (a.x == b.x && a.y < b.y); }
bool cmp(int l, int r) { return a[l].b / a[l].a > a[r].b / a[r].a; }
double xj(point a, point b, point c)
{
  return (b.x - a.x) * (c.y - b.y) - (b.y - a.y) * (c.x - b.x);
}
double calc(point f, int i) { return f.x * a[i].a + f.y * a[i].b; }
void cdq(int l, int r, double m)
{
  if (l == r)
  {
    v[l] = max(v[l], m);
    f[l].y = v[l] / (a[l].a * a[l].r + a[l].b);
    f[l].x = a[l].r * f[l].y;
    return;
  }
  int mid = (l + r) / 2, m1 = l, m2 = mid + 1, bk = 0, ft = 0;
  for (int i = l; i <= r; ++i)
    if (p[i] <= mid) s[m1++] = p[i]; else s[m2++] = p[i];
  memcpy(p + l, s + l, sizeof(int) * (r - l + 1));
  cdq(l, mid, m);
  for (int i = l; i <= mid; ++i)
  {
    while (bk > 1 && xj(t[bk - 2], t[bk - 1], f[i]) >= 0) --bk;
    t[bk++] = f[i];
  }
  for (int i = mid + 1; i <= r; ++i)
  {
    while (ft < bk - 1 && calc(t[ft], p[i]) < calc(t[ft + 1], p[i])) ++ft;
    v[p[i]] = max(v[p[i]], calc(t[ft], p[i]));
  }
  cdq(mid + 1, r, v[mid]);
  merge(f + l, f + mid + 1, f + mid + 1, f + r + 1, t);
  memcpy(f + l, t, sizeof(point) * (r -l + 1));
}
int main()
{
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i)
  {
    scanf("%lf%lf%lf", &a[i].a, &a[i].b, &a[i].r);
    p[i] = i;
  }
  std::sort(p, p + n, cmp);
  cdq(0, n- 1, m);
  printf("%.3f", v[n - 1]);
}
