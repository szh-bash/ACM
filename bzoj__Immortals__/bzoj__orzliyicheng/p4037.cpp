#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 510
#define mo 998244353
typedef long long ll;
using namespace std;
int n, m, x[N];
char s[N];
struct qlz{
	int matrix[5][5];
	qlz operator + (const qlz &b){
		qlz B;
		memset(B.matrix,0,sizeof(B.matrix));
		for (int i=0;i<m;i++)
			for (int j=0;j<m;j++)
				B.matrix[i][j]=(matrix[i][j]+b.matrix[i][j])%mo;
		return B;
	}
	qlz operator * (const qlz &b){
		qlz B;
		memset(B.matrix,0,sizeof(B.matrix));
		for (int i=0;i<m;i++)
			for (int j=0;j<m;j++)
				for (int k=0;k<m;k++)
					B.matrix[i][j]=(B.matrix[i][j]+(ll)matrix[i][k]*b.matrix[k][j])%mo;
		return B;
	}
}A, B, zero, dp[N], num[N][10];
qlz modify(qlz k1){
	qlz k2=k1;
	for (int i=1;i<10;i++) k2=k2*k1;
	return k2;
}
int main(){
	scanf("%s%d", s+1, &m);
	n=strlen(s+1);
	for (int i=1;i<=n;i++) x[i]=s[i]-'0';
	for (int i=0;i<m;i++) A.matrix[i][0]=1, zero.matrix[i][i]=1;
	for (int i=1;i<m;i++) A.matrix[i-1][i]=1;
	for (int i=1;i<=n;i++){
		num[i][0]=zero;
		for (int j=1;j<10;j++) num[i][j]=num[i][j-1]*A;
		A=modify(A);
	}
	dp[0]=zero;
	for (int i=1;i<=n;i++){
		A=zero;
		for (int j=i;j;j--){
			A=num[i-j+1][x[j]]*A;
			dp[i]=dp[i]+dp[j-1]*A;
		}
	}
	cout<<dp[n].matrix[0][0]<<endl;
	return 0;
}
