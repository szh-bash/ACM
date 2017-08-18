
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, a, b, ans;
char s[200000];
int main(){
	cin>>n>>a>>b;
	scanf("%s", s);
	if (s[a-1]==s[b-1]){
		cout<<0<<endl;
		return 0;
	}
	ans=n;
	a=b=999999;
	for (int i=0;i<n;i++){
		if (s[i]=='0') a=i;
		else b=i; 
		ans=min(ans,abs(a-b));
	}
	cout<<ans<<endl;
	return 0;
}
