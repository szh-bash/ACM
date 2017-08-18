#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
bool cmp(int a, int b){
	
}
int main(){
	scanf("%d%d", &n, &A);
	for (int i=1;i<=n;i++) scanf("%d%d", &x[i], &y[i]);
	sort(x+1,x+1+n,cmp);
	for (int i=1;i<=n;i++)
		if (x[i]!=x[i-1]) x[++cnt]=x[i], y[cnt]=i;
	n=cnt;
	for (int i=n;i;i--)
		for (int j=i;j<=n;j++)
			for (int k=)
	return 0;
}
