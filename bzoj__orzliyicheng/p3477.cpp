#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
int n, a, b, s, x[200000];
double fm,ans;
int main(){
	scanf("%d", &n);
	n--;cin>>a;
	fm=1e8;
	for (int i=1;i<n;i++) scanf("%d", &x[i]);
	cin>>b;a+=b;
	for (int i=1;i<n;i++){
		s+=x[i];
		fm=min(fm,(double)s/i);
		ans=min(ans+x[i],fm);
	}
	cout<<ans<<endl;
	return 0;
}
