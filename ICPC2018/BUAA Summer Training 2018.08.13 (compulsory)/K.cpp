#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
#define ll long long
#define MAXN 305

int n, m, co, flag[MAXN], d0[MAXN], d1[MAXN];
char c1[MAXN], c2[MAXN];
bool base[MAXN][MAXN], g[MAXN][MAXN];
int calc[MAXN], a[MAXN];
ll jc[MAXN];

void init() {
	jc[0] = 1;
	for (int i = 1; i <= 20; i++) jc[i] = jc[i - 1] * i;
}

ll ksm(ll x, ll y) {
	ll result = 1;
	while (y) {
		if (y & 1) {
			result *= x;
		}
		x *= x;
		y >>= 1;
	}
	return result;
}
void dfs(int u){
	flag[u]=co;
	if (u<m){
		d0[co]++;
		for (int j=m;j<2*m;j++)
			if (base[u][j] && !flag[j]) dfs(j);
			
	}
	else{
		d1[co]++;
		for (int j=0;j<m;j++)
			if (base[u][j] && !flag[j]) dfs(j);
	}
}
ll doit() {
	n = strlen(c1);
	for (int i = 0; i < m; i++) 
		for (int j = 0; j < m; j++)
			base[i][j] = 1;
			
	for (int i = 0; i < n; i += m) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < m; k++) {
				g[j][k] = (c1[i + j] == c2[i + k]);
				base[j][k] &= g[j][k];
			}
		}
	}
	for (int i=0;i<m;i++)
		for (int j=0;j<m;j++)
			base[j+m][i]=base[i][j],
			base[i][j+m]=base[i][j];
	co=0;
	for (int i=0;i<2*m;i++) flag[i]=0, d0[i]=d1[i]=0;
	ll result = 1;
	for (int i=0;i<m;i++)
		if (!flag[i]){
			co++;
			dfs(i);
			//cout<<i<<' '<<flag[i]<<' '<<d0[co]<<' '<<d1[co]<<endl;
			if (d0[co]!=d1[co]) return 0;
			result*=jc[d0[co]];
		}
	return result;
}

int main() {
	init();
	while (~scanf("%d", &m)) {
		scanf("%s", &c1);
		scanf("%s", &c2);
		cout<<doit()<<endl;
	}
}
/*
4
treewood
ertedowo
1
nwerc
ncrew
6
secret
etrcse
1
impossibru
youdontsay
*/
