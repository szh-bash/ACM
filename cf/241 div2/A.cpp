#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int main(){
	int n, x, l=-2000000000, r=2000000000;
	char c1, c2;
	scanf("%d", &n);getchar();
	for (int i=1;i<=n;i++){
		c1=getchar();c2=getchar();
		scanf("%d", &x);
		if (c2==' '){
			c2=getchar();c2=getchar();getchar();
			if (c2=='Y'){
				if (c1=='>') l=max(l-1,x)+1;
				else r=min(r+1,x)-1;
			}
			else{
				if (c1=='>') r=min(r,x);
				else l=max(l,x);
			}
		}
		else{
			c2=getchar();c2=getchar();getchar();
			if (c2=='Y'){
				if (c1=='<') r=min(r,x);
				else l=max(l,x);
			}
			else{
				if (c1=='<') l=max(l-1,x)+1;
				else r=min(r+1,x)-1;
			}
		}
		if (l>r) cout<<"Impossible"<<endl,exit(0);
	}
	cout<<l<<endl;
	return 0;
}
