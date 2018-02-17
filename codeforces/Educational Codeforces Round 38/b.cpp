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
#define INF 1000000
#define N 200000
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
	a[n+1]=INF;
	int ans=INF-a[1];
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) ans=min(ans,max(a[i]-1,INF-a[i+1]));
	cout<<ans<<endl;
	return 0;
}
