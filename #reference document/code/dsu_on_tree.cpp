#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;
int read()
{
	int p = 0, q = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
		ch == '-' ? q = -1 : 0, ch = getchar();
	while (ch >= '0' && ch <= '9')
		p = p * 10 + ch - '0', ch = getchar();
	return p * q;
}
#define N 100005
#define M N * 3
ll sum, ans[N];
int n, cnt, Son, ma;
int g[N], c[N], size[N], son[N];
int nex[M], nu[M];
void link(int u, int v)
{
	nex[++cnt] = nex[u];
	nex[u] = cnt;
	nu[cnt] = v;
}
void dfs_cut(int u, int fa)
{
	size[u] = 1;
	son[u] = 0;
	int mx = 0;
	for (int j = nex[u]; j; j = nex[j])
	{
		int v = nu[j];
		if (v == fa)
			continue;
		dfs_cut(v, u);
		if (size[v] > mx)
			mx = size[v], son[u] = v;
		size[u] += size[v];
	}
}
void calc(int u, int fa, int val)
{
	g[c[u]] += val;
	if (g[c[u]] > ma)
		ma = g[c[u]], sum = c[u];
	else if (g[c[u]] == ma)
		sum += c[u];
	for (int j = nex[u]; j; j = nex[j])
	{
		int v = nu[j];
		if (v == fa || v == Son)
			continue;
		calc(v, u, val);
	}
}
void dsu_ot(int u, int fa, int opt)
{
	for (int j = nex[u]; j; j = nex[j])
	{
		int v = nu[j];
		if (v == fa || v == son[u])
			continue;
		dsu_ot(v, u, 0);
	}
	if (son[u])
		dsu_ot(son[u], u, 1), Son = son[u];
	calc(u, fa, 1);
	Son = 0;
	ans[u] = sum;
	if (!opt)
		calc(u, fa, -1), sum = 0, ma = 0;
}
int main()
{
	cnt = n = read();
	for (int i = 1; i <= n; i++)
		c[i] = read();
	for (int i = 1; i < n; i++)
	{
		int u = read(), v = read();
		link(u, v);
		link(v, u);
	}
	dfs_cut(1, 0);
	dsu_ot(1, 0, 0);
	for (int i = 1; i <= n; i++)
		printf("%I64d%s", ans[i], i == n ? "\n" : " ");
	return 0;
}
