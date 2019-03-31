#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 200000
#define M (3*N)
#define mo 1000000007
typedef long long ll;
using namespace std;
int ans;
int n, cnt, k, f[N], nex[M], nu[M], col[M];
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9')
		ch=='-'?q=-1:0,
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
void add(int u, int v, int co){
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;col[cnt]=co;
}
int power(ll n, int k){
	ll p=1;
	while (k){
		if (k&1) p=p*n%mo;
		n=n*n%mo;
		k>>=1;
	}
	return p;
}
void subi(int &a, int b){
	a-=b;
	if (a<0) a+=mo;
}
void dfs(int u, int fa, int co){
	f[u]=1;
	for (int j=nex[u];j;j=nex[j]){
		int v=nu[j];
		if (v==fa) continue;
		dfs(v,u,col[j]);
		if (!col[j]) f[u]+=f[v];
	}
	if (co) subi(ans,power(f[u],k));
}
int main(){
	cnt=n=read();k=read();
	for(int i=1;i<n;i++){
		int u=read(), v=read(), w=read();
		add(u,v,w);
		add(v,u,w);
	}
	ans=power(n,k);
	dfs(1,0,1);
	cout<<ans<<endl;
	return 0;
}
