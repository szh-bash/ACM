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
#define mo 1000000007
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
int power(ll a, int b){
	ll c=1;
	while (b){
		if (b&1) c=c*a%mo;
		a=a*a%mo;
		b>>=1;
	}
	return c;
}
int n, m;
char s[200];
void solve(){
	n=read(), m=read();
	for (int i=1;i<=m;i++) s[i]='B';
	s[m+1]='\0';
	for (int i=1;i<=n;i++){
		int x=read();
		if (x>m+1-x) x = m+1-x;
		if (s[x]=='A') s[m+1-x]='A';
		else s[x]='A';
	}
	printf("%s\n", s+1);
}
int main(){
	for (int _=read();_;_--) solve();
	return 0;
}
