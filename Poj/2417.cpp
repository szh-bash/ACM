#include <map>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
map<int, int> f;
int b, n, m, p;
int power(int a, int b){
	int tmp=1; 
	while (b){
		if (b%2) tmp=(long long)a*tmp%p;
		a=(long long)a*a%p;
		b/=2;
	}
	return tmp;
}

int main(){
	while (scanf("%d%d%d", &p, &b, &n)!=EOF){
		f.clear();
		m=ceil(sqrt(p));
		f[1]=0;
		long long tmp=1;
		for (int i=1;i<=m;i++){
			tmp=tmp*b%p;
			if (tmp==1 || f[tmp]) break;
		    f[tmp]=i;
		}
		tmp=power(power(b,p-2),m);
		int ff=1, tp=1;
		for (int i=1;i<=m;i++){
			if (f[tp*n%p] || tp*n%p==1){
				printf("%d\n", f[tp*n%p]+(i-1)*m);
				ff=0;
				break;
			}
			tp=tmp*tp%p;
		}
		if (ff) printf("%s\n", "no solution");
	}
	return 0;
}
/*ÎÒ²ÝÕâ¹·Ìâ*/ 
