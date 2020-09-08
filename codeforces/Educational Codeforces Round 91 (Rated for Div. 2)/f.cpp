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
#define mo 998244353
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
#define N 501005
#define M N*8
int n, a[N], m, x;
char s[N];
int f[M][4];
inline int mul(int a, int b){
	return 1ll*a*b%mo;
}
inline void inc(int &a, int b){
	a += b;
	if (a>=mo) a-=mo;
}
inline void pushup(int t, int l, int r){
	int mid=l+r>>1;
	int tl=t<<1, tr=(t<<1)+1;
	int nl=(l==mid)?0:1;
	int nr=(r==mid+1)?0:2;
	f[t][0]=mul(f[tl][nl], f[tr][nr]);
	f[t][1]=mul(f[tl][nl], f[tr][3]);
	f[t][2]=mul(f[tl][3], f[tr][nr]);
	f[t][3]=mul(f[tl][3], f[tr][3]);
	if (a[mid]==1){
		nl=(l==mid)?2:0;
		nr=(r==mid+1)?1:0;
		inc(f[t][nl+nr],mul(mul(f[tl][0],f[tr][0]),19-10*a[mid]-a[mid+1]));
		inc(f[t][1+nl],mul(mul(f[tl][0],f[tr][1]),19-10*a[mid]-a[mid+1]));
		inc(f[t][2+nr],mul(mul(f[tl][2],f[tr][0]),19-10*a[mid]-a[mid+1]));
		inc(f[t][3],mul(mul(f[tl][2],f[tr][1]),19-10*a[mid]-a[mid+1]));
	}
}
void build(int t, int l, int r){
	if (l==r){
		f[t][0]=1;
		f[t][3]=a[l]+1;
		return;
	}
	int mid=l+r>>1; 
	build(t<<1,l,mid);
	build((t<<1)+1, mid+1, r);
	pushup(t,l,r);
}
void upd(int t, int l, int r){
	if (l==r){ 
		f[t][3]=a[l]+1;
		return;
	}
	int mid=l+r>>1;
	if (x<=mid) upd(t<<1, l, mid);
	else upd((t<<1)+1, mid+1, r);
	pushup(t,l,r);
}
int main(){
	n=read();m=read();
	scanf("%s", s+1);
	for (int i=1;i<=n;i++) a[i]=s[i]-'0';
	build(1,1,n);
	for (int i=1;i<=m;i++){
		x=read(), a[x]=read();
		upd(1,1,n);
		if (f[1][3]==17976000){
			for (int j=1;j<=n;j++) printf("%d",a[j]);puts("");
		}
		else printf("%d\n", f[1][3]);
	}
	return 0;
}
//6792116149
