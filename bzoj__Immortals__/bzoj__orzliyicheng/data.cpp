#include <ctime>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	freopen("1.in","w",stdout);
	srand(unsigned(time(NULL)));
	int D=100000;
	int n=250, m=10000, k=10000;
	cout<<n<<' '<<m<<' '<<k<<endl;
	for (int i=1;i<=n;i++) cout<<rand()<<endl;
	for (int i=1;i<=m;i++)
		cout<<rand()%n+1<<' '<<rand()%n+1<<' '<<100000<<endl;
	for (int i=1;i<=k;i++)
		cout<<rand()%n+1<<' '<<rand()%n+1<<endl;
	return 0;
}
