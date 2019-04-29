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
#include <tr1/unordered_map>
#define N 200000
#define M 2000000
#define mo 1000000007
#define INF N
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int n, m;
int main(){
	srand(unsigned(time(NULL)));
	freopen("b.in","w",stdout);
	n=10;m=100;
	cout<<n<<' '<<m<<' '<<endl;
	for (int i=1;i<=m;i++){
		cout<<rand()%n+1<<' '<<rand()%n+1<<endl;
	}
	return 0;
}
