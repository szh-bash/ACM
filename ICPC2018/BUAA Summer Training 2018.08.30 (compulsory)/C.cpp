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
#include <tr1/unordered_map>
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int k, n, a[20000], f[20000];
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
	while (~scanf("%d%d", &k, &n)){
		memset(f,0,sizeof(f));
		for (int i=1;i<=n;i++) a[i]=read(), f[a[i]]++;
		int mi=n+1, ma=0, pi=0, ti=0, pa=0, ta=0;
		for (int i=1;i<=k;i++){
			if (f[i]<mi) 
				mi=f[i],
				pi=i,
				ti=1;
			else
				if (f[i]==mi) ti++;
			if (f[i]>ma)
				ma=f[i],
				pa=i,
				ta=1;
			else
				if (f[i]==ma) ta++;
		}
		if (ma==mi+1 && ta==1){
			printf("-%d\n", pa);
			continue;
		}
		if (ma==mi+1 && ti==1){
			printf("+%d\n", pi);
			continue;
		}
		if (ma==mi+2 && ti==1 && ta==1){
			printf("-%d +%d\n", pa, pi);
			continue;
		}
		printf("*\n");
	}
    return 0;
}
