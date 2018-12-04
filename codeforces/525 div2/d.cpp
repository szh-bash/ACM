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
int bit[33], s0, s1, s2;
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
	bit[0]=1;
	for (int i=1;i<=30;i++) bit[i]=bit[i-1]<<1;
	int tp0=0, tp1=0;
	printf("? %d %d\n", 0, 0);
	fflush(stdout);
	scanf("%d", &s0);
	for (int i=30-1;i>=0;i--){
		int u=tp0*bit[i+1], v=tp1*bit[i+1];
		u+=bit[i];
		printf("? %d %d\n", u, v);
		fflush(stdout);
		scanf("%d", &s1);
		
		v+=bit[i];
		printf("? %d %d \n", u, v);
		fflush(stdout);
		scanf("%d", &s2);
		if (s0!=s2){
			//a[i]!=b[i]
			if (s0>0){
				//a[i]==1
				tp0=(tp0<<1)+1;
				tp1<<=1;
			}
			else{
				//b[i]==1;
				tp0<<=1;
				tp1=(tp1<<1)+1;
			}
			s0=s1;
		}
		else{
			//a[i]==b[i]
			if (s0>0){
				if (s1>0){
					//a[i]==0
					tp0<<=1;
					tp1<<=1;
				}
				else{
					//a[i]==1
					tp0=(tp0<<1)+1;
					tp1=(tp1<<1)+1;
				}
			}
			else{
				if (s1<0){
					//a[i]==1
					tp0=(tp0<<1)+1;
					tp1=(tp1<<1)+1;
				}
				else{
					tp0<<=1;
					tp1<<=1;
				}
			}
		}
	}
	printf("! %d %d\n", tp0, tp1);
	fflush(stdout);
	return 0;
}
