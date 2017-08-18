#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;
int read(){
	int p=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
int sg(int u, int v){
	int j=0;
	for (ll i=2;i;i<<=1, j++)
		if ((u-1)%i<i/2 && (v-1)%i<i/2) return j;
}
int main(){
	for (int T=read();T;T--){
		int n=read(), ans=0;
		for (int i=1;i<=n/2;i++){
			int u=read(), v=read();
			ans^=sg(u,v);
		}
		if (ans) cout<<"YES"<<endl;else cout<<"NO"<<endl;
	}
	return 0;
}
