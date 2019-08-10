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
#define N 20000005
#define mo 998244353
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int inv[N], f[N], pr[N], b[N];
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
int main(){
	cin>>d>>L>>m;
	pr[0]=1;
	n=2*L+1;
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
		l[i].t=read(), l[i].x=read();
	}
	sort(l+1,l+1+m,cmp);
	int ans=f[L];
	for (int i=1;i<=m;i++){
		int sum=0;
		int dans=f[l[i].x];
		for (int j=1;j<i;j++){
			int dt=l[i].t-l[j].t;
			int dx=l[i].x-l[j].x;
			if (1LL*dt*d>dx) continue;
			dx-=1LL*dt*d;
			add(b[i],1LL*C(dt-1,dx+dt-1)*b[j]);
		}
		add(ans,1LL*(b[i]-1)*dans%mo);
		b[i]=((-b[i]+1)%mo+mo)%mo;
	}
	cout<<ans<<endl;
    return 0;
}
