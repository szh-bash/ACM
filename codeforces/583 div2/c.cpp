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
#define N 300000
char s[N];
int main(){
	int n=read();
	scanf("%s", s+1);
	int ct=0, lc=0;
	for (int i=1;i<=n;i++)
		if (s[i]=='('){
			ct++;
		}
		else{
			if (ct) ct--;
			else lc++;
		}
	if (!ct && !lc || lc==1 && ct==1){
		puts("Yes");
		return 0;
	}
	puts("No");
	return 0;
}
