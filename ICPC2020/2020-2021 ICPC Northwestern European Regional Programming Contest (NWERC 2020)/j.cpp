#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <tr1/unordered_map>
#define mo 1000000007
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
#define N 200005
#define M N*3
int n, m, cnt, nex[M], nu[M];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
void add(int u, int v){
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;
}
int a, b, flag[N], stack[N], cl[N];
void print(){
	printf("%d %d\n", cnt, (n-cnt)/2);
	for (int i=1;i<=cnt;i++) printf("%d%s", stack[i], (i==cnt?"\n":" "));
	for (int i=1, j=(n-cnt)/2;i<=n;i++)
		if (!cl[i]) printf("%d%s", i, ((--j)?" ":"\n"));
	for (int i=1, j=(n-cnt)/2;i<=n;i++)
		if (cl[i]==2) printf("%d%s", i, (--j)?" ":"\n");
}
int dfs(int u){
	flag[u]=1;
	a--;
	cl[u]++;
	stack[++cnt]=u;
	if (a==b){
		print();
		return 1;
	}
	for (int j=nex[u];j;j=nex[j]){
		int v=nu[j];
		if (flag[v]) continue;
		if (dfs(v)) return 1;
	}
	b++;
	cl[u]++;
	cnt--;
	if (a==b){
		print();
		return 1;
	}
	return 0;
}
int main(){
	cnt=n=read(), m=read();
	for (int i=1;i<=m;i++) {
		int u=read(), v=read();
		add(u,v);
		add(v,u);
	}
	a=n;
	cnt=0;
	dfs(1);
    return 0;
}
