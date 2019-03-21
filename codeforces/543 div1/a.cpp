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
#define N 3000000
typedef long long ll;
using namespace std;
int f[N], a[N], b[N], n, m, k, s, ma;
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') 
		ch=='-'?q=-1:0,
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
void upd(int t, int l, int r, int x, int y){
	if (l==r){
		f[t]+=y;
		return;
	}
	int mid=l+r>>1;
	if (x<=mid) upd(t<<1,l,mid,x,y);
	else upd((t<<1)+1,mid+1,r,x,y);
	f[t]=max(f[t<<1], f[(t<<1)+1]);
}
int query(int t, int l, int r, int le, int ri){
	if (le<=l && r<=ri) return f[t];
	int mid=l+r>>1, p=-1;
	if (le<=mid) p=max(p,query(t<<1,l,mid,le,ri));
	if (ri>mid) p=max(p,query((t<<1)+1,mid+1,r,le,ri));
	return p;
}
int main(){
	m=read();k=read();n=read();s=read();
	int ma0=0;
	for (int i=1;i<=m;i++) a[i]=read(), ma=max(ma,a[i]);
	for (int i=1;i<=s;i++) b[i]=read(), ma0=max(ma0,b[i]), upd(1,1,ma,b[i],1);
	if (ma0>ma) {
		puts("-1");
		return 0;
	}
	int j=1;
	for (int i=1;i<=m;i++){
		upd(1,1,ma,a[i],-1);
		while (query(1,1,ma,a[j],a[j])<0){
			upd(1,1,ma,a[j],1);
			j++;
		}
		if (query(1,1,ma,1,ma)<=0){
			int len=i-j+1, del=0, last;
			if (len>k) del+=len-k, len=k;
			last=(i-del)%k;
			if (m-last-del<n*k) continue;
			printf("%d\n", last+del);
			for (int p=1;p<=last;p++) printf("%d\n", j-p);
			for (int p=j, t=0;p<=i, t<del;p++){
				if (query(1,1,ma,a[p],a[p])<0)
					upd(1,1,ma,a[p],1),
					printf("%d\n", p),
					t++;
			}
			return 0;
		}
	}
	puts("-1");
	return 0;
}
