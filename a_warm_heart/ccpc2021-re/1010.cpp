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
struct node{
	int le, ri;
}ans[N];
bool cmp(node a, node b){
	if (a.le < b.le) return 1;
	if (a.le > b.le) return 0;
	return a.ri<b.ri;
}
void solve(){
	n=read(), m=read();
	for (int i=1;i<=n;i++) ga[i]=gb[i]=da[i]=db[i]=0;
	for (int i=1;i<=m;i++){
		int u=read(), v=read()+n;
		da[u]++;
		db[v]++;
		ga[u]=v;
		gb[v]=u;
	}
	printf("%d\n", 2*n-m);
	int cnt=0;
	for (int i=m+1;i<=n;i++){
		for (int le=1, ri=1;le<=n && ri<=n;le++, ri++){
			while (le<=n && ga[le]) le++;
			while (ri<=n && gb[ri]) ri++;
			ga[le]=ri;
			gb[ri]=le;
			++cnt;
			ans[cnt].le=le;
			ans[cnt].ri=ri;
		}
	}

	sort(ans+1,ans+1+cnt,cmp);
	for (int i=1;i<=cnt;i++) printf("%d %d\n", ans[i].le, ans[i].ri);
}
int main(){
	for (int _=read();_;_--) solve();
    return 0;
}
