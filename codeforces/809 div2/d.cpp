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
int n, k, a[N];
void solve(){
	n=read();k=read();
	for (int i=1;i<=n;i++) a[i]=read();
	int ans=a[n]/k-a[1]/k;
	for (int v=1;v<=a[1];v++){
		int mi=a[n];
		int ma=v;
		for (int i=1;i<=n;i++){
			int u=a[i]/min(k, a[i]/v);
			mi=min(mi,u);
			ma=max(ma,u);
		}
		ans=min(ans,ma-mi);
	}
	cout<<ans<<endl;
}
int main(){
	for (int _=read();_;_--) solve();
	return 0;
}
