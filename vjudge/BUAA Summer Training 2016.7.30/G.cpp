#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define mo 1000000007
using namespace std;
int n, a , b, f[50001][3];
int main(){
	scanf ("%d%d%d", &n, &a, &b);
	f[0][0]=f[0][1]=1;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=a;j++)
			if (i>=j)
			f[i][1]=(f[i][1]+f[i-j][0])%mo;
		for (int j=1;j<=b;j++)
			if (i>=j)
			f[i][0]=(f[i][0]+f[i-j][1])%mo;
	}
	cout<<(f[n][0]+f[n][1])%mo<<endl;
	return 0;
}
