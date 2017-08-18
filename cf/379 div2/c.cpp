#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, k, x, s, a[310000], b[310000], c[310000], d[310000], e[310000];
long long ans;
bool cmp(int x, int y){return b[x]<b[y];}
int main(){
	cin>>n>>m>>k;
	cin>>x>>s;
	for (int i=1;i<=m;i++) scanf("%d", &a[i]);
	for (int i=1;i<=m;i++) scanf("%d", &b[i]), e[i]=i;
	sort(e+1,e+1+m,cmp);
	for (int i=1;i<=k;i++) scanf("%d", &c[i]);
	for (int i=1;i<=k;i++) scanf("%d", &d[i]);
	int j=k;
	a[0]=x;
	ans=(long long)2000000000*2000000000;
	for (int i=0;i<=m && b[e[i]]<=s;i++){
		while (d[j]>s-b[e[i]]) j--;
		if (c[j]>=n) {ans=0;break;}
		ans=min(ans,(long long)a[e[i]]*(n-c[j]));
	}
	cout<<ans<<endl;
	return 0;
}
