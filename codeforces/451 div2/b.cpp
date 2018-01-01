#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;
int n, a, b;
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
	n=read(), a=read(), b=read();
	for (int i=0;a*i<=n;i++){
		if (((n-a*i)%b)==0) {
			cout<<"YES"<<endl;
			cout<<i<<' '<<(n-a*i)/b<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}
