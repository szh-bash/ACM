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
#define N 3000000
char s[N];
int nxt[N];
int solve(){
	scanf("%s", s);
	int ls=strlen(s);
	for (int i=0;i<ls/2;i++)
		swap(s[i], s[ls-i-1]);
	int p=ls;
	for (int i=ls-1;i>=0;i--)
		if (s[i]=='1') 
			nxt[i]=p,
			p=i;
		else nxt[i]=p;

	int ans=0;
	for (int i=0;i<ls;i++)
		for (int j=i, p=0;j<ls && j-i<30;j=nxt[j]){
			p=p+(s[j]-'0')*(1<<(j-i));
			if (j-i+1<=p && nxt[j]-i>=p) ans++;
		}
	return ans;
}
int main(){
	for (int _=read();_;_--)
		cout<<solve()<<endl;
	return 0;
}
