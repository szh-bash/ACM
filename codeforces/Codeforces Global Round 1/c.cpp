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
typedef long long ll;
using namespace std;
int ans[]={
0,0,
1,
1,
5,
1,
21,
1,
85,
73,
341,
89,
1365,
1,
5461,
4681,
21845,
1,
87381,
1,
349525,
299593,
1398101,
178481,
5592405,
1082401};
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') 
		ch=='-'?q=-1:0,
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
int gcd(int a, int b){return !b?a:gcd(b,a%b);}
int main(){
/*	for (int k=2, p=3;k<=25;k++){
		for (int j=1;j<p;j++)
			if (gcd(p&j,p^j)>ans[k]) ans[k]=gcd(p&j,p^j);
		p+=1<<k;
		cout<<ans[k]<<endl;
	}*/
	for (int _=read();_;_--){
		int x=read(), y=0, z, j=0;
		for (;(1<<j)<=x;j++)
			y|=1<<j;
		z=y^x;
		if (!z){
			printf("%d\n", ans[j]);
		}
		else{
			printf("%d\n",y);
		}
	}
	return 0;
}
