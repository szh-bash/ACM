#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, m, l, r, ans=500000;
int main(){
	cin>>n>>m;
	for (int i=1;i<=m;i++){
		cin>>l>>r;
		ans=min(ans,r-l+1);
	}
	cout<<ans<<endl;
	for (int i=1;i<=n;i++) cout<<(i-1)%ans<<' ';
	cout<<endl;
	return 0;
}
