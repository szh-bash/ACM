#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
long long n, m;
int main(){
	cin>>n;
	m=2;
	for (long long i=1;i<=n;i++){
		m=(i+1)*(i+1)*i-m/i;
		printf("%I64d\n", m);
		m=i*(i+1);
	}
	return 0;
}
