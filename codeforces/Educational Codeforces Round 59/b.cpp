#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') 
		ch=='-'?q=-1:0,
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
int s(int x){
	if (x<10) return x;
	int p=0;
	while (x){
		p+=x%10;
		x/=10;
	}
	return s(p);
}
int main(){
	for (int _=read();_;_--){
		ll k;
		cin>>k;
		int x=read();
		ll ans=(k-1)*9+x;
		cout<<ans<<endl;
	}
	return 0;
}
