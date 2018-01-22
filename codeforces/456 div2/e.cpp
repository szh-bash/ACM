#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
typedef unsigned long long ll;
using namespace std;
int n, k, p[100], cnt, g[100];
ll f[1000000];
int main(){
	cin>>n;
	double INF=(ll)1000000000*1000000001;
	for (int i=1;i<=n;i++) cin>>p[i];
	g[0]=1;
	for (int i=1;i<=n;i++) g[i]=g[i-1]*2;
	for (int i=1;i<g[n];i++){
		ll x=1;
		int k=1;
		for (int j=1;j<=i;j<<=1,k++)
			if (i&j){
				if ((INF/x)<p[k]){
					x=f[++cnt]=(ll) INF;
					break;
				}
				else x*=p[k];
			}
		if (x<INF) f[++cnt]=x;
		cout<<i<<' '<<x<<endl;
	}
	sort(f+1,f+1+cnt);
	cin>>k;
	cout<<f[k]<<endl;
	return 0;
}
