#include <ctime>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int main(){
	srand(unsigned(time(NULL)));
	freopen("tree.in","w",stdout);
	int n=30000, m=30000;
	cout<<n<<' '<<m<<endl;
	for (int i=1;i<=n;i++) printf("%d ", rand());cout<<endl;
	for (int i=2;i<=n;i++) printf("%d %d\n", i, rand()%(i-1)+1);
	/*for (int i=1;i<=m;i++)
		printf("%d %d %d\n", rand()%2, rand()%n+1, rand()%n+1);
	*/ 
	return 0;
}
