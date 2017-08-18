#include <ctime>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int main(){
	srand(unsigned(time(NULL)));
	freopen("1.in","w",stdout);
	int n=10000;
	cout<<n<<endl;
	for (int i=1;i<=n;i++) printf("%d ",rand());cout<<endl;
	return 0;
}
