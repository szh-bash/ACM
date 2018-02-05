#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <bitset>
#include <cstring>
#include <cstdlib>
#include <complex>
#include <iostream>
#include <algorithm>
typedef long long ll;
int n, k, f[300];
using namespace std;
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
	for (int T=read();T;T--){
		n=read();k=read();
		for (int i=1;i<=n;i++) f[i]=n;
		for (int i=1;i<=k;i++){
			int x=read();
			for (int j=1;j<=n;j++)
				f[j]=min(f[j],abs(x-j)+1);
		}
		int ans=0;
		for (int i=1;i<=n;i++) ans=max(ans,f[i]);
		cout<<ans<<endl;
	}
	return 0;
}
