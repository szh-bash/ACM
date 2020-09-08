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
void solve(){
	ll l=readll(), r=readll(), m=readll(), del=r-l;
	ll le=max(0ll,m-del), ri=m+del;
	ll a, b, c, n;
	for (int i=l;i<=ri;i++)
		if (((le-1)/i+1)*i<=ri){
			a=i;
			n=(le-1)/i+1;
			if (m-n*a>=0)
				b=l+m-n*a,
				c=l;
			else
				b=l,
				c=l-(m-n*a);
			break;
		}
	cout<<a<<' '<<b<<' '<<c<<endl;
}
int main(){
	for (int _=read();_;_--) solve();
	return 0;
}
