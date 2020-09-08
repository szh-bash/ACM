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
#define N 1000005
int n;
ll r1, r2, r3, d, a[N], f[N][4][4];
const ll inf = 1e18;
void upd(int i, ll x, int k){
	if (k==0) f[i+1][0][3]=min(f[i+1][0][3],x+a[i+1]*r1+r3);
	if (k==1) f[i+1][1][3]=min(f[i+1][1][3],x+min(a[i+1]*r1+r1,r2));
	if (k==2) f[i+1][2][3]=min(f[i+1][2][3],x+a[i+1]*r1);
	if (k==3) f[i+1][3][3]=min(f[i+1][3][3],x+0);
}
void solve(){
	n=read();
	r1=read();r2=read();r3=read();
	d=read(); 
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=0;i<n;i++)
		for (int j=0;j<4;j++)
			for (int k=0;k<4;k++)
				f[i][j][k]=inf;
	f[0][0][3]=-d;
//	f[1][0][3]=min(a[1]*r1+min(r3,r1*2+d*2),r2+d*2+r1);
//	f[1][1][3]=min(r2+d*2,a[1]*r1+r1+d*2);
//	f[1][2][3]=a[1]*r1;
//	f[1][3][3]=0;
	for (int i=0;i<n-1;i++)
		for (int k=0;k<4;k++){
			//j==0
			f[i+1][k][3]=min(f[i+1][k][3],f[i][0][k]+d);
			//j==1
			f[i+1][k][3]=min(f[i+1][k][3],f[i][1][k]+r1+d);
			//j==2
			f[i+1][k][3]=min(f[i+1][k][3],f[i][2][k]+r3+d);
			upd(i,f[i][2][k]+r1*2+d*3,k);
			//j==3
			f[i+1][k][3]=min(f[i+1][k][3],f[i][3][k]+a[i]*r1+r3+d);
			upd(i,f[i][3][k]+r2+r1+d*3,k);
			upd(i,f[i][3][k]+(a[i]+2)*r1+d*2,k);
		}
	for (int i=0;i<4;i++) cout<<f[n-1][0][i]<<endl;
	ll ans=inf;
	ans=min(ans,f[n-1][0][0]);
	ans=min(ans,f[n-1][0][1]+r1);
	ans=min(ans,f[n-1][0][2]+min(r3,r1*2+d*2));
	ans=min(ans,f[n-1][0][3]+min(a[n]*r1+min(r3,r1*2+d*2),r2+d*2+r1));
	cout<<ans<<endl;
}
int main(){
	solve();
	return 0;
}
