#include <map>
#include <set> 
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
int a, b, c, d, y, x;
ll ans;
int main(){
	a=read(), b=read(), c=read(), d=read();
	for (int i=c;i<=d && i<b+c;i++){
		if (i<b+b){
			if (a+b>i){
				ans+=1ll*(c-b+1)*(b-a+1);
			}
			else{
				x=i-b;
				int d1=b-x, d2=c-b+1, d3=x-a+1;
				if (d2<=d3)
					ans += 1ll*(d1+d1+d2-1)*d2/2;
				else ans += 1ll*(d1+d1+d3-1)*d3/2+1ll*(d2-d3)*(d1+d3);
			}
		}
		else{
			y=i-b;
			int d1=b-a+1, d2=c-y;
			if (d1<=d2){
				ans+=1ll*(d2+d2-d1+1)*d1/2;
			}
			else{
				ans+=1ll*(d2+1)*d2/2;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
