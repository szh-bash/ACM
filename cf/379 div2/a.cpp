#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, a, b;
char s[111000];
int main(){
	cin>>n;
	scanf("%s", s);
	for (int i=0;i<n;i++)
		if (s[i]=='A') a++;else b++;
	if (a>b) cout<<"Anton"<<endl;
	if (a==b) cout<<"Friendship"<<endl;
	if (a<b) cout<<"Danik"<<endl;
	return 0;
}
