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
#define N 1000
#define M 3000
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
void add(int u, int v, int w){
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;id[cnt]=w;
}
int main(){
	while (~scanf("%d%d", &n, &m)){
		n=read();m=read();
		cnt=n+(!(n&1));
		for (int i=1;i<=m;i++){
			int u=read(), v=read();
			add(u, v, i);
			add(v, u, -i);
			d[u]++;
			d[v]++;
		}
		for (int i=1;i<=n;i++)
			if (!flag[i]) dfs(i);
	}
    return 0;
}
