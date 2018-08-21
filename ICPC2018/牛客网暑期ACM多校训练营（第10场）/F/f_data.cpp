#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <tr1/unordered_map>
#define INF 1000000000
#define N 505
#define M 500*500+500
#define mo 998244353
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
using namespace std::tr1;
int n, a[1000][1000];
int main(){
	freopen("f.in","w",stdout);
	srand(unsigned(time(NULL)));
	int t=3;
	cout<<t<<endl;
	while (t--){
		//n=rand()%1+4;
		n=500;
		cout<<n<<endl;
		for (int i=1;i<=n;i++){
			a[i][i]=0;
			for (int j=i+1;j<=n;j++)
				a[i][j]=a[j][i]=rand()%10000+999990000;
			for (int j=1;j<=n;j++)
				printf("%d ", a[i][j]);
			cout<<endl;
		}
	}
	return 0;
}
