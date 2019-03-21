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
	n=read();a=read();b=read();
	scanf("%s", s+1);
	for (int i=2, j=0;i<=n;i++){
		while (j && s[j+1]!=s[i]) j=p[j];
		if (s[j+1]==s[i]) ++j;
		p[i]=j;
	}
	for (int i=1;i<=n;i++)
		f[i]=min(f[i-1]+min(a,b)
	cout<<f[n]<<endl;
	return 0;
}
