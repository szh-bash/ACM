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
#define N 100005
int n, m, k, f[N];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
void solve(){
	n=read();m=read();k=read();
	for (int i=1;i<=n;i++) f[i]=-1;
	f[k]=0;
	for (int i=1;i<=m;i++){
		int u=read(), v=read();
		if (f[u]<0 && f[v]<0) continue;
		if (f[u]>-1 && f[v]>-1){
			if (f[u]<f[v])
				f[v]=f[u],
				f[u]++;
			else if (f[u]>f[v])
				f[u]=f[v],
				f[v]++;
			// int gu=min(f[v],f[u]+1);
			// int gv=min(f[u],f[v]+1);
			// f[u]=g[u];
			// f[v]=g[v];
			continue;
		}
		// cout<<u<<' '<<v<<' '<<f[u]<<' '<<f[v]<<endl;
		if (f[u]>-1){
			f[v]=f[u];
			f[u]++;
		}
		else if (f[v]>-1){
			f[u]=f[v];
			f[v]++;
		}
		// cout<<u<<' '<<v<<' '<<f[u]<<' '<<f[v]<<endl;
	}
	for (int i=1;i<=n;i++) printf("%d%s", f[i], i==n?"\n":" ");
}
int main(){
	for (int _=read();_;_--) solve();
    return 0;
}
