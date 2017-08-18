#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a=2, b=0;
	for (int i=1;i<=n;i++){
		if (a){
			cout<<'a';
			a--;
			if (!a) b=2;
			continue;
		}
		if (b){
			cout<<'b';
			b--;
			if (!b) a=2;
			continue;
		}
	}
	return 0;
}
