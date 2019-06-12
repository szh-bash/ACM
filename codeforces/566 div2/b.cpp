#include <map>
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
int n, m;
char s[1000][1000];
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
	n=read();
	m=read();
	int tot=0;
	for (int i=1;i<=n;i++){
		scanf("%s", s[i]+1);
		for (int j=1;j<=m;j++) tot+=s[i][j]=='*';
	}
	for (int i=2;i<n;i++)
		for (int j=2;j<m;j++)
			if (s[i][j]=='*' && s[i-1][j]=='*' && s[i][j+1]=='*' && s[i+1][j]=='*' && s[i][j-1]=='*'){
				for (int k=1;i-k;k++)
					if (s[i-k][j]=='*') tot--;
					else break;
				for (int k=1;j+k;k++)
					if (s[i][j+k]=='*') tot--;
					else break;
				for (int k=1;i+k;k++)
					if (s[i+k][j]=='*') tot--;
					else break;
				for (int k=1;j-k;k++)
					if (s[i][j-k]=='*') tot--;
					else break;
				if (--tot) {
					cout<<"NO"<<endl;
					return 0;
				}
				else{
					cout<<"YES"<<endl;
					return 0;
				}
			}
	cout<<"NO"<<endl;
	return 0;
}
