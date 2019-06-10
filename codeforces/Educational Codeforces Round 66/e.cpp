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
#define N 500000
#define M 4000000
#define INF 99999999
typedef long long ll;
using namespace std;
int f[M], g[M], num[N], l[N], r[N], n, m, bit[N], fa[N][30], gt[N];
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') 
		ch=='-'?q=-1:0,
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
bool cmp(int x, int y){
	if (l[x]<l[y]) return 1;
	if (l[x]>l[y]) return 0;
	return r[x]>r[y];
}
void pushdown(int t){
	if (g[t]){
		g[t<<1]+=g[t];
		f[t<<1]+=g[t];
		g[(t<<1)+1]+=g[t];
		f[(t<<1)+1]+=g[t];
		g[t]=0;
	}
}
void upd(int t, int l, int r, int le, int ri){
	if (le<=l && r<=ri){
		g[t]++;
		f[t]++;
		return;
	}
	pushdown(t);
	int mid=l+r>>1;
	if (le<=mid) upd(t<<1,l,mid,le,ri);
	if (ri>mid) upd((t<<1)+1,mid+1,r,le,ri);
	f[t]=min(f[t<<1],f[(t<<1)+1]);
}
int query(int t, int l, int r, int le, int ri){
	if (le<=l && r<=ri) return f[t];
	pushdown(t);
	int mid=l+r>>1;
	int p0=INF, p1=INF;
	if (le<=mid) p0=query(t<<1,l,mid,le,ri);
	if (ri>mid) p1=query((t<<1)+1,mid+1,r,le,ri);
	return min(p0,p1);
}
int main(){
	n=read();m=read();
	for (int i=1;i<=n;i++) l[i]=read(), r[i]=read(), num[i]=i;
	sort(num+1,num+1+n,cmp);
	int j=1;
	for (int i=2;i<=n;){
		if (l[num[i]]==l[num[j]] || r[num[i]]<=r[num[j]]) i++;
		else{
			num[++j]=num[i++];
		}
	}
	n=j;
	int ma=500000*2;
	for (int i=1;i<=n;i++)
		upd(1,0,ma,l[num[i]]*2,r[num[i]]*2);
	for (int i=1;i<=n;i++){
		int le=i, ri=n+1;
		while (le<ri-1){
			int mid=le+ri>>1;
			if (l[num[mid]]<=r[num[i]]) le=mid;
			else ri=mid;
		}
		if (le==i) le=n+1;
		fa[i][0]=le;
	}
	fa[n+1][0]=n+1;
	for (int i=1;i<=n;i++)
		for (int j=1;fa[fa[i][j-1]][j-1]<=n;j++)
			fa[i][j]=fa[fa[i][j-1]][j-1],
			gt[i]=j;
	bit[0]=1;
	for (int i=1;bit[i-1]<n;i++) bit[i]=bit[i-1]<<1;
	for (int i=1;i<=m;i++){
		int x=read(), y=read();
		if (!query(1,0,ma,x*2,y*2)) puts("-1");
		else{
			int le=1, ri=n+1;
			while (le<ri-1){
				int mid=le+ri>>1;
				if (l[num[mid]]>x) ri=mid;
				else le=mid;
			}
			int st=le;
			le=0, ri=n;
			while (le<ri-1){
				int mid=le+ri>>1;
				if (r[num[mid]]<y) le=mid;
				else ri=mid;
			}
			int ed=ri;
			int tot=0, x=st;
			for (int j=gt[st];j>=0;j--)
				if (fa[x][j] && fa[x][j]<=ed) tot+=bit[j], x=fa[x][j];
			printf("%d\n", 1+tot+(x!=ed));
		}
	}
	return 0;
}
