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
char s[2000];
int n;
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
		scanf("%s", s);
		n=strlen(s);
		int flag=0, i;
		for (i=1;i<n;i++)
			if (s[i]!=s[i-1]) {flag=1;break;}
		if (flag){
			for (int j=i;j<n;j++) printf("%c", s[j]);
			for (int j=0;j<i;j++) printf("%c", s[j]);
			printf("\n");
		}
		else printf("-1\n");
	}
	return 0;
}
