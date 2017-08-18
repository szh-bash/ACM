#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
long long n, m;
int main(){
	int T;
	cin>>T;
	while (T--){
		cin>>m>>n;
		while (n--){
			m=m*2+1;
		}
		cout<<m<<endl;
	}
	return 0;
}
