#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 6
#define M 200000
#define INF 999999999
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int main(){
	freopen("f.in","w",stdout);
	srand(unsigned(time(NULL)));
	int n=4;
	cout<<n<<endl;
	for (int i=1;i<=n;i++){
		int len=rand()%1000+1;
		for (int j=1;j<=len;j++) printf("%c",(char)(rand()%2+'a'));cout<<endl;
	}
	for (int i=1;i<=10000;i++){
		int x=rand()%4;
		if (x) printf("%c",(char)(rand()%2+'a'));
		else printf("-");
	}
	cout<<endl;
	return 0;
}
