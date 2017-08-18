#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main(){
	int n;
	scanf("%d", &n);
	cout<<n*(n-1)/2<<endl;
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++){
			if (j-i>n-(j-i))
				printf("%d %d %d\n", i, j, (i+(n-(j-i))-1)%n+1);
			else
				printf("%d %d %d\n", i, j, (j*2-i-1)%n+1);
		}
	return 0;
}
