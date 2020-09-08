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
#define N 20
int n, a[N], b[N], c[N], flag[N], ans;
int sqr(int x){return x*x;}
int dup(int x1, int y1, int x2, int y2){
	return (sqr(x1*x2+y1*y2)==sqr(x1+y1)*sqr(x2+y2)) && 
		((x1*x2+y1*y2)>0);
}
bool check(){
	int x=0, y=0;
	for (int i=1;i<=n+1;i++)
		if (x==a[c[i]] || y==b[c[i]]) 
			x=a[c[i]],
			y=b[c[i]];
		else return 0;
	for (int i=1;i<=n;i++)
		if (dup(a[c[i]]-a[c[i-1]], b[c[i]]-b[c[i-1]],
				a[c[i+1]]-a[c[i]], b[c[i+1]]-b[c[i]]))
			return 0;
	return 1;
}
void dfs(int t){
	if (t>n){
		if (check()) ans++;
		return;
	}
	for (int i=1;i<=n;i++)
		if (!flag[i]){
			flag[i]=1;
			c[t]=i;
			dfs(t+1);
			flag[i]=0;
		}
}
int main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(), b[i]=read();
	dfs(1);
	cout<<ans<<endl;
    return 0;
}
