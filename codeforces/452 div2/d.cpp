#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
typedef long long ll;
using namespace std;
ll n;
ll read(){
	ll p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9')
		(ch=='-'?q=-1:0),
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
int main(){
	n=read();
	ll p=9, q, s=0, ans=0;
	for (;p<=n;p=p*10+9);
	if (n+n-1<p) p/=10;
	if (p==0){
		cout<<n*(n-1)/2<<endl;
		return 0;
	}
	q=p+1;
	for (s=p;;s+=q)
		if (s<=n) ans+=(s-1)/2;
		else{
			if (2*n-s+1<=0) break;
			ans+=(2*n-s+1)/2;
		}
	cout<<ans<<endl;
	return 0;
}
