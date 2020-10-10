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
ll readll(){
    ll p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
#define N 20
#define D 10
ll cnm[N][N], f[N];
int dex[N], num[D], w[D];
#define C(x,y) cnm[x][y]
inline int getn(ll x){
	int res=0;
	while (x) dex[++res]=x%10, x/=10;
	return res;
}
ll getf(int m){
	f[0]=1;
	for (int p=m;p;p--) f[p]=0;
	for (int j=0;j<D;j++)
		for (int p=m;p;p--)
			for (int k=1;k<=min(w[j],p);k++)
				f[p]+=f[p-k]*C(p,p-k);
	return f[m];
}
ll getans(int n, int d){
	ll res=0;
	if (!d){
		for (int i=1;i<=n;i++){
			int m=n-i;
			for (int j=0;j<D;j++) w[j]=(i-1)*(j!=d);
			res+=C(n-1,i)*getf(m);
		}
	}
	else{
		for (int i=1;i<=n;i++)
			for (int q=0;q<i && q+i<=n;q++){
				int m=n-i-q;
				for (int j=0;j<D;j++) w[j]=(i-1)*(j!=d)*(j>0);
				res+=C(n-1,q)*C(n-q,i)*getf(m);
			}
	}
	return res;
}
ll solve(ll x, int d){
	int n=getn(x);
	ll ans=0;
	for (int i=1;i<n;i++) ans+=getans(i,d);
	for (int i=0;i<D;i++) num[i]=0;
	for (int i=n;i;i--){
		for (int j=0;j<dex[i];j++){
			if (!j && i==n) continue;
			num[j]++;
			int ma=0;
			for (int k=0;k<D;k++)
				if (k!=d) ma=max(ma, num[k]);
			int mi=max(0,ma+1-num[d]);
			for (int k=mi;k<=i-1;k++){
				int m=i-1-k;
				for (int j=0;j<D;j++)
					w[j]=(num[d]+k-1-num[j])*(j!=d);
				ans+=C(i-1,k)*getf(m);
			}
			num[j]--;
		}
		num[dex[i]]++;
	}
	int ma=0;
	for (int k=0;k<D;k++)
		if (k!=d) ma=max(ma, num[k]);
	if (ma<num[d]) ans++;
	return ans;
}
int main(){
	cnm[0][0]=1;
	for (int i=1;i<N;i++){
		cnm[i][0]=1;
		for (int j=1;j<=i;j++)
			cnm[i][j]=cnm[i-1][j]+cnm[i-1][j-1];
	}
	for (int _=read();_;_--){
		ll l=readll()-1, r=readll();
		int d=read();
		printf("%I64d\n", solve(r,d)-solve(l,d));
	}
    return 0;
}
