#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, m, ans, a[1010][1010], f[1010][1010][5];
bool read(){
	char ch=getchar();
	while (ch!='0' && ch!='1') ch=getchar();
	return ch-'0';
}
int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			a[i][j]=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			f[i][j][0]=f[i][j-1][0] | a[i][j-1],
			f[i][j][1]=f[i-1][j][1] | a[i-1][j];
	for (int i=n;i;i--)
		for (int j=m;j;j--)
			f[i][j][2]=f[i][j+1][2] | a[i][j+1],
			f[i][j][3]=f[i+1][j][3] | a[i+1][j];
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (!a[i][j])
				for (int k=0;k<=3;k++)
					ans+=f[i][j][k];
	cout<<ans<<endl;
	return 0;
}

