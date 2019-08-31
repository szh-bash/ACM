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
#define N 45000
typedef long long ll;
using namespace std;
int n;
int a[N], nex[N];
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
map<int, int> mp;
map<int, int> f;
int main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	int suf=1;
	for (int i=n;i;i--){
		nex[i]=mp[a[i]];
		if (!mp[a[i]]) mp[a[i]]=i;
		if (nex[i]) suf=max(suf, i+1);
	}
//	for (int i=1;i<=n;i++) cout<<nex[i]<<' ';cout<<endl;
	int flag=0;
	int ma=0;
	int ans=n+1;
	for (int i=1;i<=n;i++){
		int j=i;
		for (;j<=n && (j<suf || j<=ma);j++);
//		cout<<i<<' '<<j<<endl;
		ans=min(ans, (j-i));
		if (f[a[i]])  break;
		f[a[i]]=1;
		ma=max(ma, nex[i]);
	}
	cout<<ans<<endl;
	return 0;
}
