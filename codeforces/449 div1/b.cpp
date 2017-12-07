#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, m, c, c0, tot, a[2000];
int main(){
	cin>>n>>m>>c0;
	c=(c0+1)>>1;
	for (int i=1;i<=n/2;i++) a[i]=2000;
	for (int i=n/2+1;i<=n;i++) a[i]=0;
	while (1){
		int flag=0, x;
		scanf("%d", &x);
		if (c0==1){
			tot++;
			printf("%d\n", tot);
			fflush(stdout);
			if (tot==n) return 0;
			continue;
		}
		if (x<=c){
			for (int i=1;i<=n/2;i++)
				if (a[i]>x){
					if (a[i]==2000) tot++;
					a[i]=x;
					printf("%d\n", i);
					fflush(stdout);
					flag=1;
					break;
				}
			if (tot==n) return 0;
			if (flag) continue;
			for (int i=n;i>=n/2+1;i--)
				if (a[i]<x){
					if (!a[i]) tot++;
					a[i]=x;
					printf("%d\n", i);
					fflush(stdout);
					flag=1;
					break;
				}
			if (tot==n) return 0;
		}
		else{
			for (int i=n;i>=n/2+1;i--)
				if (a[i]<x){
					if (!a[i]) tot++;
					a[i]=x;
					printf("%d\n", i);
					fflush(stdout);
					flag=1;
					break;
				}
			if (tot==n) return 0;
			if (flag) continue;
			for (int i=1;i<=n/2;i++)
				if (a[i]>x){
					if (a[i]==2000) tot++;
					a[i]=x;
					printf("%d\n", i);
					fflush(stdout);
					flag=1;
					break;
				}
			if (tot==n) return 0;
		}
	}
	return 0;
}
