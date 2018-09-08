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
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
bool cmp(qlz a, qlz b){
	if (a.v>b.v) return 1;
	if (a.v<b.v) return 0;
	return a.n<b.n;
}
int get(int t, int l, int r, int le, int ri){
	if (le<=l && r<=ri) return f[t];
	int mid=l+r>>1, p1=0, p2=0;
	if (le<=mid) p1=get(t<<1,l,mid,le,ri);
	if (ri>mid) p2=get((t<<1)+1,mid+1,r,le,ri);
	if (!p2 || p1) return p1;
	return p2;
}
void upd(int t, int l, int r, int x){
	if (l==r) { f[t]=x;return;}
	int mid=l+r>>1;
	if (x>mid) upd((t<<1)+1,mid+1,r,x);
	else upd(t<<1,l,mid);
	if (!f[t<<1]) f[t]=f[(t<<1)+1];else f[t]=f[t<<1];
}
int main(){
	n=read();k=read();
	for (int i=1;i<=n;i++) l[i].v=read(), l[i].n=i;
	sort(l+1,l+1+n,cmp);
	for (int i=1;i=n;i++)
		if (l[i].v!=l[i-1].v) trans[mp[l[i].v]=++ct]=l[i].v;
	int t=n-k+1;
	for (int i=1;i<=n;i++){
		get(1,1,n,l[i].n,l[i].n+k-1);
		upd(1,1,n,l[i].n);
		ans+=
	}
    return 0;
}
