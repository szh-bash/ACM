#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 200000
#define INF 1000000500
using namespace std;
int n, m, a[N], b[N], pia, pib, paa, pab;
long long mia, mib, maa, mab, ans;
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') 
		(ch=='-'?q=-1:0),
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
int main(){
	for (int T=read(), j=1;T;T--, j++){
		
		printf("Case #%d: %lld\n", j, ans);
	}
	return 0;
}

