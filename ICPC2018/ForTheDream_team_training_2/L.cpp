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
#define N 800000
#define mo 1000000007
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int n, m, k, ans, cnt, size[N], nex[N], nu[N];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
int power(ll a, int b){
	ll c=1;
	while (b){
		if (b&1) c=c*a%mo;
		a=a*a%mo;
		b>>=1;
	}
	return c;
}
void add(int u, int v){
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;
}
void dfs(int u, int fa){
	size[u]=1;
	for (int j=nex[u];j;j=nex[j]){
		int v=nu[j];
		if (v==fa) continue;
		dfs(v, u);
		if (size[v]>=k && (n-size[v])>=k) ans++; 
		size[u]+=size[v];
	}
}
int main(){
	for (int _=read();_;_--){
		cnt=n=read();k=read();
		for (int i=1;i<=n;i++) nex[i]=0;
		for (int i=1;i<n;i++){
			int u=read(), v=read();
			add(u,v);
			add(v,u);
		}
		ans=0;
		dfs(1,0);
		printf("%d\n",ans);
	}
    return 0;
}

