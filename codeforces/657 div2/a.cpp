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
int n, f[100000];
char s[100000];
char s0[]={'a','b','a','c','a','b','a'};
char err[]={'c','a','b','a'};
void solve(){
	n=read();
	scanf("%s", s);
	int sum=0;
	for (int i=0;i+7<=n;i++){
		int flag=1;
		for (int j=0;j<7;j++)
			if (s[i+j]!=s0[j]) flag=0;
		sum+=flag;
	}
	if (sum>1) {puts("No");return;}
	if (sum==1){
		puts("Yes");
		for (int i=0;i<n;i++) 
			if (s[i]=='?') s[i]='z';
		printf("%s\n", s);
		return;
	}
	for (int i=0;i<n;i++) f[i]=1;
	for (int i=1;i+4<=n;i++){
		int flag=0;
		for (int j=0;j<4;j++)
			if (s[i+j]!=err[j]) flag=1;
		f[i-1]=flag;
	}
	for (int i=0;i+7<=n;i++){
		int flag=1;
		for (int j=0;j<7;j++)
			if (s[i+j]!=s0[j] && s[i+j]!='?') flag=0;
		if (flag && f[i+7-1]){
			puts("Yes");
			for (int j=0;j<7;j++) s[i+j]=s0[j];
			for (int j=0;j<n;j++) 
				if (s[j]=='?') s[j]='z';
			printf("%s\n",s);
			return;
		}
	}
	puts("No");
}
int main(){
	for (int _=read();_;_--) solve();
	return 0;
}
