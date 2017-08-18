#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int main(){
	int n, flag=0;
	cin>>n;
	for (int i=1;i<=n;i++){
		int x;
		scanf("%d", &x);
		flag^=(x+1)&1;
		if (flag) cout<<1<<endl;else cout<<2<<endl;
	}
	return 0;
}
