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
void solve(){
	int n=read();
	int m=n-n/4;
	if (n%4==0){
		for (int i=1;i<=m;i++) printf("9");
	}
	else{
		for (int i=1;i<m;i++) printf("9");
		printf("8");
	}
	for (int i=1;i<=n/4;i++) printf("8");
	puts("");
}
int main(){
	for (int _=read();_;_--) solve();
	return 0;
}
