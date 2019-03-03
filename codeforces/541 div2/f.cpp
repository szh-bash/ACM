#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 500000
typedef long long ll;
using namespace std;
int cnt, n, fa[N], g[N], l[N], r[N];
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') 
		ch=='-'?q=-1:0,
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
int father(int x){ return fa[x]==x?x:fa[x]=father(fa[x]);}
void print(int u){
	//cout<<u<<endl;
	if (!u) return;
	print(l[u]);
	if (g[u]) printf("%d ", g[u]);
	print(r[u]);
}
int main(){
	cnt=n=read();
	for (int i=1;i<=n;i++) fa[i]=i, g[i]=i;
	for (int i=1;i<n;i++){
		//cout<<i<<endl;
		int u=read(), v=read();
		if (father(u)==father(v)) continue;
		++cnt;
		fa[cnt]=cnt;
		l[cnt]=fa[u], r[cnt]=fa[v];
		fa[fa[u]]=fa[fa[v]]=cnt;
	}
	print(cnt);
	return 0;
}
