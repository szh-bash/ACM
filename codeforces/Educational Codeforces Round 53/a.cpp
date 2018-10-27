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
int n;
char s[2000];
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
	cin>>n;
	scanf("%s",s);
	for (int i=0;i<n-1;i++)
		if (s[i]!=s[i+1]){
			cout<<"YES"<<endl;
			cout<<s[i]<<s[i+1]<<endl;
			return 0;
		}
	cout<<"NO"<<endl;
	return 0;
}
