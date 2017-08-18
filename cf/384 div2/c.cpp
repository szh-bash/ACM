#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
int main(){
	int a;
	cin>>a;
	if (a==1) cout<<"-1"<<endl;
	else 
	cout<<a<<' '<<a+1<<' '<<a*(a+1)<<endl;
	return 0;
}
