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
#define mo 1000000007
int power(ll a, int b){
	ll c=1;
	while (b){
		if (b&1) c=c*a%mo;
		a=a*a%mo;
		b>>=1;
	}
	return c;
}
#define N 1000005
int f[N], cnt;
//vector<int> g[N];
int nex[N*25], nu[N*25];
void add(int u, int v){
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;
}
int main(){
	cnt=N;
	for (int i=2;i<N;i++)
		for (int j=2;j*i<N;j++)
			add(j*i,i);
//			g[j*i].push_back(i);
	for (int i=2;i<N;i++){
//		int m=g[i].size();
		f[i]=1;
//		for (int j=0;j<m;j++)
//			f[i]=max(f[i],f[g[i][j]]+1);
		for (int j=nex[i];j;j=nex[j])
			f[i]=max(f[i],f[nu[j]]+1);
	}
	for (int _=read();_;_--){
		int n=read(), c=read();
		printf("%lld\n", power(c,f[n]));
	}
    return 0;
}
