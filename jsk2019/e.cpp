#include <map>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 2000000
using namespace std;
int n, len;
char s[N], ss[N];
int main(){
	scanf("%s", s);
	len=strlen(s);
	strcpy(ss,s);
	for (int i=len-1;i>=0;i--){
		if (s[i]=='(') tot++;
		if (s[i]==')') tot--;
		
	}
	return 0;
}
