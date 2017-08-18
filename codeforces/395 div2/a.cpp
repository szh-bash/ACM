#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int gcd(int a, int b){return b?gcd(b,a%b):a;}
int a, b, c;
int main(){
	cin>>a>>b>>c;
	int gys=a*b/gcd(a,b);
	cout<<(c/gys)<<endl;
	return 0;
}
