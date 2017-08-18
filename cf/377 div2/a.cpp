#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
using namespace std;
int main(){
	int r, k;
	cin>>r>>k;
	for (int i=1;i<=10;i++)
		if ((i*r%10==k) || (i*r%10==0)){
			cout<<i<<endl;
			return 0;
		}
	return 0;
}
