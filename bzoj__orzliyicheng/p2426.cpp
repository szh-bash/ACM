#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
struct cp{
	int v, n;
}b[60000];
int m, B, H, n, a[60000], h[60000], c[60000], p;
long long tp=(long long)1e11;
bool cmp(cp a, cp b){return a.v>b.v;}
int main(){
	scanf("%d%d%d%d", &m, &B, &H, &n);
	for (int i=1;i<=m;i++) scanf("%d", &a[i]);
	for (int i=1;i<=n;i++) scanf("%d", &h[i]);
	for (int i=1;i<=m;i++) scanf("%d", &c[i]);
	for (int i=1;i<=n;i++){
		int tmp=0;
		long long ans=h[i]+H;
		for (int j=1;j<=m;j++)
			scanf("%d", &b[j].v), ans+=(long long)b[j].v*a[j], b[j].v-=c[j], b[j].n=j;
		sort(b+1,b+1+m,cmp);
		for (int j=1;j<=m;j++)
			if (tmp+a[b[j].n]<=B) tmp+=a[b[j].n], ans-=(long long)a[b[j].n]*b[j].v;
			else {ans-=(long long)(B-tmp)*b[j].v;break;}
		if (ans<tp) tp=ans, p=i;
	}
	printf("%d\n%lld\n", p, tp);
	return 0;
}

