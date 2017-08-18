#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, tot, cnt, a[10000], ls, k;
char s[110][1000], tmp[1000], ans[1000];
int main(){
	cin>>n>>k;
	for (int i=1;i<=n;i++)
		scanf("%s",s[i]);
	scanf("%s", ans);
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			if (strlen(s[j])<strlen(s[i])){
			swap(s[i],s[j]);
			}
	ls=strlen(ans);
	for (int i=1;i<=n;i++)
		if (strlen(s[i])==ls){
			cout<<((i-1)/k)*5+i<<' ';
			break;
		}
	for (int i=n;i;i--)
		if (strlen(s[i])==ls){
			cout<<((i-1)/k)*5+i<<endl;
			break;
		}
	return 0;
}
