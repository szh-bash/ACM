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
#define N 300000
typedef long long ll;
using namespace std;
int n, a[N], b[N], ans, c[N];
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
	n=read();
	int ct=0;
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) b[i]=read(), ct+=b[i]>0;
	for (int i=1;i<=n;i++) c[i]=b[i]?(b[i]-i-1):n;
	c[n+1]=n+1;
	for (int i=n;i;i--) c[i]=min(c[i+1],c[i]);
	if (c[1]==-1 && ct==n){
		cout<<0<<endl;
		return 0;
	}
	int x=b[n], cnt=0;
	ans=n*2;
	for (int i=0;i<n;i++)
		if (c[i+1]+i>=0){
			ans=i+n;
			break;
		}
	for (int i=n;i;i--){
//		cout<<i<<' '<<x<<' '<<x-(n-i)<<' '<<b[i]<<endl;
		if (b[i] && b[i]==x-(n-i)) cnt++;
		else{
			if (x!=cnt) cnt=0;
			break;
		}
	}
//	cout<<cnt<<endl;
	int flag=1;
	for (int i=1;i<=n-cnt;i++)
		if (b[i] && b[i]<=cnt+i){
			flag=0;
			break;
		}
//	cout<<ans<<' '<<cnt<<endl;
	if (flag) ans=min(ans,n-cnt);
	cout<<ans<<endl;
	return 0;
}
