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
#define inf (1000000005ll)
#define mp make_pair
#define pli pair<ll,int>
#define pii pair<int,int>
#define ll long long 
#define N 200000
using namespace std;
int n, k, g[N], a[N];
ll f[N], ans;
int read(){
	int x=0,p=1;char ch=getchar();
	while(ch<'0'||ch>'9'){ch=='-'?p=-1:0;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*p;
}
bool check(int x){
	for (int i=2;i<=n;i++){
		ll tmp=f[i-2]+a[i]-a[i-1]-x;
		bool go=tmp==f[i-1]?g[i-2]+1>g[i-1]:tmp<f[i-1];
		if (go)
			f[i]=tmp,
			g[i]=g[i-2]+1;
		else f[i]=f[i-1], g[i]=g[i-1];
	}
//	for (int i=1;i<=n;i++) cout<<x<<' '<<i<<' '<<f[i]<<' '<<g[i]<<endl; 
	return g[n]<k;
}
int main(){
	n=read();k=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int le=-1,ri=inf+1;le<ri-1;){
		int mid=le+ri>>1;
		if (check(mid)) le=mid;else ri=mid, ans=f[n]+1ll*mid*k;
	}
	cout<<ans<<endl;
	return 0;
}
