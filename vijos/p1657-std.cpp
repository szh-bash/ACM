#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int dist[181][181], ga[181][181], match[181], n;
char name[181][256];
bool v[181];

int DFS(int i, int limit)
  {
    v[i] = true;
    for (int j = 1; j <= n; j ++)
      if (ga[i][j] <= limit)
        if (! match[j] || ! v[match[j]] && DFS(match[j], limit))
          {
            match[j] = i;
            return 1;
          }
    return 0;
  }

int Check(int ans)
  {
    memset(match, 0, sizeof(match));
    for (int i = 1; i <= n; i ++)
      {
        memset(v, false, sizeof(v));
        if (! DFS(i, ans)) return 0;
      }
    return 1;
  }

int main()
  {
     freopen("test.in","r",stdin);
     freopen("std.out","w",stdout);
    int a[181], b[181], ans[181], i, j, k, head, tail, mid;
    
    scanf("%d", &n);
    for (i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for (i = 1; i <= n; i ++) scanf("%d", &b[i]);
    for (i = 1; i <= n; i ++) scanf("%s", name[i]);
    for (i = 1; i <= n; i ++)
      for (j = 1; j <= n; j ++) scanf("%d", &dist[i][j]);
    
    for (k = 1; k <= n; k ++)
      for (i = 1; i <= n; i ++)
        for (j = 1; j <= n; j ++)
          {
            if (i == j || i == k || j == k) continue;
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
          }
    for (tail = 0, i = 1; i <= n; i ++)
      for (j = 1; j <= n; j ++)
        {
          ga[i][j] = (b[i] == j) ? a[i] : a[i] - dist[b[i]][j];
          tail = max(tail, ga[i][j]);
        }
    
    for (head = 0, tail ++; head <= tail; )
      {
        mid = head + tail >> 1;
        if (Check(mid)) tail = mid - 1; else head = mid + 1;
      }
    
    Check(tail + 1), printf("%d\n", tail + 1);
    for (i = 1; i <= n; i ++) ans[match[i]] = i;
    for (i = 1; i <= n; i ++) printf("%s\n", name[ans[i]]);
    
    system("pause");
    
    return 0;
  }
