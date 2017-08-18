#include <map>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define LL long long
using namespace std;
map<int, int>mp;
int p, b, n;
int power(LL a, int b){
	LL c=1;
	while (b){
		if (b&1) c=c*a%p;
		a=a*a%p;
		b/=2;
	}
	return c%p;
}
void exgcd(int a, int b, int &x, int &y){
	if (!b){
		x=1;
		y=0;
		return;
	}
	exgcd(b,a%b,x,y);
	LL t=x;
	x=y;
	y=t-a/b*y;
	//cout<<a<<' '<<b<<' '<<x<<' '<<y<<endl;
}
int main(){
	while (scanf("%d%d%d",&p, &b, &n)!=EOF){
		if (n==1){cout<<0<<endl;continue;}
		if (b%p==0 && n) {cout<<"no solution"<<endl;continue;}
		mp.clear();
		int sq=1+floor(sqrt(p));
		int D=power(b,sq),tmp=1,y,x,flag=0;
		for (int i=1;i<=sq;i++)
			tmp=(LL)tmp*b%p,mp[tmp]=mp[tmp]?mp[tmp]:i;
		tmp=1;
		for (int i=0;i<=sq;i++){
			x=(LL)power(tmp,p-2)*n%p;
			if (mp[x] || x==1){
				flag=1;
				cout<<i*sq+mp[x]<<endl;
				break;
			}
			tmp=(LL)tmp*D%p;
		}
		if (!flag) cout<<"no solution"<<endl;
	}
	return 0;
}
