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
char s[1000][1000];
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
	int n=read(), ans=0;
	for (int i=1;i<=n;i++) scanf("%s",s[i]+1);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (s[i][j]=='X' && s[i-1][j-1]=='X' && s[i-1][j+1]=='X'
				&& s[i+1][j-1]=='X' && s[i+1][j+1]=='X') ans++;
	cout<<ans<<endl; 
	return 0;
}
