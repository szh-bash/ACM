#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
long long a, b, x, y, z;
int main(){
	cin>>a>>b;
	cin>>x>>y>>z;
	a-=2*x+y;
	b-=z*3+y;
	if (a>0) a=0;else a=-a;
	if (b>0) b=0;else b=-b;
	cout<<a+b<<endl;
	return 0;
}
