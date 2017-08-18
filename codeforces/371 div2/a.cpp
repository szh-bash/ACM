#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
long long l1, l2, r1, r2, k, ans;
int main(){
	cin>>l1>>r1>>l2>>r2>>k;
	l1=max(l1,l2);
	r1=min(r1,r2);
	if (k>=l1 && k<=r1) ans--;
	ans+=r1-l1+1;
	if (ans<0) ans=0;
	cout<<ans<<endl;
	return 0;
}
