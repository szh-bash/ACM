#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
typedef unsigned long long ULL;
using namespace std;
ULL ans, n, k, l, r, d;
int main(){
	cin>>n>>k;
	for (int i=1;i<=n;i=r+1){
		d=k/i;
		l=k/(d+1)+1;
		r=d?k/d:n;
		r=r>n?n:r;
		ans+=(2*k-d*(l+r))*(r-l+1);
	}
	cout<<ans/2<<endl;
	return 0;
}
