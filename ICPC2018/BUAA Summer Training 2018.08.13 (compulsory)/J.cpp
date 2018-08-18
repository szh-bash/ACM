#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int x, n, ans, ans1, ans2;
map <int, int> mp;
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
	while (~scanf("%d", &x)){
		mp.clear();
		x*=10000000;
		n=read();
		ans=-1;
		for (int i=1;i<=n;i++){
			int u=read(), v=mp[x-u];
			mp[u]++;
			if (v && abs(x-u-u)>ans) ans=abs(x-u*2), ans1=u, ans2=x-u;
		}
		if (ans<0) printf("danger\n");
		else{
			if (ans1>ans2) swap(ans1,ans2);
			printf("yes %d %d\n", ans1, ans2);
		}
	}
    return 0;
}
