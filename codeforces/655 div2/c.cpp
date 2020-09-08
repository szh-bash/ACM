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
int n;
void solve(){
	n=read();
	int flag=0, ct=0;
	for (int i=1;i<=n;i++){
		int v=read()!=i;
		if (v && !flag) flag=1, ct++;
		if (!v) flag=0;
	}
	if (!ct) cout<<0<<endl;
	else if (ct==1) cout<<1<<endl;
	else cout<<2<<endl;	
}
int main(){
	for (int _=read();_;_--) solve();
	return 0;
}
