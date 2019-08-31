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
#define M 4000
#define N 20000005
#define mo 998244353
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int inv[N], f[N], pr[N], b[N], g[M][M];
int d, L, m, n;
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
void add(int &a, int b){
	a+=b;
	if (a>=mo) a-=mo;
}
struct st{
	int t, x;
}l[N];
bool cmp(st a, st b){
	return a.t<b.t;
}
int C(int m, int n){
	return 1LL*pr[n]*inv[n-m]%mo*inv[m]%mo;
}
int cal(int dt, int dx){
	if (1LL*dt*d>dx) return 0;
	dx-=dt*d;
	return C(dt-1,dx+dt-1);
}
int main(){
	cin>>L>>d>>m;
	
	n=2*L+1;
	pr[0]=1;
	for (int i=1;i<=n;i++) pr[i]=1LL*pr[i-1]*i%mo;
	inv[n]=power(pr[n],mo-2);
	for (int i=n-1;i;i--) inv[i]=1LL*inv[i+1]*(i+1)%mo;
	inv[0]=1;
	f[0]=1;
	int sum=0;
	for (int i=d;i<=L;i++)
		add(sum,f[i-d]),
		add(f[i],sum);
		
	for (int i=1;i<=m;i++){
		l[i].t=read(), l[i].x=read()+1;
	}
	sort(l+1,l+1+m,cmp);
	
	int ans=f[L];
	g[0][0]=l[0].x=1;
	for (int i=1;i<=m;i++){
		for (int od=0;od<2;od++)
			for (int j=0;j<i;j++)
				add(g[i][od],1LL*cal(l[i].t-l[j].t,l[i].x-l[j].x)*g[j][od^1]%mo);
		add(ans,(g[i][0]+1ll*(mo-1)*g[i][1])%mo*f[L-l[i].x+1]%mo);
	}
	cout<<ans<<endl;
    return 0;
}
