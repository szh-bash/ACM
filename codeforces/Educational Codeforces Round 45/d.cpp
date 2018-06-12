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
int n, a, b;
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') 
		ch=='-'?q=-1:0,
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
int main(){
	n=read(), a=read(), b=read();
	if (a>1 && b>1 || a==1 && b==1 && n<=3 && n>1){
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	if (a==1 && b==1){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				if (i==j) {printf("0");continue;}
				if (i==j+1 || i+1==j) printf("1");
				else printf("0");
			}
			printf("\n");
		}
		return 0;
	}
	if (a==1){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				if (i==j) {printf("0");continue;}
				if (i<b || j<b) printf("1");
				else printf("0");
			}
			printf("\n");
		}
	}
	else{
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				if (i==j) {printf("0");continue;}
				if (i<a || j<a) printf("0");
				else printf("1");
			}
			printf("\n");
		}
	}
	return 0;
}
