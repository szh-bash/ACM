#include <map>
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
int n;
char s[100], ts[100];
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') 
		ch=='-'?q=-1:0,
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
void solve(){
	n=read();
	scanf("%s", s);
	strcpy(ts,s);
	sort(ts,ts+n);
	int ans=n;
	for (int i=0;i<n;i++)
		if (ts[i]==s[i]) ans--;
	printf("%d\n", ans);
}
int main(){
	for (int _=read();_;_--) solve();
	return 0;
}
