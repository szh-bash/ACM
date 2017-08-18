#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespaces std;
int n, q, len;
char s[210000];
int main(){
	cin>>n>>q;
	scanf("%s", s);
	len=strlen(s);
	f[0][s[0]-'0']=1;
	for (int i=1;i<len;i++){
		f[i][0]=f[i-1][0];
		f[i][1]=f[i-1][1];
		f[i][2]=f[i-1][2];
		f[i][6]=f[i-1][6];
		f[i][7]=f[i-1][7];
		if (s[i]=='2') f[i][2]++;
		if (s[i]=='0') f[i][0]+=f[i-1][2];
		if (s[i]=='1') f[i][1]+=f[i-1][0];
		if (s[i]=='6') f[i][6]+=f[i-1][0];
		if (s[i]=='7') f[i][7]+=f[i-1][7];
	}
	return 0;
}
