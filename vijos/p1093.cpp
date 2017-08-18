#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, f[10010][5];
int main(){
	scanf("%d", &n);
	f[n][1]=f[n][2]=f[n][3]=f[n][4]=1;
	for (int i=n-1;i>=1;i--){
		f[i][1]=f[i+1][2];
		f[i][4]=f[i+1][3];
		f[i][2]=(f[i+1][1]+f[i+1][3]) % 7654321;
		f[i][3]=(f[i+1][2]+f[i+1][4]) % 7654321;
	}
	cout<<f[1][1]<<endl;
}
