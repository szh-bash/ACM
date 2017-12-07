#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
struct zsm{
	int l, r, n;
}
bool cmp(zsm a, zsm b){return a.l<b.l};
void build(int t, int l, int r){
	if (l==r){
		s[t]=sg[l];
		return;
	}
	int mid=l+r>>1;
	if (i<=mid) build(t*2,l,mid);else build(t*2+1,mid+1,r);
	s[t]=max(s[t*2],s[t*2+1]);
}
void pushdown(int t){
	if (p[t]==-1) return;
	p[t*2]=s[t*2]=p[t*2+1]=s[t*2+1]=p[t];
	p[t]=-1;
}///////////////
int find(int t, int l, int r){
	if (l==r) return s[t];
	pushdown(t);
	int mid=l+r>>1;
	if (l<=mid) return find(t*2,l,mid);else return find(t*2+1,mid+1,r);
	s[t]=max(s[t*2],s[t*2+1]);
}
void updata(int t, int l, int r){
	pushdown(t);
	int mid=l+r>>1;
	if (le<=l && r<=ri){
		if (s[t*2]>x) updata(t*2,l,mid), p[t*2+1]=s[t*2+1]=x;
		else
			if (s[t*2+1]>x) updata(t*2+1,mid+1,r);
		return;
	}
	if (ri>mid) updata(t*2+1,mid+1,r);
	if (le<=mid) updata(t*2,le,mid);
	s[t]=max(s[t*2],s[t*2+1]);
}
int main(){
	scanf("%d%d", &n, &q);
	int j=0;
	for (int i=1;i<=n*10;i++) s[i]=1e8;
	for (i=1;i<=n;i++){
		scanf("%d", &a[i]);
		f[a[i]]=1;
		while (f[j]) j++;
		sg[i]=j;
		build(1,1,n);
		next[last[a[i]]]=i;
		last[a[i]]=i;
	}
	for (int i=1;i<=q;i++) scnaf("%d%d", &b[i].l, &b[i].r), b[i].n=i;
	sort(b+1,b+1+q,cmp);
	memset(p,-1,sizeof(p));
	for (int i=1;i<=n;i++){
		if (b[i].l==b[i-1].l) x=i, ans[b[i].n]=find(1,1,n), continue;
		le=b[i-1].l;
		while (le<b[i].l){
			ri=next[le]-1;
			x=a[le];
			updata(1,1,n);
			le++;
		}
	}
	return 0;
}
