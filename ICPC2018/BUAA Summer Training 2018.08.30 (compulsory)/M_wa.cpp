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
#define M 200000
#define N 1500000
#define mo 1000000007
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int n, a[N], wv[N], sa[N], rk[N], y[N], r[N];
int fr[M], k[M], f[N+M*3];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
void upd(int t, int l, int r, int x, int y){
	if (l==r) {f[t]=y;return; }
	int mid=l+r>>1;
	if (x<=mid) upd(t<<1,l,mid,x,y);
	else upd((t<<1)+1,mid+1,r,x,y);
	f[t]=f[t<<1] | f[(t<<1)+1];
}
int query(int t, int l, int r){
	if (l==r) return l;
	int mid=l+r>>1;
	if (f[t<<1]) return query(t<<1,l,mid);
	return query((t<<1)+1,mid+1,r);
}
void reset(int t, int l, int r){
	if (l==r) {f[t]=0;return;}
	reset(t<<1,l,l+r>>1);
	reset((t<<1)+1,((l+r)>>1)+1,r);
	f[t]=0;
}
int main(){
	freopen("M.in","r",stdin);
	while (~scanf("%d", &n)){
		int ls=0, sum=0;
		a[ls++]=301;
		for (int i=1;i<=n;i++){
			fr[i]=ls;
			k[i]=read();
			for (int j=1;j<=k[i];j++) a[ls++]=read();
			a[ls++]=301;
			sum+=k[i];
		}
		for (int i=0;(i<<1)<ls;i++)
			swap(a[i],a[ls-i-1]);
		for (int i=1;i<=n;i++)
			fr[i]=ls-1-fr[i];
		int m=max(ls,302);
		for (int i=0;i<2*ls;i++) rk[i]=-1;
		for (int i=0;i<m;i++) wv[i]=0; 
		for (int i=0;i<ls;i++) wv[a[i]]++;
		for (int i=1;i<m;i++) wv[i]+=wv[i-1];
		for (int i=0;i<ls;i++) sa[--wv[a[i]]]=i;
		rk[sa[0]]=0;
		for (int i=1;i<ls;i++) rk[sa[i]]=rk[sa[i-1]]+(a[sa[i]]!=a[sa[i-1]]);
		for (int j=1;j<ls;j*=2){
			int p=0;
			for (int i=ls-j;i<ls;i++) y[++p]=i;
			for (int i=0;i<ls;i++)
				if (sa[i]>=j) y[++p]=sa[i]-j;
			for (int i=0;i<m;i++)  wv[i]=0;
			for (int i=0;i<ls;i++) wv[rk[i]]++;
			for (int i=1;i<m;i++) wv[i]+=wv[i-1];
			for (int i=ls;i;i--)   sa[--wv[rk[y[i]]]]=y[i];
			r[sa[0]]=0;
			for (int i=1;i<ls;i++)
				r[sa[i]]=r[sa[i-1]]+(rk[sa[i-1]]!=rk[sa[i]] || rk[j+sa[i-1]]!=rk[j+sa[i]]);
			for (int i=0;i<ls;i++)
				rk[i]=r[i];
		}
		reset(1,0,ls);
		for (int i=1;i<=n;i++)
			upd(1,0,ls,rk[fr[i]-k[i]+1],1);
		ll ans=0;
		while (sum--){
			int v=query(1,0,ls);
			upd(1,0,ls,v,0);
			upd(1,0,ls,rk[sa[v]+1],1);
			ans=(ans*365+a[sa[v]])%mo;
			//cout<<v<<' '<<sa[v]<<' '<<a[sa[v]]<<endl;
		}
		//cout<<ans<<endl;
		ans=ans*365%mo;
		printf("%lld\n", ans);
		//cout<<ans*365%mo<<endl;
	}
    return 0;
}
