#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 300000
typedef long long ll;
using namespace std;
int n, m, k, ans, tot, a[N], b[N];
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
	n=read();m=read();k=read();
	if (k>m){
		cout<<0<<endl;
		return 0;
	}
	for (int i=1;i<=n;i++) a[i]=read(), b[i]=1;
	sort(a+1,a+1+n);
	int j=1;
	for (int i=1;i<=n;i++){
		tot++;
		while (a[i]-a[j]+1>m) tot-=b[j++];
		if (tot==k) b[i]=0, tot--, ans++;
	}
	cout<<ans<<endl;
	return 0;
}
