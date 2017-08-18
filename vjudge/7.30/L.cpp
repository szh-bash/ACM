#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
char s[15];
int n;
int main(){
	cin>>n;
	int ans=0,p=1;
	for (int i=1;i<=n;i++){
		scanf("%s", &s);
		if (s[0]=='A' || s[0]=='P' || s[0]=='R' || s[0]=='O'){
			ans+=abs(p-1);
			p=1;
		}
		else
		if (s[0]=='B' || s[0]=='M' || s[0]=='S'){
			ans+=abs(p-2);
			p=2;
		}
		else{
			ans+=abs(p-3);
			p=3;
		}
	}
	cout<<ans<<endl;
	return 0;
}
