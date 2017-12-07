#include<cstdio>
#include <cstring>
#include<cstdlib>
#include <iostream>
using namespace std;
bool cmp(int a, int b){
	return (x[a]<x[b] || ((x[a]==x[b])&&(y[a]<y[b])))
}
int main(){
	scanf("%d%d", &c, &n);
	for (int i=1;i<=n;i++) scanf("%d%d", &x[i], &y[i]), z[i]=i;
	sort(z+1,z+1+n,cmp);
	
	return 0;
}
