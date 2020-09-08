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
#define N 200005
#define M N*3
int n, m, cnt, nex[M], nu[M], flag[N];
void add(int u, int v){
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;
}
int sum;
void dfs(int u){
	sum++;
	flag[u]=1;
	for (int j=nex[u];j;j=nex[j]){
		int v=nu[j];
		if (!flag[v]) dfs(v);
	}
}
int main(){
	cnt=n=read();m=read();
	for (int i=1;i<=m;i++){
		int u=read(), v=read();
		add(u,v);
		add(v,u);
	}
	int ans=0;
	for (int i=1;i<=n;i++)
		if (!flag[i]) sum=0, dfs(i), ans=max(ans,sum);
	cout<<ans<<endl;
    return 0;
}
