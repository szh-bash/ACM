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
#define N 500000
typedef long long ll;
using namespace std;
ll a[N], b[N];
int n, m;
ll read(){
	ll p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') 
		ch=='-'?q=-1:0,
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
int main(){
	n=read();
	m=n>>1;
	a[0]=0;a[n+1]=(ll)1000000000*1000000000;
	for (int i=1;i<=m;i++) b[i]=read();
	for (int i=1;i<=m;i++){
		ll l=a[i-1], r=a[n-i+2];
		if (b[i]-l<=r){
			a[i]=l;
			a[n-i+1]=b[i]-l;
		}
		else{
			a[n-i+1]=r;
			a[i]=b[i]-r;
		}
	}
	for (int i=1;i<=n;i++) printf("%I64d ", a[i]);cout<<endl;
	return 0;
}
