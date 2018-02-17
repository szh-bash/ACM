#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;
int n, m;
ll a[100], b[100];
int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=m;i++) cin>>b[i];
	ll ans=(ll)1000000000*1000000000;
	for (int i=1;i<=n;i++){
		ll ma=-(ll)1000000000*1000000000;
		for (int j=1;j<=n;j++)
			if (i!=j)
				for (int k=1;k<=m;k++)
				if (a[j]*b[k]>ma) ma=a[j]*b[k];
		if (ma<ans) ans=ma;
	}
	cout<<ans<<endl;
	return 0;
}
