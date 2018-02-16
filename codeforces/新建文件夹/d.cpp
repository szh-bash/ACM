#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
typedef unsigned long long ll;
using namespace std;

int main(){
	cin>>k>>p;
	int t=-1, cnt=1;
	while (abs(p)>=k){
		a[cnt]+=p%k;
		p/=k;
		a[++cnt]+=(p*=t);
		t=-t;
	}
	if (p<0) ans[cnt]+=k, ans[++cnt]=1;
	if (p>0) 
	return 0;
}
