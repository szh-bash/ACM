#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int m, ans, p[20000], g[20000];
char s[20000];
int main(){
	scanf("%s", s);
	int len=strlen(s);
	cin>>m;
	for (int i=len;i;i--) s[i]=s[i-1];
	s[++len]='\0';
	int k=0;
	for (int i=1;i<len;i++){
		p[i]=i-1;g[i]=i;
		k=i-1;
		for (int j=i+1;j<len;j++){
			while (k!=i-1 && s[k+1]!=s[j]) k=p[k];
			if (s[k+1]==s[j]) ++k;p[j]=k;
			g[j]=(k<i+m-1)?j:g[k];
			if (g[j]<(i+j>>1)) ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
