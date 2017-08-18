#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int ans, a, b, c, d;
int main(){
	cin>>a>>b>>c>>d;
	for (int i=0;i<=min(b,a);i++)
		ans=max(ans,i*32+min(a-i,min(c,d))*256);
	cout<<ans<<endl;
	return 0;
}
