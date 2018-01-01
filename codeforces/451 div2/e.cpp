#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 300000
typedef long long ll;
using namespace std;
int n, a[N], b[N], tot, ze;
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9')
		(ch=='-'?q=-1:0),
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
int main(){
	n=read();
	for (int i=1;i<=n;i++){
		a[i]=read();
		int x=sqrt(a[i]);
		if (x*x==a[i]) b[i]=0;
		else b[i]=min(a[i]-x*x, (x+1)*(x+1)-a[i]);
		if (!b[i]) tot++;
		if (!a[i]) ze++;
	}
	if (tot==n/2){
		cout<<0<<endl;
		return 0;
	}
	sort(b+1,b+1+n);
	if (tot>n/2){
		int k=tot-n/2;
		ll ans=0;
		if (tot-ze>=k) ans=k;
		else
			ans=k+k-(tot-ze);
		cout<<ans<<endl;
	}
	else{
		int k=n/2-tot;
		ll ans=0;
		for (int i=1;k && i<=n;i++)
			if (b[i]) ans+=b[i], k--;
		cout<<ans<<endl;
	}
	return 0;
}
