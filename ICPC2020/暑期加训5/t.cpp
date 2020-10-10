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
#define N 300000
int n, d[N], num[N];
ll l[N];
bool cmp (int x, int y){
	if (l[x]+d[x]<l[y]+d[y]) return 1;
	if (l[x]+d[x]>l[y]+d[y]) return 0;
	return d[x]<d[y];
}
void solve(){
	n=read();
	for (int i=1;i<=n;i++) l[i]=readll(), d[i]=read(), num[i]=i;
	sort(num+1,num+1+n,cmp);
	ll L=0;
	int ans=0;
	for (int i=1;i<=n;i++)
		if (L<=l[num[i]]){
			ans++;
			L+=d[num[i]];
		}
	cout<<ans<<endl;
}
int main(){
	solve();
    return 0;
}
