#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define Q 400000
#define N 400000
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
struct qlz{
	int l, r;
}l[Q];
int n, q, ans, countt, cnt, f[N*20], ls[N*20], rs[N*20], a[N], root[N];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
void initialize(int x){
	for (int i=1;i<=cnt;i++) ls[i]=rs[i]=0;
	cnt=x;
	countt=0;
	for (int i=1;i<=x;i++)
		l[i].l=x+1,
		l[i].r=0,
		f[i]=0;
}
bool cmp(qlz a, qlz b){
	return a.l<b.l;
}
void add(int x, int y){
	int l=1, r=n, j=root[x-1];
	root[x]=x;
	while (l<r){
		int mid=l+r>>1;
		f[x]=f[j]+1;
		if (y<=mid) rs[x]=rs[j], x=ls[x]=++cnt, j=ls[j], r=mid;
		else ls[x]=ls[j], x=rs[x]=++cnt, j=rs[j], l=mid+1;
	}
	f[x]=f[j]+1;
}
int main(){
	while (~scanf("%d%d", &n, &q)){
		initialize(n);
		for (int i=1;i<=n;i++){
			a[i]=read();
			l[a[i]].l=min(l[a[i]].l,i),
			l[a[i]].r=max(l[a[i]].r,i);
		}
		sort(l+1,l+1+n,cmp);
		for (int i=1;i<=n && l[i].l<=n;i++){
			countt++;
			for (int j=l[i-1].l+1;j<l[i].l;j++) root[j]=root[j-1];
			add(l[i].l,l[i].r);
		}
		for (int i=l[countt].l+1;i<=n;i++) root[i]=root[i-1];
		for (int i=1;i<=q;i++){
			ans=countt;
			int le=read(), ri=read()-1, k=ri, l=1, r=n;
			if (le>=ri){
				printf("%d\n", ans);
				continue;
			}
			le=root[le];ri=root[ri];
			while (l<r){
				int mid=l+r>>1;
				if (k>mid){
					ans-=f[ls[ri]]-f[ls[le]];
					le=rs[le];
					ri=rs[ri];
					l=mid+1;
				}
				else{
					le=ls[le];
					ri=ls[ri];
					r=mid;
				}
			}
			ans-=f[ri]-f[le];
			printf("%d\n", ans);
		}
	}
    return 0;
}
