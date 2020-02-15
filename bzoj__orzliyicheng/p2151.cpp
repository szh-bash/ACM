#include<set>
#include<map>
#include<ctime>
#include<queue>
#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define inf (2006)
#define mp make_pair
#define pli pair<ll,int>
#define pii pair<int,int>
#define ll long long 
#define N 400000
using namespace std;
int read(){
	int x=0,p=1;char ch=getchar();
	while(ch<'0'||ch>'9'){ch=='-'?p=-1:0;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*p;
}
int n, m, a[N];
ll f[N][2];
int g[N][2];
ll ans;
bool check(int x){
	f[1][1]=a[1]-x;
	g[1][1]=1;
	for (int i=2;i<=n;i++){
		ll tmp0=f[i-2][0]+a[i]-x;
		ll tmp1=f[i-2][1]+(a[i]-x)*(i!=n);
		bool go0=f[i-1][0]==tmp0?g[i-1][0]>g[i-2][0]+1:f[i-1][0]>tmp0;
		bool go1=f[i-1][1]==tmp1?g[i-1][1]>g[i-2][1]+(i!=n):f[i-1][1]>tmp1;
		if (go0)
			f[i][0]=f[i-1][0], g[i][0]=g[i-1][0];
		else f[i][0]=tmp0, g[i][0]=g[i-2][0]+1;
		if (go1)
			f[i][1]=f[i-1][1], g[i][1]=g[i-1][1];
		else f[i][1]=tmp1, g[i][1]=g[i-2][1]+(i!=n);
	}
	int ct;
	if (f[n][0]==f[n][1]) ct=max(g[n][0],g[n][1]);
	else if (f[n][0]>f[n][1]) ct=g[n][0];
	else ct=g[n][1];
//	for (int i=0;i<=n;i++) cout<<x<<' '<<i<<' '<<a[i]<<' '<<f[i][0]<<' '<<f[i][1]<<endl;
	return ct<m;
}
int main(){
	n=read();m=read();
	for (int i=1;i<=n;i++) a[i]=read();
	if (m>n/2){
		puts("Error!");
		return 0;
	}
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	for (int le=-inf, ri=inf;le<ri-1;){
		int mid=le+ri>>1;
		if (check(mid)) ri=mid;else le=mid, ans=max(f[n][0],f[n][1])+1ll*mid*m;
//		cout<<le<<' '<<ri<<' '<<mid<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
