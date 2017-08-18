#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
long long n, m;
long long work(long long x, long long p){
	long long w, y=(x/p)%10;
	w=(x/p/10)*45*p;
	w+=(x%p+1)*y;
	w+=y*(y-1)/2*p;
	return w;
}
int flag(long long l,long long x){
	l--;
	l=0,x=98;
	long long p=1, ans=0, jw=0;
	while (jw || x>=p){
		jw+=work(x,p)-work(l,p);
		jw/=10;
		ans+=jw;
		p*=10;
	}
	cout<<ans<<endl;
	while (1);
	return ans<=m;
}
int main(){
	int T;
	cin>>T;
	while (T--){
		cin>>n>>m;
		long long mid,l=n, r=1000000000;
		while (l<r-1){
			mid=l+r>>1;
			if (flag(n,mid)) l=mid;else r=mid;
		}
		cout<<((long long)(l+n)*(l-n+1)/2)<<endl;
	}
	return 0;
}
