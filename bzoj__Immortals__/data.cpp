#include <ctime>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int main(){
	srand(unsigned(time(NULL)));
	freopen("1.in","w",stdout);
	int T=1, n=100000, m=100000;
	while (T--){
		cout<<n<<' '<<m<<endl;
		for (int i=1;i<=n;i++) printf("%d ", rand()+1);cout<<endl;
		for (int i=1;i<=m;i++) printf("%d %d\n", rand()+1, rand()+1);
	}
	return 0;
}
