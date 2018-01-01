#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <bitset>
#include <cstring>
#include <cstdlib>
#include <complex>
#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;
int f[2000];
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9')
		(ch=='-'?q=-1:0),
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
int main(){
	//k1=read();k2=read();k3=read();
	f[read()]++; 
	f[read()]++; 
	f[read()]++; 
	if (f[1] || (f[2]>1) || (f[3]>2) || (f[2]==1 && f[4]==2)) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
