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
#define N 1000000
typedef long long ll;
using namespace std;
int n;
ll a[N], b[N], k[N];
ll f[N], g[N], flag[N], ps[N], pre[N];
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') 
		ch=='-'?q=-1:0,
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
void build(int t, int l, int r){
	if (l==r) {
		f[t]=b[l];
		g[t]=1LL*b[l]*l;
		return;
	}
	int mid=l+r>>1;
	build(t<<1,l,mid);
	build((t<<1)+1,mid+1,r);
	f[t]=f[t<<1]+f[(t<<1)+1];
	g[t]=g[t<<1]+g[(t<<1)+1];
}
void pushdown(int t){
	if (flag[t]){
		flag[t<<1]=flag[(t<<1)+1]=1;
		f[t<<1]=f[(t<<1)+1]=0;
		g[t<<1]=g[(t<<1)+1]=0;
		flag[t]=0;
	}
}
void update(int t, int l, int r, int x, int y){
	if (l==r){
		f[t]+=y;
		g[t]+=1LL*y*l;
		return;
	}
	pushdown(t);
	int mid=l+r>>1;
	if (x<=mid) update(t<<1,l,mid,x,y);
	else update((t<<1)+1,mid+1,r,x,y);
	f[t]=f[t<<1]+f[(t<<1)+1];
	g[t]=g[t<<1]+g[(t<<1)+1];
}
void set(int t, int l, int r, int le, int ri, int y){
	if (le<=l && r<=ri){
		if (!y)
			f[t]=g[t]=0,
			flag[t]=1;
		else
			f[t]=y,
			g[t]=1LL*y*l;
		return ;
	}
	pushdown(t);
	int mid=l+r>>1;
	if (le<=mid) set(t<<1,l,mid,le,ri,y);
	if (ri>mid) set((t<<1)+1,mid+1,r,le,ri,y);
	f[t]=f[t<<1]+f[(t<<1)+1];
	g[t]=g[t<<1]+g[(t<<1)+1];
}
ll query(int t, int l, int r, int le, int ri){
	if (le<=l && r<=ri) return f[t];
	pushdown(t);
	int mid=l+r>>1;
	ll p=0;
	if (le<=mid) p+=query(t<<1,l,mid,le,ri);
	if (ri>mid) p+=query((t<<1)+1,mid+1,r,le,ri);
	return p;
}
ll queryf(int t, int l, int r, int x){
	if (!x) return 0;
	if (r<=x) return f[t];
	pushdown(t);
	int mid=l+r>>1;
	ll p=queryf(t<<1,l,mid,x);
	if (x>mid) p+=queryf((t<<1)+1,mid+1,r,x);
	return p;
}
ll queryg(int t, int l, int r, int x){
	if (!x) return 0;
	if (r<=x) return g[t];
	pushdown(t);
	int mid=l+r>>1;
	ll p=queryg(t<<1,l,mid,x);
	if (x>mid) p+=queryg((t<<1)+1,mid+1,r,x);
	return p;
}
ll calc(int x){
	if (!x) return 0;
	return 1LL*x*queryf(1,1,n-1,x-1)-queryg(1,1,n-1,x-1)+1LL*x*ps[x-1]-pre[x-1]+1LL*x*a[1];
}
int main(){
	char op[5];
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<n;i++) k[i]=read(), b[i]=a[i+1]-a[i]-k[i], pre[i]=pre[i-1]+1LL*k[i]*i, ps[i]=ps[i-1]+k[i];
	build(1,1,n-1);
	for (int _=read();_;_--){
		scanf("%s", op);
		if (op[0]=='+'){
			int i=read(), x=read();
			if (i==1) a[1]+=x;
			if (i<n) update(1,1,n-1,i,-x);
			if (i>1) update(1,1,n-1,i-1,x);
			if (i==n || query(1,1,n-1,i,i)>=0) continue;
			int le=i, ri=n;
			ll tmp=0, tp=0;
			while (le<ri-1){
				int mid=le+ri>>1;
				if ((tmp=query(1,1,n-1,i,mid))>=0) ri=mid, tp=tmp;
				else le=mid;
			}
			if (tp)
				set(1,1,n-1,i,le,0),
				set(1,1,n-1,ri,ri,tp);
			else set(1,1,n-1,i,min(ri,n-1),0);
		//	for (int i=1;i<=n;i++)
		//		printf("%I64d%s", a[1]+queryf(1,1,n-1,i-1)+ps[i-1], i==n?"\n":" ");
		}
		else{
		//	for (int i=1;i<=n;i++)
		//		printf("%I64d%s", a[1]+queryf(1,1,n-1,i-1)+ps[i-1], i==n?"\n":" ");
			int l=read(), r=read();
			//cout<<calc(r)<<' '<<calc(l-1)<<endl;
			printf("%I64d\n", calc(r)-calc(l-1));
		}
	}
	return 0;
}
