#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int main(){
	int T;
	cin>>T;
	while (T--){
		int n;
		cin>>n;
		if (n==4) cout<<"11 4"<<endl;
		else{
			if (n&1) {
				cout<<"7";
				for (int i=2;i<=n-3;i+=2) cout<<1;cout<<' ';
				cout<<"17";
				for (int i=2;i<=n-5;i+=2) cout<<1;cout<<endl;
			}
			else{
				for (int i=2;i<=n;i+=2) cout<<1;cout<<" 77";
				for (int i=2;i<=n-6;i+=2) cout<<1;cout<<endl;
			}
		}
	}
	return 0;
}
