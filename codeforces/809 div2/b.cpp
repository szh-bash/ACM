#include <map>
#include <set> 
#include <ctime>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define mo 1000000007
typedef long long ll;
using namespace std;
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=='-'?q=-1:0, ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
ll readll(){
	ll p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=='-'?q=-1:0, ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
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
#define N 200005
int n, f[N][2], g[N];
void solve(){
	n=read();
	for (int i=1;i<=n;i++) f[i][0]=f[i][1]=0;
	for (int i=1;i<=n;i++){
		int x=read();
		f[x][i&1] = f[x][(i&1)^1]+1;
	}
	for (int i=1;i<=n;i++) printf("%d%s", max(f[i][0], f[i][1]), i==n?"\n":" ");
}
int main(){
	for (int _=read();_;_--) solve();
	return 0;
}
