#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, tot, cnt, a[10000];
char s[10000];
int main(){
	cin>>n;
	scanf("%s",s);
	for (int i=0;i<n;i++)
		if (s[i]=='W' && tot){
			a[++cnt]=tot;
			tot=0;
		}
		else
			if (s[i]=='B') tot++;
	if (tot) a[++cnt]=tot;
	cout<<cnt<<endl;
	for (int i=1;i<=cnt;i++) cout<<a[i]<<' ';
	cout<<endl;
	return 0;
}
