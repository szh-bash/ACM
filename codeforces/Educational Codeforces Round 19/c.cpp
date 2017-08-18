#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
char s[110000], ans[110000];
int ls, a[100], b[110000], d[110000], top, cnt;
int main(){
	scanf("%s", s);
	ls=strlen(s);
	for (int i=0;i<ls;i++)
		a[s[i]-'a']++;
	int j=0;
	for (int i=0;i<ls;i++){
		b[++top]=s[i]-'a';
		d[s[i]-'a']++;
		while (j<26 && !a[j]) j++;
		while (j<26 && top && b[top]<=j){
			d[b[top]]--;
			ans[cnt++]=b[top]+'a';
			a[b[top--]]--;
			while (j<26 && ((!a[j])||(d[j]==a[j] && b[top]!=j))) j++;
		}
	}
	for (int i=0;i<cnt;i++) printf("%c", ans[i]);
	while (top) printf("%c", b[top--]+'a');
	return 0;
}
