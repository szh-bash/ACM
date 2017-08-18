#include <ctime>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int main(){
	freopen("1.in","w",stdout);
	srand(unsigned(time(NULL)));
	int T=1;
	cout<<T<<endl;  
	while (T--){
		int n=2090000,k=rand()%n+1;
		cout<<k<<' '<<n<<endl;
		for (int i=1;i<=n;i++){
			int m=rand()%10+1;
			for (int j=1;j<=m;j++)
				printf("%c", char(33+rand()%90));
			printf("\n");
		}
	}
	return 0;
}
