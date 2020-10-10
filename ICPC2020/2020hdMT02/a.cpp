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
#define num(x) (x>='0' && x<='9')
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
ll readll(){
    ll p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
#define N 100005
#define M 200005
int n, m, b[N], fa[N], flag[N];
struct node{
	int y, x;
}l[M];
bool cmp(node aa, node bb){return b[aa.x]>b[bb.x];}
int father(int x){return fa[x]==x?fa[x]:fa[x]=father(fa[x]);}
void solve(){
	n=read();m=read();
	for (int i=1;i<=n;i++) b[i]=read(), fa[i]=i, flag[i]=0;
	for (int i=1;i<=m;i++){
		int u=read(), v=read();
		if (b[u]>b[v]) swap(u,v);
		l[i].x=u,
		l[i].y=v;
	}
	sort(l+1,l+1+m,cmp);
	ll ans=0;
	for (int i=1;i<=m;i++)
		if (father(l[i].x)!=father(l[i].y)){
			ans+=b[fa[l[i].y]]-b[fa[l[i].x]];
			fa[fa[l[i].y]]=fa[l[i].x];
		}
	for (int i=1;i<=n;i++)
		if (!flag[father(i)])
			flag[fa[i]]=1,
			ans+=b[fa[i]];
	cout<<ans<<endl;
}
int main(){
	for (int _=read();_;_--) solve();
    return 0;
}
