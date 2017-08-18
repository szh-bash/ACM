#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define M 20000
using namespace std;
struct qlz{
	int x, y1, y2, p;
}l[100000];
int n, ans, cnt, len[100000], cov[100000];
bool cmp(qlz a , qlz b){return a.x<b.x;}
void pushdown(int t, int l, int mid, int r){
	cov[t*2]+=cov[t];
	if (cov[t*2]) len[t*2]=mid-l+1;
	cov[t*2+1]+=cov[t];
	if (cov[t*2+1]) len[t*2+1]=r-mid;
	cov[t]=0;
}
void pushup(int t){
	len[t]=len[t*2]+len[t*2+1];
}
void update(int t, int l, int r, int le, int ri, int p){
	if (le<=l && r<=ri){
		cov[t]+=p;
		if (cov[t])
			len[t]=r-l+1;
		else
			len[t]=len[t*2]+len[t*2+1];
		return;
	}
	int mid=l+r>>1;
	pushdown(t,l,mid,r);
	if (le<=mid) update(t*2,l,mid,le,ri,p);
	if (mid<ri) update(t*2+1,mid+1,r,le,ri,p);
	pushup(t);
}
int main(){
	freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		x1+=10000;y1+=10000;
		x2+=10000;y2+=10000;
		l[++cnt].x=x1+1;l[cnt].y1=y1+1;l[cnt].y2=y2;
		l[cnt].p=1;
		l[++cnt].x=x2+1;l[cnt].y1=y1+1;l[cnt].y2=y2;
		l[cnt].p=-1;
	}
	sort(l+1,l+1+cnt,cmp);
	for (int i=1;i<cnt;i++){
		update(1,1,M,l[i].y1, l[i].y2, l[i].p);
		long long dx=l[i+1].x-l[i].x;
		ans+=dx*len[1];
		cout<<ans<<' '<<dx<<' '<<len[1]<<endl;
	}
	printf("%lld\n", ans);
	return 0;
}
