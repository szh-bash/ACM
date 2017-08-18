#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define mo 1000000007
using namespace std;
char s[1100000];
int ans, tot;
int main(){
	scanf("%s", s);
	int len=strlen(s);
	for (int i=len-1;i>=0;i--){
		if (s[i]=='b') tot++;
		else{
			ans=(ans+tot)%mo;
			tot=tot*2%mo;
		}
	}
	cout<<ans<<endl;
	return 0;
}
