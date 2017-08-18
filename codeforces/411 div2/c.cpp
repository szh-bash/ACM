#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
int n;
int main(){
	cin>>n;
	if (n&1){
		cout<<n/2<<endl;
	}
	else{
		cout<<n/2-1<<endl;
	}
	return 0;
}
