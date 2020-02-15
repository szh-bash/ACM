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
int solve(){
	scanf("%s%s", s, t);
	int i, j;
	for (i=0, j=0;s[i] && t[j];i++)
		if (s[i]==t[j]) j++;
	if (!t[j]) return 1;
//	for (int k=0;t[k] && t[k+1];k++){
//		
//	}
	return 0;
}
int main(){
	for (int _=read();_;_--) puts(solve()?"YES":"NO");
	return 0;
}
