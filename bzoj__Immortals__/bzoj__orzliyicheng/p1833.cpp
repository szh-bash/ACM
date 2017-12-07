#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
long long a, b, q[20], f[12][15][12], w[15], ans[15], c[15];
void work(long long x, long long y){
	int l=0;
	if (!x) {ans[0]+=y;return;}
	for (int i=15;i>=0;i--) 
		if (q[i]<=x){
			w[++l]=(x/q[i])%10;
			ans[w[l]]+=(x%q[i]+1)*y;
			c[l]=q[i+1];
		}
	for (int k=1;k<=l;k++)
		for (int i=((k==1 && l>1)?1:0);i<w[k];i++)
			for (int j=0;j<=9;j++)
				ans[j]+=f[i][l-k+1][j]*y;
				
	for (int i=2;i<=l;i++)
		for (int j=(i!=l);j<=9;j++)
			for (int k=0;k<=9;k++)
				ans[k]+=f[j][l-i+1][k]*y;
}
int main(){
	cin>>a>>b;
	q[0]=1;
	for (int i=1;i<=15;i++) q[i]=q[i-1]*10;
	for (int i=1;i<=12;i++)
		for (int j=0;j<=9;j++)
			for (int k=0;k<=9;k++){
				if (k==j)	f[j][i][k]=q[i-1];
				for (int p=0;p<=9;p++)
					f[j][i][k]+=f[p][i-1][k];
			}
	work(a-1,-1);
	work(b,1);
	for (int i=0;i<9;i++) cout<<ans[i]<<' ';cout<<ans[9]<<endl;
	return 0;
}
