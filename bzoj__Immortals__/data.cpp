#include <ctime>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int main(){
	srand(unsigned(time(NULL)));
	freopen("1.in","w",stdout);
	int T=1, n=500000, m=500000;
	while (T--){
		cout<<n<<' '<<m<<endl;
		for (int i=1;i<=n;i++)
			printf("%d %d\n", rand(), rand());
		for (int i=1;i<=m;i++){
			int u=rand()+1, v=rand()+1;
			printf("%d %d %d %d\n", u, v, rand()%u, rand()%v);
		}
	}
	return 0;
}
