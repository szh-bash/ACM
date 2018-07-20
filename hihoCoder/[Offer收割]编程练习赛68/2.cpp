#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 1000001
#define mo 1000000007
using namespace std;
int n, k, ans;
long f[N+5];
int read(){
	int p=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
int main(){
	k=N;
	f[1]=1; 
	for (int i=1;i<=k;i++)
		for (int j=2;i*j<=N;j++)
			f[i*j]=(f[i*j]+f[i])%mo;
	cout<<f[read()]<<endl;
	return 0;
}
