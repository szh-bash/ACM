#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
double e=exp(1), pi=acos(-1), eps=0.000001;
int n, k;
int main(){
    cout<<e<<' '<<pi<<endl;
	while (scanf("%d%d", &n, &k)!=EOF){
		double ans=0;
		if (n<=10000){
			for (int i=1;i<=n;i++) ans+=log(i)/log(k);
			ans+=eps+1;
            printf("%lld\n", (long long)ans);
		}
		else{
		    printf("%lld\n", (long long)(1+0.5*log(2*pi*n)/log(k)+n*log(n)/log(k)-n*log(e)/log(k)));
		}
	}
	return 0;
}
