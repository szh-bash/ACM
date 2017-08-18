#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define eps 1e-5
#define N 200000
#define M 6000000
typedef long long ll;
using namespace std;
int n, m, id, hash[M], sg[2][N];
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
int next(int x, int y){
	return y==x?x+1:y/(y/(x+1));
}
void pre(){
	for (int i=1;i<=n;i=next(i,n)){
		int t=0, u=1;
		hash[0]=++id;
		for (int j=2;j<=i;u=j,j=next(j,i)){
			t^=(i/j>m)?sg[1][n/(i/j)]:sg[0][i/j];
			hash[t]=id;
			if (!((j-u)&1)) t^=(i/j>m)?sg[1][n/(i/j)]:sg[0][i/j];
		}
		for (int j=0;;j++)
			if (hash[j]!=id){
				if (i>m) sg[1][n/i]=j;
				else sg[0][i]=j;
				break;
			}
	}
}
int main(){
	n=read();m=sqrt(n);
	pre();
	for (int T=read();T;T--){
		int ans=0;
		for (int q=read();q;q--){
			int x=n/read();
			if (x>m) ans^=sg[1][n/x];else ans^=sg[0][x];
		}
		if (ans) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
