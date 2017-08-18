#include <cstdio>
#include <cstdlib>
#include <cstdlib>
#include <iostream>
typedef long long LL;
using namespace std;
LL l, r, ans;
int main(){
	cin>>l>>r;
	ans+=max((LL)0,r/11-l+1);
	ans+=max((LL)0,r/29-l+1);
	cout<<4<<endl;
	cout<<ans<<endl;
	return 0;
}
