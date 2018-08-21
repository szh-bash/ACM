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
#define N 200000
#define mo 998244353
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
using namespace std::tr1;
int a[N], n, m;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
int upd(int a, int b){ return a+b>=mo?a+b-mo:a+b;}
int pwd(ll a, ll b){
	ll c=1;
	while (b){
		if (b&1) c=c*a%mo;
		a=a*a%mo;
		b>>=1;
	}
	return c;
}
int main(){
	for (int _=read();_;_--){
		n=read();m=read();
		for (int i=1;i<=n;i++) a[i]=upd(a[i-1],read());
		int pw=pwd(2,(ll)n*m);
		for (int i=1;i<=m;i++){
			int t=read(), l=read(), r=read();
			if (t==2){
				int ans=(ll)(((ll)a[r]-a[l-1])%mo+mo)%mo*pw%mo;
				printf("%d\n", ans);
			}
		}
	}
    return 0;
}
