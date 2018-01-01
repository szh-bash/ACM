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
using namespace std;
int f[2000][2000], a[2000], ans, n;
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
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++)
		for (int j=i-1;j;j--)
			f[i][j]=f[i][j+1]+(a[i]<a[j]);
	for (int i=1;i<=n;i++)
		ans+=f[i][1];
	ans&=1;
	for (int q=read();q;q--){
		int l=read(), r=read();
		ans^=((r-l+1)*(r-l)/2)&1;
		if (ans) printf("odd\n");
		else printf("even\n");
	}
	return 0;
}
