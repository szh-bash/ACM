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
int n, m, k, h[200];
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
void solve(){
	n=read();m=read();k=read();
	for (int i=1;i<=n;i++) h[i]=read();
	int flag=1;
	for (int i=1;i<n;i++){
		if (h[i]<h[i+1]-k){
			if (h[i]+m<h[i+1]-k){
				flag=0;
				break;
			}
			else m-=h[i+1]-k-h[i];
		}
		else {
			m+=h[i]-max(0,h[i+1]-k);
		}
	}
	if (flag) puts("YES");else puts("NO");
}
int main(){
	for (int _=read();_;_--) solve();
	return 0;
}
