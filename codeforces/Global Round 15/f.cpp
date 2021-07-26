#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;
#define N 200005
#define mo 998244353
int n, x[N], y[N], a[N], c[N];
int ans;
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') 
		ch=='-'?q=-1:0,
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
int add(int a, int b){
	if (a+b>=mo) return a+b-mo;
	return a+b;
}
int mul(int a, int b){
	if (1ll*a*b>=mo) return 1ll*a*b%mo;
	return a*b;
}
int calc(ll times){
	ll res=times/2-0, tmp=0, ret=0;
	while (res){
		tmp=ret+res;
		times+=res;
		ret+=res;
		res=times/2-tmp;
	}
	return ret%mo;
}
int getn(int y){
	int le=0, ri=n;
	while (le<ri-1){
		int mid=(le+ri)>>1;
		if (x[mid]<y) le=mid;
		else ri=mid;
	}
	return ri;
}
int main(){
	n=read();
	for (int i=1;i<=n;i++) x[i]=read(), y[i]=read(), a[i]=read();
	ans=(x[n]+1)%mo;
	for (int i=n;i;i--){
		int v=getn(y[i]);
		int sum=1;
		for (int j=i;j;j-=j&(-j)) sum=add(sum,c[j]);
		int ret=calc(add(sum,a[i]));
		ans=add(ans,mul(ret,(x[i]-y[i])%mo));
		for (int j=v;j<=n;j+=j&(-j)) c[j]=add(c[j],ret);
	}
	cout<<ans<<endl;
	return 0;
}
