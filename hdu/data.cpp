#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int main(){
	freopen("1.in","w",stdout);
	int n=5;
	cout<<n<<endl;
	for (int i=1;i<=n;i++){
		int x1=rand()%3, y1=rand()%3;
		int x2=rand()%3+1, y2=rand()%3+1;
		cout<<x1<<' '<<y1<<' '<<x2+x1<<' '<<y1+y2<<endl;
	}
	return 0;
}
