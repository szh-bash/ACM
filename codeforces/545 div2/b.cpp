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
int a[10000], b[10000];
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
	int ct=0;
	n=read();
	scanf("%s",s+1);
	for (int i=1;i<=n;i++) a[i]=s[i]-'0';
	scanf("%s", s+1);
	for (int i=1;i<=n;i++) b[i]=s[i]-'0';
	int fc=0, fa=0, fb=0;
	for (int i=1;i<=n;i++)
		if (a[i] && b[i]) fc++;
		else if (a[i] && !b[i]) fa++;
		else if (!a[i] && b[i]) fb++;
	for (int i=1;i<=n/2;i++){
		if (i*2>fa+fb+fc) break;
		for (int j=1;j<=fc;j++)
			if (j+fa>=i && fc-j+fb>=i && fc-j<=i && (n-fa-fb-fc>=abs(j+fa-i-(fc-j+fb-i)))
				&& (n-fa-fb-fc+j+fa-i+fc-j+fb-i)%2==0){
					int ta=fa, tb=fb, tc=fc;
					for (int k=1;k<=n;k++)
						if (a[k] && b[k] && (tc--)>fc-j ||
							a[k] && !b[k] && ||
							!a[k] && b[k] && ||
							!a[k] && !b[k] && )
					return 0; 
				}
	}
	puts("-1");
	return 0;
}
