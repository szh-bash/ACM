#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
char s[200];
int main(){
	scanf("%s", s);
	int ls=strlen(s), ans=0;
	for (int i=0;i<ls;i++)
		if (s[i]=='Q')
			for (int j=i+1;j<ls;j++)
				if (s[j]=='A')
				for (int k=j+1;k<ls;k++)
					if (s[k]=='Q') ans++;
	cout<<ans<<endl;
	return 0;
}
