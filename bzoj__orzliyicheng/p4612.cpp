#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define q (long long)1000000000*1000000000
using namespace std;
long long ans, y, l;
long long f(long long b, long long x){
	long long p=0, c=1;
	while (x){
		p+=(x%10)*c;
		c*=b;
		x/=10;
	}
	return p;
}
bool check(int b){
	if (f(b,l)>y) return 0;
	long long x=y;
	while (x){
		if (x%b>9) return 0;
		x/=b;
	}
	return 1;
}
long long min(long long a, long long b){return b<a?b:a;}
long long max(long long a, long long b){return a<b?b:a;}
int main(){
	cin>>y>>l;
	for (int b=1000000;b>=10;b--)
		if (check(b)){
			ans=b;
			break;
		}
	for (long long i=l;i<=min(y-1,1000);i++){
		long long le=1000000, ri=(long long)1000000000*1000000000;
		while (le<ri-1){
			long long mid=le+ri>>1;
			if (f(mid,i)<y) le=mid;else ri=mid;
		}
		if (f(ri,i)==y) ans=max(ans,ri);
	}
	cout<<ans<<endl;
	return 0;
}
