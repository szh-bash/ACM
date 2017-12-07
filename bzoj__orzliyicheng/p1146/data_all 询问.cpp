#include <ctime>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int read(){
	int p=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
int main(){
	srand(unsigned(time(NULL)));
	freopen("tree.in","r",stdin);
	freopen("data_0.in","w",stdout);
	int n=read(), m=read();
	cout<<n<<' '<<m<<endl;
	for (int i=1;i<=n;i++) printf("%d ", rand());cout<<endl;
	for (int i=2;i<=n;i++) printf("%d %d\n", i, rand()%(i-1)+1);
	for (int i=1;i<=m;i++)
		printf("%d %d %d\n", 0, rand()%n+1, rand()%n+1);
	return 0;
}
