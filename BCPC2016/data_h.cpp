#include <ctime>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
char a[1010][1010];
int main(){
	freopen("h.in","w",stdout);
	srand(unsigned(time(NULL)));
	int T=2;
	cout<<T<<endl;  
	while (T--){
		int n=rand()%25,m;
		if (n&1==0) n++;
		m=2*n+1;
		cout<<n<<' '<<m<<endl;
		for (int i=1;i<=n;i++){
			for (int j=n-i+1;j;j--)
				a[i][j]='0',a[i][2*n+2-j]='0';
			for (int j=1;j<=i;j++)
				a[i][n+1+j-1]=a[i][n+1-j+1]='1';
		}
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++) printf("%c", a[i][j]);
			printf("\n");
		}
	}
	return 0;
}
