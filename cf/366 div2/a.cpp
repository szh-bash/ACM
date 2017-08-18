#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int flag=1;
	while (n){
		if (n>1){
			if (flag) cout<<"I hate that ";
			else cout<<"I love that ";
			flag^=1;
		}
		else{
			if (flag) cout<<"I hate it"<<endl;
			else cout<<"I love it"<<endl;
		}
		n--;
	}
	return 0;
}
