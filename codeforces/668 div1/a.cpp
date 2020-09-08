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
#define N 300005
int n, k;
char s[N];
void solve(){
	n=read();k=read();
	scanf("%s", s+1);
	int s0=0, s1=0, s2=0;
	for (int i=1;i<=k;i++)
		if (s[i]=='0') s0++;
		else if (s[i]=='1') s1++;
		else s2++;
	if (max(s0,s1)-min(s0,s1)>s2){
		puts("NO");
		return;
	}
	if (abs(s0-s1)==s2){
		char ch=s0>s1?'1':'0';
		for (int i=1;i<=k;i++)
			if (s[i]=='?') s[i]=ch;
		s2=0;
	}
	for (int i=k+1;i<=n;i++){
		int u=s[i]=='?'?2:s[i]-'0';
		int v=s[i-k]=='?'?2:s[i-k]-'0';
		if (!u){
			if (u==v) continue;
			else if (v==1 || s0-s1==s2){
				puts("NO");
				return;
			}
			s0++;
		}
		else if (u==1){
			if (u==v) continue;
			else if (!v || s1-s0==s2){
				puts("NO");
				return;
			}
			s1++;
		}
		else{
			s[i]=s[i-k];
			continue;
		}
		if (!v) s0--;
		else if (v==1) s1--;
		else s2--;
	}
	puts("YES");
}
int main(){
	for (int _=read();_;_--) solve();
	return 0;
}
