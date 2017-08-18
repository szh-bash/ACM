#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
struct zsm{
	int h, n;
}l[2000000];
int n, h[2000000];
long long ans;
int cmp(zsm a, zsm b){
	return a.h>b.h;
}
int main(){
	scanf("%d", &n);
	for (int i=1;i<=n;i++){
	    scanf("%d", &l[i].h);
		l[i].n=i;
		h[i]=l[i].h;
	}
	sort(l+1,l+1+n,cmp);
	ans=0;
	for (int i=1;i<=n;i++){
		if (!h[l[i].n])continue;
		int j=l[i].n, minn;
		ans+=h[j];
		minn=h[j];
		for (int k=j+1;k<=n;k++){
			minn=min(minn,h[k]);
			if (!minn) continue;
			h[k]-=minn;
		}
		minn=h[j];
		for (int k=j-1;k>=1;k--){
			minn=min(minn,h[k]);
			if (!minn) continue;
			h[k]-=minn;
		}
		h[j]-=minn;
	}
	printf("%lld\n", ans);
	return 0;
}
