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
#define mo 1000000007
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
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
#define N 2005
int n, st, flag[N], a[N], e[N][N], dist[N];
ll ans;
int main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) e[i][j]=a[i]^a[j];
	st = 1;
	flag[st]=1;
	for (int i=1;i<n;i++){
		int ma=0, p;
		for (int j=1;j<=n;j++)
			if (!flag[j]){
				dist[j]=max(dist[j], a[st]^a[j]);
				if (dist[j]>ma)
					ma = dist[j],
					p = j;
			}
		flag[st=p]=1;
		ans += ma;
	}
	cout<<ans<<endl;
    return 0;
}
