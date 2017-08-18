#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 200000
#define mo 998244353
typedef long long LL;
using namespace std;
int n, ma, a[N], p[N], rank[N], c[N];
LL w[N];
int read(){
	int p=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
void __init(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(), ma=max(ma,a[i]);
}
void solve1(){
	LL ans=0;
	for (int k=1;k<=ma;k<<=1){
		LL b=0, c=0, tot=0;
		for (int i=1;i<=n;i++){
			bool flag=(a[i]&k)>0;
			if (flag)
				swap(b,c), b++;
			else
				c++;
			tot+=b;
		}
		ans+=tot*k%mo;
	}
	cout<<ans%mo<<' ';
}
bool cmp(int a, int b){return w[a]<w[b];}
int query(LL x){
	if (x<w[p[1]]) return 0;
	if (x>w[p[n]]) return n;
	int le=0, ri=n+1;
	while (le<ri-1){
		int mid=le+ri>>1;
		if (w[p[mid]]<=x) le=mid;else ri=mid;
	}
	return le;
}
bool calc(int x){
	bool y=0;
	for (int i=x;i;i-=i&(-i)) y^=c[i];
	return y;
}
void solve2(){
	LL ans=0, sum=0;
	for (int i=1;i<=n;i++) sum+=a[i];
	for (LL k=1;k<=sum;k<<=1){
		LL kk=k<<1;
		bool flag=0;
		for (int i=1;i<=n;i++){
			w[i]=w[i-1]+a[i];
			if (w[i]>=kk) w[i]%=kk;
			p[i]=i;
		}
		sort(p+1,p+1+n,cmp);
		for (int i=1;i<=n;i++) rank[p[i]]=i, c[i]=0;
		for (int i=1;i<=n;i++){
			for (int j=rank[i];j<=n;j+=j&(-j)) c[j]^=1;
			flag^=(w[i]>=k)^calc(query(w[i]-k))^calc(query(w[i]))^calc(query(w[i]+k));
		}
		ans^=k*flag;
	}
	cout<<ans<<endl;
}
int main(){
	__init();
	solve1();
	solve2();
	return 0;
}
