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
#define N 200
int a[N];
char s[N];
void solve(){
	scanf("%s", s);
	int sum=0, cnt=0;
	for (int i=0;s[i];i++)
		if (s[i]=='0'){
			if (sum) a[++cnt]=sum, sum=0;
		}
		else sum++;
	if (sum) a[++cnt]=sum;
	sort(a+1, a+1+cnt);
	int ans=0;
	for (int i=1;i<=cnt;i+=2) ans+=a[cnt-i+1];
	printf("%d\n", ans);
}
int main(){
	for (int _=read();_;_--) solve();
	return 0;
}
