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
#define N 10000
typedef long long ll;
using namespace std;
int n, p;
char s[N];
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') 
		ch=='-'?q=-1:0,
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
void print(){
	for (int i=0;i<n;i++)
		if (s[i]=='.') s[i]='0';
	cout<<s<<endl;
}
int main(){
	n=read();p=read();
	scanf("%s", s);
	for (int i=0;i+p<n;i++)
		if (s[i]!='.' && s[i+p]!='.'){
			if (s[i]==s[i+p]) continue;
			print();
			return 0;
		}
		else
			if (s[i]=='.' && s[i+p]=='.'){
				s[i]='1';
				s[i+p]=='0';
				print();
				return 0;
			}
			else{
				if (s[i+p]=='.')
					if (s[i]=='0') s[i+p]='1';else s[i+p]='0';
				else
					if (s[i+p]=='0') s[i]='1';else s[i]='0';
				print();
				return 0;
			}
	cout<<"No"<<endl;
	return 0;
}
