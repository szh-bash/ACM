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
#define N 100005
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
vector <int> q[N];
int fa[N];
int n;
int f[N];
int father(int x){ return fa[x]==x?x:fa[x]=father(fa[x]);}
int a[N];
ll solve(){
	n=read();
	for (int i=1;i<N;i++) fa[i]=i, f[i]=0;
	for (int i=1;i<=n;i++) a[i]=read(), f[a[i]]++;
	ll ans=0;
	for (int i=N-1;i;i--){
		int tmp=0;
		for (int j=1;j*i<N;j++)
			if (f[i*j]){
				if (!tmp) tmp=father(i*j);
			 	if (father(i*j)!=father(tmp))
					fa[fa[i*j]]=fa[tmp],
					ans+=i;
			}
	}
	for (int i=1;i<N;i++) ans+=1ll*(f[i]?f[i]-1:0)*i;
	return ans;
}
vector <int> di[N];
int main(){
	freopen("dream.in","r",stdin);
	for (int _=read(), o=1;_;_--, o++)
		printf("Case %d: %I64d\n", o, solve());
    return 0;
}
