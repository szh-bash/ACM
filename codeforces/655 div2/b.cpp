#include <map>
#include <set> 
#include <ctime>
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
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=='-'?q=-1:0, ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
ll readll(){
	ll p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=='-'?q=-1:0, ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
int main(){
	for (int _=read();_;_--){
		int n=read();
		if (n&1){
			int flag=0;
			for (int i=2;i*i<=n;i++)
				if (i*(n/i)==n){
					cout<<n/i<<' '<<n-n/i<<endl;
					flag=1;
					break;
				}
			if (!flag) cout<<1<<' '<<n-1<<endl;
		}
		else cout<<n/2<<' '<<n/2<<endl;
	}
	return 0;
}
