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
#define N 200005
#define mo 1000000007
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ll;
//typedef long long ll;
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
ll g, s2, s22, s3, s4;
ll n, m;
ll s[N], fa[N];
int father(int x) {return fa[x]==x?x:fa[x]=father(fa[x]);}
ll Cn2(ll x) {return x*(x-1)/2;}
ll Cn3(ll x) {return x*(x-1)/2*(x-2)/3;}
ll Cn4(ll x) {return x*(x-1)/2*(x-2)/3*(x-3)/4;}
ll sqr(ll x) {return x*x;}
int main(){
	n=read();m=read();
	for (int i=1;i<=n;i++) fa[i]=i, s[i]=1;
	ll cn4=n*(n-1)/2*(n-2)/3*(n-3)/4;
	ll ans=cn4;
//	cout<<cn4*2<<endl;
	printf("%llu\n", ans);
	for (int i=1;i<=m;i++){
		int u=read(), v=read();
		if (father(u)==father(v)) {
			printf("%llu\n", ans);
			continue;
		}
		
		g+=Cn2(s[fa[v]]+s[fa[u]])*Cn2(n-s[fa[v]]-s[fa[u]])
			-Cn2(s[fa[v]])*Cn2(n-s[fa[v]])
			-Cn2(s[fa[u]])*Cn2(n-s[fa[u]]);
			
		s2+=Cn2(s[fa[v]]+s[fa[u]])
			-Cn2(s[fa[v]])
			-Cn2(s[fa[u]]);
			
		s22+=sqr(Cn2(s[fa[v]]+s[fa[u]]))
			-sqr(Cn2(s[fa[v]]))
			-sqr(Cn2(s[fa[u]]));
			
		s3+=Cn3(s[fa[v]]+s[fa[u]])*(n-s[fa[v]]-s[fa[u]])
			-Cn3(s[fa[v]])*(n-s[fa[v]])
			-Cn3(s[fa[u]])*(n-s[fa[u]]);
		
		s4+=Cn4(s[fa[v]]+s[fa[u]])
			-Cn4(s[fa[v]])
			-Cn4(s[fa[u]]);
			
		ans=cn4+(s2*s2-s22)/2-g-s3-s4;
		printf("%llu\n", ans);
		
		s[fa[v]]+=s[fa[u]];
		fa[fa[u]]=fa[v];
	}
    return 0;
}
