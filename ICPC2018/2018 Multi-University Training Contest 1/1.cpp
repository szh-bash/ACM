#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
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
	for (int T=read();T;T--){
		int n=read();
		if (n%3==0){
			ll v=n/3;
			printf("%lld\n", v*v*v);
			continue;
		}
		if (n%4){
			printf("-1\n");
			continue;
		}
		ll v=n/2;
		printf("%lld\n", v*v*v/4);
	}
    return 0;
}
