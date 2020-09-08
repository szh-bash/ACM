#include<bits/stdc++.h>
using namespace std;
const int maxn=1000009;
const long long inf=1e18;
int n,r1,r2,r3,d;
int a[maxn];
long long f[maxn];
int main(){
	cin>>n>>r1>>r2>>r3>>d;
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<=n;++i){
		f[i]=1LL*a[i]*r1+r3+f[i-1]+d;
		long long t=min(0LL+r1+r2,1LL*(a[i]+2)*r1);
		long long g=f[i-1]+t+3LL*d;
		if (i>=2) g=min(g,f[i-2]+2*t+4LL*d);
		f[i]=min(f[i],g);
	}
	cout<<f[n]-d<<endl;
	return 0;
}
