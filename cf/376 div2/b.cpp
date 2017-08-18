#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, flag;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		int x;
		scanf("%d", &x);
		x-=flag;
		if (x<0){cout<<"NO"<<endl;return 0;}
		flag=x&1;
	}
	if (flag) cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
	return 0;
}
