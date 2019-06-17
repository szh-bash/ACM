#include <map>
#include <ctime>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=='-'?q=-1:0, ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
ll readll(){
	ll p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=='-'?q=-1:0, ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
int main(){
	ll x, y, z, t, tx ,ty, dx, dy;
	cin>>x>>y>>z; 
	t=(x+y)/z;
	tx=x/z;
	ty=y/z;
	if (tx+ty==t) cout<<t<<' '<<0<<endl;
	else{
		dx=x-tx*z;
		dy=y-ty*z;
		cout<<t<<' '<<z-max(dx,dy)<<endl;
	}
	return 0;
}
