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
#define pii pair<int, int>
typedef long long ll;
using namespace std;
int n, a[1<<22];
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
pii f[1<<22];
void add(int mask, int x){
	if (!f[mask].first) f[mask].first=x;
	else if (!f[mask].second) {
		if (x!=f[mask].first){
			f[mask].second=x;
			if (f[mask].first>f[mask].second) swap(f[mask].first, f[mask].second);
		}
	}
	else if (f[mask].second<x){
		f[mask].first=f[mask].second;
		f[mask].second=x;
	}
	else if (f[mask].first<x && f[mask].second!=x)
		f[mask].first=x;
}
void merge(int m0, int m1){
	if (f[m1].first) add(m0, f[m1].first);
	if (f[m1].second) add(m0, f[m1].second);
}
int main(){
	n=read();
	int bits=0;
	for (int i=1;i<=n;i++){
		a[i]=read();
		add(a[i], i);
		if (a[i]) bits=max((int)log2(a[i]), bits);
	}
	bits=1<<(bits+1);
	for (int mask=bits-1;mask;mask--)
		for (int j=1;j<bits;j<<=1)
//	for (int j=1;j<bits;j<<=1)
//		for (int mask=0; mask<bits;mask++)
			if (mask&j) merge(mask^j, mask);
	int ans=0;
	for (int i=1;i<=n;i++){
		int cur=(bits-1)^a[i];
		int w=0;
		for (int j=bits>>1;j;j>>=1)
			if ((cur&j) && f[w^j].second && f[w^j].first>i) 
				w^=j;
		if (f[w].second && f[w].first>i) ans=max(ans, a[i]|w);
	}
	cout<<ans<<endl;
	return 0;
}
