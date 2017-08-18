#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
char s[1000];
int main(){
	int tot=0;
	scanf("%s", s);
	int ls=strlen(s);
	for (int i=0;i<ls;i++)
		if (s[i]!=s[ls-i-1]) tot++;
	if (!tot && ls%2==0) {cout<<"NO"<<endl;return 0;}
	if (tot<=2) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
