#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, a[300000], b[300000], f[200100];
bool cmp(int a, int b){return a>b;}
int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++) scanf("%d", &a[i]);
	for (int i=1;i<=m;i++) scanf("%d", &b[i]);
	sort(a+1,a+1+n,cmp);
	sort(b+1,b+1+m,cmp);
	int mid, le=0, ri=m+1;
	while (le<ri-1){
		mid=le+ri>>1;
		int tot=0, ans=0, j=1;
		long long k=1, p;
		memset(f,0,sizeof(f));
		for (int i=mid;i;i--) f[b[i]]++;
		for (int i=1;i<=n;i=j){
			p=k;
			j=i;
			for (;(j<i+k) && (j<=n);j++) p=p+a[j]-1;
			k=p;
			tot++;
			ans+=k<f[tot]?k:f[tot];
			k=k-f[tot];
			if (k<=0) break;
		}
		if (k>0)
			for (int i=tot+1;i<=b[1];i++){
				ans+=k<f[i]?k:f[i];
				k=k-f[i];
				if (k<=0) break;
			}
		if (ans==mid) le=mid;else ri=mid;
	}
	if (!b[m]) le=max(le,1);
	cout<<le<<endl;
	return 0;
}
