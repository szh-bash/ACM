#include <map>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define mo 998244353
#define N 500005
typedef long long ll;
using namespace std;
int ma, n, trans[N], ct, a[N], LSH[N], f[N*4], ff[N], fq[N];
ll g[N*4], gg[N], gq[N];
map<int, int> mp;
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') (ch=='-'?q=-1:0), ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
void upd(int t, int l, int r, int x, int i){
	if (l==r){
		if (fq[i]>f[t])
			f[t]=fq[i],
			g[t]=gq[i];
		else g[t]=(g[t]+gq[i])%mo;
		return;
	}
	int mid=l+r>>1;
	if (x>mid) upd((t<<1)+1,mid+1,r,x,i);
	else upd(t<<1,l,mid,x,i);
	if (f[t<<1]>f[(t<<1)+1]) f[t]=f[t<<1], g[t]=g[t<<1];
	else if (f[t<<1]<f[(t<<1)+1]) f[t]=f[(t<<1)+1], g[t]=g[(t<<1)+1];
	else f[t]=f[t<<1], g[t]=(g[t<<1]+g[(t<<1)+1])%mo;
}
int queryf(int t, int l, int r, int ri){
	if (r<=ri) return f[t];
	int mid=l+r>>1;
	int p=queryf(t<<1,l,mid,ri);
	if (ri>mid) p=max(p,queryf((t<<1)+1,mid+1,r,ri));
	return p;
}
int queryg(int t, int l, int r, int ri, int x){
	if (f[t]<x) return 0;
	if (r<=ri) return g[t];
	int mid=l+r>>1;
	ll p=queryg(t<<1,l,mid,ri, x);
	if (ri>mid) p=(p+queryg((t<<1)+1,mid+1,r,ri,x))%mo;
	return p;
}
void solve(){	
	ma=0;
	for (int i=1;i<=n;i++){
		int x=a[i];
		fq[i]=((x-1)?queryf(1,1,ct,x-1):0)+1;
		gq[i]=max(((x-1)?queryg(1,1,ct,x-1,fq[i]-1):0),1);
		//cout<<i<<' '<<x<<' '<<fq[i]<<' '<<gq[i]<<endl;
		upd(1,1,ct,x,i);
		ma=max(ma,fq[i]);
	}
}
ll power(ll a, int b){
	ll c=1;
	while (b){
		if (b&1) c=c*a%mo;
		a=a*a%mo;
		b>>=1;
	}
	return c;
}
void reset(int t, int l, int r){
	if (l==r){
		f[t]=g[t]=0;
		return;
	}
	reset(t<<1,l,l+r>>1);
	reset((t<<1)+1,(l+r>>1)+1,r);
	f[t]=g[t]=0;
}
int main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(), LSH[i]=a[i];
	sort(LSH+1,LSH+1+n);
	LSH[0]=1000000001;
	for (int i=1;i<=n;i++) if (LSH[i]!=LSH[i-1]) trans[mp[LSH[i]]=++ct]=LSH[i];
	for (int i=1;i<=n;i++) a[i]=mp[a[i]];
	solve();
	//cout<<ma<<endl;
	for (int i=1;i<=n/2;i++) swap(a[i],a[n-i+1]);
	for (int i=1;i<=n;i++)
		a[i]=ct-a[i]+1,
		ff[i]=fq[i],
		gg[i]=gq[i];
	reset(1,1,ct);
	solve();
	for (int i=1;i<=n/2;i++)
		swap(fq[i],fq[n-i+1]),
		swap(gq[i],gq[n-i+1]);
	ll tot=0;
	for (int i=1;i<=n;i++)
		if (fq[i]==ma) tot=(tot+gq[i])%mo;
	tot=power(tot,mo-2);
	for (int i=1;i<=n;i++)
		if (ff[i]+fq[i]-1==ma){
			long long m=gq[i]*gg[i]%mo;
			m=m*tot%mo;
			printf("%d% ", (int)m);
		}
		else printf("0% ");
	return 0;
}
