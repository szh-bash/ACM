#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
int k, n, l[20000], p[20000], ans;
char s[20000];
void work(int st){
	memset(p,0,sizeof(p));
	memset(l,0,sizeof(l));
	p[st]=st-1;
	int j=st-1;
	for (int i=st+1;i<=n;i++){
		while (j>st-1 && s[j+1]!=s[i]) j=p[j];
		if (s[j+1]==s[i]) j++;
		p[i]=j;
		//cout<<p[i]<<' ';
		if (l[p[i]]-st>=k-1) l[i]=l[p[i]];
			else l[i]=p[i];
		if ((l[i]-st>=k-1) && (i-st+1-2*(l[i]-st+1)>0)) ans++;
		//cout<<l[i]<<' ';
		//cout<<ans<<' ';
	}
	cout<<ans<<endl;
}
int main(){
	scanf("%s", s);
	scanf("%d", &k);
	n=strlen(s);
	for (int i=n;i;i--) s[i]=s[i-1];
	for (int i=1;i+k*2<=n;i++) work(i);
	printf("%d\n", ans);
	system("pause");
	return 0;
}
