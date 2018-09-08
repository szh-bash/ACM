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
char s[200];
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
	scanf("%s", s);
	int n=strlen(s);
	for (int i=1;i<n-1;i++)
		if (s[i-1]!='.' && s[i]!='.' && s[i+1]!='.' && s[i-1]!=s[i] && s[i]!=s[i+1] && s[i-1]!=s[i+1]){
			cout<<"Yes"<<endl;
			return 0;
		}
	cout<<"No"<<endl;
	return 0;
}
