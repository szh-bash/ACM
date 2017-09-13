#include <ctime>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int main(){
	srand(unsigned(time(NULL)));
	freopen("1.in","w",stdout);
	int n=5, m=5;
	cout<<n<<' '<<m<<endl;
	for (int i=1;i<=n;i++) printf("%d ", rand());cout<<endl;
	for (int i=2;i<=n;i++) printf("%d %d\n", i, rand()%(i-1)+1);
	for (int i=1;i<=m;i++)
		printf("%d %d %d\n", rand()%2, rand()%n+1, rand()%n+1);
	return 0;
}
5 5
1 2 3 4 5
2 1
3 1
4 1
5 3
1 3 4
0 1 1
1 3 3
0 4 4
1 4 4
