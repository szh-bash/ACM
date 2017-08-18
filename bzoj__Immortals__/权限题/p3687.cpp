#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 2100000
using namespace std;
int n, ans;
bitset<N> f;
int read(){
	int p=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
int main(){
	cout<<sizeof(f)<<endl;
	n=read();
	f[0]=1;
	for (int i=1;i<=n;i++){
		int x=read();
		f^=f<<x;
	}
	for (int i=1;i<N;i++)
		ans^=f[i]*i;
	cout<<ans<<endl;
	return 0;
}
