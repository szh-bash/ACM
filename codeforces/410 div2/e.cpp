#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
void add(int u,int v){
	next[++cnt]=next[u];next[u]=cnt;nu[cnt]=v;
}
int query(int t, int l, int r, int x){
	if (!f[t]) reutrn 0;
	if (l==r) return x;
	int mid=l+r>>1;
	if (x<=mid && f[t*2]) return query(t*2,l,mid,x);
	else return query(t*2+1,mid+1,r,x);
}
void update(int t, int l, int r, int x){
	if (l==r){
		f[t]=1;
		return;
	}
	int mid=l+r>>1;
	if (x<=mid) update(t*2,l,mid,x);
	else update(t*2+1,mid+1,r,x);
	f[t]=f[t*2]+f[t*2+1];
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		scanf("%d", &a[i]);
		if (a[i]<0) a[i]=n+1;
		b[a[i]]=i;
		if (a[i]<=n) add(a[i],i);
	}
	for (int i=n;i;i--)
		if (b[i]<=n){
			int t=query(1,1,n,b[i]);
			if (t) add(t,i);
			update(1,1,n,b[i]);
		}
	return 0;
}
