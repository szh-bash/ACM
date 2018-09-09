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
#define num(x) (x>='0' && x<='9')
#define N 1000000
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int fx[N], fy[N], x[N], y[N], lsh[N], trans[N], ct, cnt, n;
int mp[N*20];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
int queryx(int t, int l, int r, int x){
	if (!fx[t]) return 0;
	if (r<x) return fx[t];
	int mid=l+r>>1;
	int p=0;
	if (x-1>mid) p=queryx((t<<1)+1,mid+1,r,x);
	if (p) return p;
	return queryx(t<<1,l,mid,x);
}
int queryy(int t, int l, int r, int y){
	if (!fy[t]) return 0;
	if (r<y) return fy[t];
	int mid=l+r>>1;
	int p=0;
	if (y-1>mid) p=queryy((t<<1)+1,mid+1,r,y);
	if (p) return p;
	return queryy(t<<1,l,mid,y);
}
void updx(int t, int l, int r, int x){
	if (l==r) {fx[t]=l;return;}
	int mid=l+r>>1;
	if (x>mid) updx((t<<1)+1,mid+1,r,x);
	else updx(t<<1,l,mid,x);
	fx[t]=max(fx[(t<<1)+1],fx[t<<1]);
}
void updy(int t, int l, int r, int y){
	if (l==r) {fy[t]=l;return;}
	int mid=l+r>>1;
	if (y>mid) updy((t<<1)+1,mid+1,r,y);
	else updy(t<<1,l,mid,y);
	fy[t]=max(fy[(t<<1)+1],fy[t<<1]);
}
int main(){
	n=read();
	for (int i=1;i<=n;i++)
		lsh[++cnt]=x[i]=read(),
		lsh[++cnt]=y[i]=read();
	sort(lsh+1,lsh+1+cnt);
	for (int i=1;i<=cnt;i++)
		if (lsh[i]!=lsh[i-1]) trans[mp[lsh[i]]=++ct]=lsh[i];
	ll ans=0;
	for (int i=n;i;i--){
		x[i]=mp[x[i]];
		y[i]=mp[y[i]];
		ans+=trans[x[i]]-trans[queryx(1,1,ct,x[i])];
		ans+=trans[y[i]]-trans[queryy(1,1,ct,y[i])];
		//cout<<trans[x[i]]-trans[queryx(1,1,ct,x[i])]<<' '<<trans[y[i]]-trans[queryy(1,1,ct,y[i])]<<endl;
		updx(1,1,ct,x[i]);
		updy(1,1,ct,y[i]);
	}
	cout<<ans<<endl;
    return 0;
}
