#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
long long k, p=1;
int n;
void work(int l, int r, int k){
	
}
int main(){
	cin>>n>>k;
	n--;
	for (int i=1;i<=n;i++) p=p*2+1;
	while (n){
		if (k*2-1==p) break;
		else
			if (k*2>p) k-=p/2+1;
		p/=2;
		n--;
	}
	cout<<n+1<<endl;
	return 0;
}
