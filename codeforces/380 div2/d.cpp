#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, a, b, k, ls, ans[300000], tot;
char s[300000];
int main(){
	cin>>n>>a>>b>>k;
	scanf("%s", s);
	ls=strlen(s);
	s[ls++]='1';
	for (int i=0;i<ls;i++)
		if (s[i]=='0') tot++;
		else{
				for (int j=i-b;(i-j)<=tot;j-=b)
				 	ans[++ans[0]]=j;
				tot=0;
			}
	cout<<ans[0]-a+1<<endl;
	for (int i=1;i<=ans[0]-a+1;i++)
		printf("%d ", ans[i]+1);
	cout<<endl;
	return 0;
}

