#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;
int flag[10000];
int main(){
	freopen("data.in","w",stdout);
	srand(unsigned(time(NULL)));
	int n=rand()%5+5;
	cout<<n<<endl;
	for (int i=1;i<n;i++)
		cout<<i+1<<' '<<rand()%i+1<<' '<<rand()+1<<endl;
	int k=rand()%10+1;
	cout<<k<<endl;
	for (int i=1;i<=k;i++){
		int m=rand()%(n-1)+1;
		cout<<m;
		for (int j=2;j<=n;j++) flag[j]=1;
		for (int j=1;j<=m;j++){
			int x=rand()%n+1;
			while (!flag[x]) x=rand()%n+1;
			flag[x]=0;
			cout<<' '<<x;
		}
		cout<<endl;
	}
	return 0;
}
