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
char s[200];
int solve(){
	scanf("%s", s);
	int le=200, ri=-1, count=0;
	for (int i=0;s[i]!='\0';i++)
		if (s[i]=='1'){
			count ++;
			le = min(le, i);
			ri = max(ri, i);
		}
	if (!count) return 0;
	return ri-le+1-count;
}
int main(){
	for (int _=read();_;_--) printf("%d\n", solve());
	return 0;
}
