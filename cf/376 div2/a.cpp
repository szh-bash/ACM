#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int main(){
	char s[1000];
	scanf("%s", s);
	int a='a',ans=0;
	for (int i=0;i<strlen(s);i++){
		ans+=min(abs(s[i]-a),26-abs(s[i]-a));
		a=s[i];
	}
	cout<<ans<<endl;
	return 0;
}
