#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int n, a[310000], g[310000], k, t;
long long v[310000], tot, sum, tp, s, c[310000];
bool cmp(int x, int y){return v[x]<v[y];}
int main(){
	cin>>n>>k>>s>>t;
	long long ans=2000000001;
	for (int i=1;i<=n;i++) scanf("%d%I64d", &c[i], &v[i]), a[i]=i;
	for (int i=1;i<=k;i++) scanf("%d", &g[i]);
	sort(g+1,g+k+1);
	g[++k]=s;
	for (int i=0;i<k;i++) g[i]=g[i+1]-g[i];
	sort(g,g+k);
	sort(a+1,a+1+n,cmp);
	k--;
	int j=0;
	for (int i=1;i<=n;i++)
		if (v[a[i]]>=g[k]){
			while (j<=k && v[a[i]]>=2*g[j]) sum+=g[j], j++;
			tp=sum+(s-sum)*3-v[a[i]]*(k+1-j);
			if (tp<=t) ans=min(ans,c[a[i]]);
		}
	if (ans==2000000001) cout<<"-1"<<endl;
	else cout<<ans<<endl;
	return 0;
}

