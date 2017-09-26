#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, f[200], ans;
char s[2000];
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') (ch=='-'?q=-1:0), ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
int main(){
	int le=0, tot=0;
	n=read();
	scanf("%s", s+1);
	for (int i=1;i<=n;i++)
		if (s[i]>='A' && s[i]<='Z'){
			ans=max(ans,tot);
			for (int j='a';j<='z';j++)
				f[j]=0;
			tot=0;
		}
		else{
			if (!f[s[i]]) tot++;
			f[s[i]]=1;
		}
	ans=max(ans,tot);
	cout<<ans<<endl;
	return 0;
}
