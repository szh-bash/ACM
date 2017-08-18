#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, cnt;
char s[110], ch[110];
int main(){
	scanf("%d", &n);
	scanf("%s", s);
	cnt=-1;
	for (int i=0;i<n;i++)
		if (s[i]=='o' && s[i+1]=='g' && s[i+2]=='o'){
			ch[cnt+1]=ch[cnt+2]=ch[cnt+3]='*';
			i+=2;
			while (s[i+1]=='g' && s[i+2]=='o') i+=2;
			cnt+=3;
		}
		else ch[++cnt]=s[i];
	printf("%s", ch);
	return 0;
}

