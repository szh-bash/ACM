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
typedef long long ll;
using namespace std;
ll n, cnt, f[2000000], ans[2000000];
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
	n=read();
	for (ll i=1;i*i<=n;i++)
		if (n%i==0){
			f[++cnt]=(n/i)+i*(n/i-1)*(n/i)/2;
			i=n/i;
			f[++cnt]=(n/i)+i*(n/i-1)*(n/i)/2;
			i=n/i;
			if (i*i==n) cnt--;
		}
/*	int ct=0;
	for (int i=1;i<=cnt;i+=2) ans[++ct]=f[i];
	for (int i=cnt-(cnt&1);i;i-=2) ans[++ct]=f[i];*/
	sort(f+1,f+1+cnt);
	for (int i=1;i<=cnt;i++) printf("%I64d ",f[i]);
	//for (int i=ct;i;i--) printf("%I64d ",ans[i]);
	return 0;
}
