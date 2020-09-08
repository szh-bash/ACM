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
typedef long long ll;
using namespace std;
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
int a[200000];
void solve(){
	int n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int j=1<<30;j;j>>=1){
		int sum=0;
		for (int i=1;i<=n;i++)
			if (a[i]&j) sum++;
		if (sum&1){
			if ((sum>>1)&1){
				// 2 1
				if ((n-sum)&1) puts("WIN");
				else puts("LOSE");
			}
			else{
				// 3 2
				puts("WIN");
			}
			return;
		}
	}
	puts("DRAW");
}
int main(){
	for (int _=read();_;_--) solve();
	return 0;
}
