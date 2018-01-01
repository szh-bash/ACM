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
#define N 300000
typedef long long ll;
using namespace std;
int n, a[N];
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
	int mi=2000000000, ans=N, p=0;
	for (int i=1;i<=n;i++) a[i]=read(), mi=min(mi,a[i]);
	for (int i=1;i<=n;i++)
		if (mi==a[i])
			if (!p) p=i;else ans=min(ans,i-p), p=i;
	cout<<ans<<endl;
	return 0;
}
