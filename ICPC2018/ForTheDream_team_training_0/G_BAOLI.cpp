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
#define N 100010
#define mo 998244353
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int n, ans, flag[100], c[100];
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
void dfs(int u){
	if (u>n){
		if (c[n]%n+1!=c[1]) ans++;
		return;
	}
	for (int i=1;i<=n;i++)
		if (!flag[i] && (u==1 || c[u-1]%n+1!=i)){
			flag[i]=1;
			c[u]=i;
			dfs(u+1);
			flag[i]=0;
		}
}
int main(){
	for (int _=read();_;_--){
		n=read();
		ans=0;
		dfs(1);
		cout<<ans/n<<endl;
	}
    return 0;
}
