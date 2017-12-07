#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
double x[10001], ans;
int n, m;
int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++) scanf("%lf", &x[i]);
	for (int i=1;i<=m;i++){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		x[u]+=(double)w/2;
		x[v]+=(double)w/2;
	}
	sort(x+1,x+n+1);
	for (int i=2;i<=n;i+=2){
		ans+=x[i]-x[i-1];
	}
	cout<<(int)ans<<endl;
	return 0;
}
