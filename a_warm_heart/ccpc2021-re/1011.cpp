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
#define M 500005
int n, cnt, num[N], dep[N], fa[N], nex[M], a[N], nu[M], fa_dir[N];
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
bool cmp(int x, int y){
	return a[x]<a[y];
}
int father(int x){ return fa[x]==x?x:fa[x]=father(fa[x]);}
void solve(){
	cnt=n=read();
	for (int i=1;i<=n;i++) nex[i]=0;
	for (int i=1;i<n;i++){
		int u=read(), v=read();
		add(u, v);
		add(v, u);
	}
	for (int i=1;i<=n;i++) a[i]=read(), num[i]=i, fa[i]=i, fa_dir[i]=i, dep[i]=1;
	sort(num+1, num+1+n, cmp);
	for (int i=1;i<=n;i++){
		int u=num[i];
		for (int j=nex[u];j;j=nex[j]){
			int v=nu[j];
			// cout<<i<<' '<<v<<endl;
			v = father(v);
			if (a[v]<a[u]){
				fa[v]=u;
				fa_dir[v]=u;
			}
		}
		// cout<<i<<' '<<u<<' '<<f[u]<<endl;
	}
	for (int i=n;i;i--)
		dep[num[i]]=dep[fa_dir[num[i]]]+(fa_dir[num[i]]!=num[i]);
	for (int i=1;i<=n;i++) printf("%d\n", dep[i]);
	// for (int i=1;i<=n;i++)
	// 	cout<<fa_dir[i]<<' ';cout<<endl;
}
int main(){
	for (int _=read();_;_--) solve();
    return 0;
}
