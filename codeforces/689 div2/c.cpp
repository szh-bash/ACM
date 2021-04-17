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
#define N 100005
int n, k, a[N], flag[N];
double p[N];
void solve(){
	n=read();k=read();
	double ans = 1;
	for (int i=1;i<=n;i++) a[i]=read(), flag[i]=p[i]=0;
	int i=n, st=0;
	for (;i;i--){
		flag[i]=1;
		if (a[i]!=i) break;
	}
	if (!i) st=1;
	for (int i=1;i<=k;i++){
		int x;
		double px;
		scanf("%d%lf", &x, &px);
		if (flag[x]){
			ans=ans*(1-px);
			if (ans<1e-6) ans=0;
		}
	}
	if (st) cout<<1<<endl;
	else printf("%.6lf\n", 1-ans);

}
int main(){
	for (int _=read();_;_--) solve();
	return 0;
}
