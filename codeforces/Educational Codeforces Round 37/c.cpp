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
int n, a[N], b[N], c[N];
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
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(), b[i]=a[i];
	sort(b+1,b+1+n);
	for (int i=1;i<=n;i++) c[i]=getchar()-'0';
	c[n+1]=0;
	int le=0, flag=1;
	a[n+1]=b[n+1]=N;
	for (int i=1;i<=n+1;i++)
		if (!c[i]){
			sort(a+le+1,a+i+1);
			for (int j=le+1;j<=i;j++)
				if (a[j]!=b[j]) flag=0;
			le=i;
		}
	if (flag) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
