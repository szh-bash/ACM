#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
long long n, m;
int a[100], ans;
int main(){
	int T;
	cin>>T;
	int c[10];c[1] = 4; c[2] = 3; c[3] = 5;
c[4] = 6; c[5] = 4; c[6] = 6;
c[7] = 5; c[8] = 4; c[9] = 3;
	while (T--){
		double x;
		ans=0;
		for (int i=1;i<=9;i++){
			for (int j=1;j<=c[i];j++)
				cin>>a[j];
			for (int j=1;j<=c[i];j++){
				cin>>x;
				if (x+0.00001<3) a[j]=0;
			}
			for (int j=1;j<=c[i];j++){
				cin>>x;
				if (x+0.00001<3) a[j]=0;
			}
			for (int j=1;j<=c[i];j++)
				ans+=a[j];
		}
		cout<<ans<<endl;
	}
	return 0;
}
