#include <map>
#include <set> 
#include <ctime>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <tr1/unordered_map>
typedef long long ll;
using namespace std;
using namespace std::tr1;
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=='-'?q=-1:0, ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
ll readll(){
	ll p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=='-'?q=-1:0, ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
#define M 200000
ll n;
int m;
int bit[200];
int a[M];
unordered_map <int, int> lg;
int solve(){
	cin>>n; m=read();
	for (int i=0;i<100;i++) bit[i]=0;
	ll sum=0;
	int ma = 0;
	for (int i=1;i<=m;i++) a[i]=read(), sum+=a[i], bit[lg[a[i]]]++, ma = max(ma, lg[a[i]]);
	if (sum<n) return -1;
	int lim=0;
	for (int i=0;n;i++){
		bit[i] -= n & 1;
		n >>= 1;
		lim++;
	}
	lim = max(lim, ma+1);
	int ans = 0;
	int le = lim;
	for (int i=0;i<lim;i++)
		if (bit[i]<0) le = min(le, i);
		else if (bit[i]>0){
			if (le<i) ans+=(i-le), bit[i]--, le=lim;
			bit[i+1]+=bit[i] >> 1;
		}
	return ans;
}
int main(){
	for (int i=1, j=0;i<=1000000000;i<<=1, j++) lg[i]=j;
	for (int _=read();_;_--) printf("%d\n", solve());
	return 0;
}
