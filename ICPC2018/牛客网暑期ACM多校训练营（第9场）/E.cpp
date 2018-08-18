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
#define N 2000
#define mo 1000000007
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int n, m, divv, f[N][N], g[N], p[N], p0[N], p1[N], q[N][N];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
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
int upd(int a, int b){ return a+b>=mo?a+b-mo:a+b;}
int sub(int a, int b){ return a-b<0?a-b+mo:a-b;}
int main(){
	divv=power(100,mo-2);
	n=read();m=read();
	for (int i=1;i<=n;i++){
		p[i]=read(),
		p0[i]=(ll)p[i]*divv%mo,
		p1[i]=(ll)(100-p[i])*divv%mo;
		//cout<<p[i]<<' '<<p0[i]<<' '<<p1[i]<<endl;
	}
	for (int i=1;i<=n;i++){
		g[i]=power(i,m);
		//cout<<g[i]<<endl;
	}
	q[1][0]=1;
	for (int i=1;i<=n;i++){
		for (int j=0;j<i;j++){
			//cout<<f[i][j]<<' ';
			f[i+1][0]=upd(f[i+1][0],(ll)f[i][j]*p1[i]%mo),
			q[i+1][0]=upd(q[i+1][0],(ll)q[i][j]*p1[i]%mo),
			f[i+1][j+1]=upd(f[i+1][j+1],(ll)upd(sub(f[i][j],(ll)g[j]*q[i][j]%mo),(ll)g[j+1]*q[i][j]%mo)*p0[i]%mo),
			q[i+1][j+1]=upd(q[i+1][j+1],(ll)q[i][j]*p0[i]%mo);
		}
		//cout<<endl;
	}
	int ans=0;
	for (int i=0;i<=n;i++){
		ans=upd(ans,f[n+1][i]);
		//cout<<i<<' '<<f[n+1][i]<<endl;
	}
	cout<<ans<<endl;
    return 0;
}
/*
3 4
50 50 50

*/
