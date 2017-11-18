#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 3000
typedef long long ll;
using namespace std;
int n, a[N], gys;
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9')
		(ch=='-'?q=-1:0),
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
int gcd(int a, int b){return b?gcd(b,a%b):a;}
int main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(), gys=gcd(gys,a[i]);
	int tot=0;
	for (int i=1;i<=n;i++)
		if (a[i]==1) tot++;
	if (gys>1){
		cout<<-1<<endl;
		return 0;
	}
	int ans=n;
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			a[i]=gcd(a[i],a[j]);
			if (a[i]==1){
				ans=min(ans,j-i);
				break;
			}
		}
	}
	if (tot) ans-=tot-1;
	ans+=n-1;
	cout<<ans<<endl;
	return 0;
}
