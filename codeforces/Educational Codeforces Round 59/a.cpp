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
char s[10000];
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
	for (int _=read();_;_--){
		int n=read();
		scanf("%s", s);
		if (n>2){
			printf("YES\n2\n%c %s\n", s[0], s+1);
		}
		else{
			int p=s[0]-'0', q=0;
			for (int i=1;i<n;i++) q=q*10+s[i]-'0';
			if (p<q){
				printf("YES\n2\n%d %d\n",p,q);
			}
			else printf("NO\n");
		}
	}
	return 0;
}
