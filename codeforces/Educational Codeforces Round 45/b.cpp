#include <map>
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
int n, k, ans, a[N];
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') 
		ch=='-'?q=-1:0,
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
int main(){
	n=read();k=read();
	for (int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	int j=2;
	for (int i=1;i<n;i++){
		while (j<=n && a[j]==a[i]) j++;
		if (j<=n && a[j]<=a[i]+k) ans++;
	}
	cout<<n-ans<<endl;
	return 0;
}
