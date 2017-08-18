#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm> 
using namespace std;
struct zsm{
	int h, n;
}l[200000];
int cmp(zsm a, zsm b){return a.h<b.h;}
int n, cnt, tmp, v, le, ri, h[200000], p1[1000000], p2[1000000];
int query1(int t, int l, int r){
	if (le<=l && r<=ri) return p1[t];
	int mid=(l+r)>>1, tmp=0;
	if (mid<ri) tmp=max(tmp,query1((t<<1)+1,mid+1,r));
	if (le<=mid) tmp=max(tmp,query1(t<<1,l,mid));
	return tmp;
}
void update1(int t, int l, int r){
	if (l==r) {
		p1[t]=max(p1[t],tmp);
		return;
	}
	int mid=(l+r)>>1;
	if (v>mid) update1((t<<1)+1,mid+1,r);
	else update1(t<<1,l,mid);
	p1[t]=max(p1[t<<1],p1[(t<<1)+1]);
}
int query2(int t, int l, int r){
	if (le<=l && r<=ri) return p2[t];
	int mid=(l+r)>>1, tmp=0;
	if (mid<ri) tmp=max(tmp,query2((t<<1)+1,mid+1,r));
	if (le<=mid) tmp=max(tmp,query2(t<<1,l,mid));
	return tmp;
}
void update2(int t, int l, int r){
	if (l==r) {
		p2[t]=max(p2[t],tmp);
		return;
	}
	int mid=(l+r)>>1;
	if (v>mid) update2((t<<1)+1,mid+1,r);
	else update2(t<<1,l,mid);
	p2[t]=max(p2[t<<1],p2[(t<<1)+1]);
}
int main(){
	scanf("%d", &n);
	for (int i=1;i<=n;i++) scanf("%d", &l[i].h),l[i].n=i;
	sort(l+1,l+1+n,cmp);
	cnt=0;
	l[0].h=-1;
	for (int i=1;i<=n;i++){
		if (l[i].h!=l[i-1].h) cnt++;
		h[l[i].n]=cnt;
	}
	for (int i=1;i<=n;i++){
		v=h[i];
		le=0;ri=h[i]-1;
		tmp=query2(1,0,n+1)+1;
		update1(1,0,n+1);
		le=h[i]+1;ri=n+1;
		tmp=query1(1,0,n+1)+1;
		update2(1,0,n+1);
	}
	le=0;ri=n+1;
	printf("%d\n", max(query1(1,0,n+1),query2(1,0,n+1)));
return 0;
}
