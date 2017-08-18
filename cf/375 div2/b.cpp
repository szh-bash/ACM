#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
int n, ans1, ans2, tot, flag;
char s[3000];
int main(){
	cin>>n;
	scanf("%s", s);
	s[n++]='_';
	for (int i=0;i<=n;i++){
		if ((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z')) tot++;
		else{
			if (flag)
				ans2+=tot>0, tot=0;
			else
				ans1=max(ans1,tot), tot=0;
			if (s[i]=='(') flag^=1;
			if (s[i]==')') flag^=1;
		}
	}
	cout<<ans1<<' '<<ans2<<endl;
	return 0;
}
