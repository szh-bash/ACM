#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
struct zsm {
	int a, b, g;
	long long x;
}l[1000000];
bool cmp1(zsm a, zsm b){return a.l<b.l;}
bool cmp2(zsm a, zsm b){return a.r<b.r;}
bool cmp3(zsm a, zsm b){return a.x<b.x;}
int main(){
	scanf("%d%d", &n, &p);
	for (int i=1;i<=n;i++){
		scanf("%d%d", &f[i].l, &f[i].r);
		if (f[i].l>f[i].r) swap(f[i].l,f[i].r);
		f[i].x=(long long)f[i].l*n+f[i].r;
	}
	sort(f+1,f+1+n,cmp1);
	int j=1;
	for (int i=1;i<=n;i++){
		while (f[i].l>j) j++;
		p[j]++;
	}
	sort(f+1,f+1+n,cmp2);
	j=1;
	for (int i=1;i<=n;i++){
		while (f[i].r>j) j++;
		p[j]++;
	}
	sort(f+1,f+1+n,cmp3);
	j=0;
	for (int i=1;i<=n;i++)
		if (f[i]!=f[i-1]) f[i].g=++j;else f[i].g=j;
	return 0;
}
