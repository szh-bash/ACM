#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int main(){
	long long n, m;
	double e=2.718281828459045, C=0.57721566490153286060651209;
	cin>>n>>m;
	if (n>5000000)cout<<(int)((log(n)/log(e)+C)*m/2-0.00001)<<endl;
	else{
		double ans=0;
		for (int i=1;i<=n;i++) ans+=(double)1/i;
		cout<<(int)(ans*m/2-0.00001)<<endl;
	}
	return 0;
}
