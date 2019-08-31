#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
#include<map>
#incldue<unordered_map>
 
const int MAXN = 150000;
 
int not_prime[200000];
int prime[200000];
int cnt_prime;
int product2[200000];
 
void init()
{
	not_prime[1] = 1;
	for (int i = 2; i <= MAXN; i++)
	{
		if (!not_prime[i])
		{
			prime[++cnt_prime] = i;
		}
		for (int j = 1; j <= cnt_prime; j++)
		{
			if ((long long)i * prime[j] > MAXN)
			{
				break;
			}
			not_prime[i * prime[j]] = 1;
			if (!not_prime[i] && prime[j] != i)
			{
				product2[i * prime[j]] = 1;
			}
			if (i % prime[j] == 0)
			{
				break;
			}
		}
	}
}
 
int fa[200000];
int findfa(int i)
{
	return fa[i] == i ? i : (fa[i] = findfa(fa[i]));
}
int size[200000];
 
int u[200000], v[200000], w[200000];
 
struct node
{
	int begin, end;
};
 
struct edge
{
	int u, v, w;
	int next;
};
 
node p[200000];
edge e[400000];
int cnte;
 
void addedge(int u, int v, int w)
{
	cnte++;
	e[cnte].next = 0;
	e[cnte].u = u;
	e[cnte].v = v;
	e[cnte].w = w;
	if (p[u].begin == 0)
	{
		p[u].begin = cnte;
	}
	else
	{
		e[p[u].end].next = cnte;
	}
	p[u].end = cnte;
}
 
std::unordered_map<int, int> q;
 
//std::vector<int> son[200000];
 
int main()
{
	freopen("evaluations.in", "r", stdin);
	init();
	int T;
	scanf("%d", &T);
	for (int tt = 1; tt <= T; tt++)
	{
		//cnte = 0;
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			fa[i] = i;
			size[i] = 1;
			//son[i].clear();
		}
		for (int i = 1; i <= n; i++)
		{
			p[i].begin = p[i].end = 0;
		}
		for (int i = 1; i <= n-1; i++)
		{
			scanf("%d %d %d", &u[i], &v[i], &w[i]);
		}
		for (int i = 1; i <= n-1; i++)
		{
			if (w[i] == 1)
			{
				findfa(u[i]);
				findfa(v[i]);
				if (size[fa[u[i]]] < size[fa[v[i]]])
				{
					size[fa[v[i]]] += size[fa[u[i]]];
					fa[fa[u[i]]] = fa[v[i]];
				}
				else
				{
					size[fa[u[i]]] += size[fa[v[i]]];
					fa[fa[v[i]]] = fa[u[i]];
				}
			}
		}
		long long ans = 0;
		for (int i = 1; i <= n-1; i++)
		{
			if (w[i] != 1)
			{
				if (!not_prime[w[i]])
				{
					findfa(u[i]);
					findfa(v[i]);
					addedge(fa[u[i]], fa[v[i]], w[i]);
					addedge(fa[v[i]], fa[u[i]], w[i]);
					/*
					son[fa[u[i]]].push_back(fa[v[i]]);
					son[fa[v[i]]].push_back(fa[u[i]]);
					*/
				}
				else if (product2[w[i]])
				{
					findfa(u[i]);
					findfa(v[i]);
					ans += (long long)size[fa[u[i]]] * size[fa[v[i]]];
				}
			}
		}
		for (int i = 1; i <= n; i++)
		{
			if (fa[i] == i)
			{
				q.clear();
				long long cur = 0;
				for (int j = p[i].begin; j; j = e[j].next)
				{
					ans += (cur - q[e[j].w]) * size[e[j].v];
					cur += size[e[j].v];
					q[e[j].w] += size[e[j].v];
				}
				/*
				for (size_t j = 0; j < son[i].size(); j++)
				{
					ans += cur * size[son[i][j]];
					cur += size[son[i][j]];
				}
				*/
			}
		}
		std::cout<<"Case "<<tt<<": "<<ans<<std::endl;
	}
}
