#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int ls, f[1000100], p[1000100];
char s[1000100];
int main(){
	scanf("%d %s", &ls, s+1);
	int j=0;
	long long ans=0;
	f[1]=1;
	for (int i=2;i<=ls;i++){
		while (j && s[j+1]!=s[i]) j=p[j];
		(p[i]=j+=(s[j+1]==s[i]))?f[i]=f[p[i]]:f[i]=i;
		if (f[i]*2<=i) ans+=i-f[i]; 
	}
	cout<<ans<<endl;
	return 0;
}
