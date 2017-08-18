#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int f[50];
char s[200000];
int main(){
	gets(s);
	int ls=strlen(s), flag=0;
	f[0]=f[7]=f[8]=f[12]=f[14]=f[19]=f[20]=f[21]=f[22]=f[23]=f[24]=1;
	for (int i=0;i<(ls+1)/2;i++)
		if (s[i]!=s[ls-i-1] || !f[s[i]-'A']){flag=1;break;}
	if (!flag) cout<<"YES"<<endl;else cout<<"NO"<<endl;
	return 0;
}
