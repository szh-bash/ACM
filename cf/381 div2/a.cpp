#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
long long ans, a, b[5], f[5][5];
int main(){
	cin>>a>>b[1]>>b[2]>>b[3];
	a=a%4;
	ans=(long long)1000000000*100000000;
	f[0][0]=f[0][1]=f[0][2]=f[0][3]=ans;
	f[0][a]=0;
	for (int i=1;i<=3;i++){
		for (int j=0;j<=3;j++) f[i][j]=ans;
		for (int j=0;j<=3;j++)
			for (int k=0;k<=3;k++)
				f[i][j]=min(f[i][j],min(f[i][j],f[i-1][(j+4*4-i*k)%4]+k*b[i]));
	}
	cout<<f[3][0]<<endl;
	return 0;
}
