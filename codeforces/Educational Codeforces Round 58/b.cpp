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
char s[500100];
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
	scanf("%s",s);
	int ls=strlen(s);
	int indexl, indexr;
	int flag0=0, flag1=0, flag2=0, flag3=0;
	int ans=0;
	for (int i=0;i<ls;i++){
		if (s[i]=='[' && !flag0) flag0=1, ans++;
		if (s[i]==':' && flag0 && !flag1) flag1=1, ans++, indexl=i;
	}
	for (int j=ls-1;j>=0;j--){
		if (s[j]==']' && !flag2) flag2=1, ans++;
		if (s[j]==':' && flag2 && !flag3) flag3=1, ans++, indexr=j;
	}
	if (flag0 && flag1 && flag2 && flag3 && indexr!=indexl){
		for (int i=indexl;i<indexr;i++)
			if (s[i]=='|') ans++;
		cout<<ans<<endl;
	}
	else{
		cout<<-1<<endl;
	}
	return 0;
}
