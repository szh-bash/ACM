#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
char s[2000][2000];
int a[2000][2000], n, sum1[2000], sum2[2000], ans1, ans2;
int main(){
	scanf("%d", &n);
	for (int i=1;i<=n;i++){
		scanf("%s", s[i]);
		for (int j=1;j<=n;j++)
			a[i][j]=s[i][j-1]-'0';
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++){
			sum1[i]^=a[i][j];
			sum2[j]^=a[i][j];
		}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			ans1+=sum1[i]^sum2[j]^a[i][j],
			ans2+=sum1[i]^sum2[j]^a[i][j]^1;
	cout<<min(ans1,ans2)<<endl;
	return 0;
}
