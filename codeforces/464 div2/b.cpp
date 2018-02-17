#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
int main(){
	cin>>n;
	if (n>36) cout<<-1<<endl;
	else {
		while (n>1){
			cout<<8;
			n-=2;
		}
		if (n) cout<<6<<endl;
	}
	return 0;
}
