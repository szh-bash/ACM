#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 200000
#define mo 998244353 
typedef long long ll;
using namespace std;
int n, k, len, a[N], f[2][N];
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') 
		ch=='-'?q=-1:0,
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
int sub(int x, int y){
	x-=y;
	if (x<0) x+=mo;
	return x;
}
int add(int x, int y){
	x+=y;
	if (x>=mo) x-=mo;
	return x;
}
int main(){
	n=read();k=read();len=read();
	for (int i=1;i<=n;i++) a[i]=read();
	int presum=1;
	for (int i=1, o=0;i<=n;i++, o^=1){
		int sum=0;
		if (a[i]==-1){
			for (int j=1;j<=k;j++)
				f[o][j]=sub(presum,f[o^1][j]),
				sum=add(sum,f[o][j]);
		}
		else{
			for (int j=1;j<=k;j++)
				if (a[i]!=j) f[o][j]=0;
				else f[o][j]=sub(presum,f[o^1][j]), sum=f[o][j];
		}
		presum=sum;
	}
	cout<<presum<<endl;
	return 0;
}
