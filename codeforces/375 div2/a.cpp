#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
int main(){
	int a, b, c;
	cin>>a>>b>>c;
	if (b>a) swap(a,b);
	if (c>a) swap(c,a);
	if (c>b) swap(c,b);
	cout<<(a-c)<<endl;
	return 0;
}
