#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
long long n, k, ans;
int main(){
	cin>>n>>k;
	ans=n/k;
	if (ans&1) cout<<"YES"<<endl;else cout<<"NO"<<endl;
	return 0;
}
