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
int n, k, a[N], cloest[N];
void solve(){
	n=read();k=read();
	for (int i=1;i<=n;i++) a[i]=read();
	cloest[0]=a[1];
	for (int i=1;i<=n;i++)
		for (int j=a[i-1]+1;j<=a[i];j++)
			cloest[j] = a[i];
	int ans=a[n];
	for (int v=1;v<=a[n];v++){
		if ((v+1)*k <= a[n]) continue;
		int mn = (a[1] <= v)?a[1]:(a[n]+1);
		for (int j=1;(j-1)*(v+1)<=a[n];j++){
			int nxt = cloest[(j-1)*(v+1)];
			if (nxt<j*(v+1)) mn = min(mn, nxt/j);
		}
		if (v>=mn) ans=min(ans, v-mn);

	}
	cout<<ans<<endl;
}
int main(){
	for (int _=read();_;_--) solve();
	return 0;
}
