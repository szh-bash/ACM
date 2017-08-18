#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, t, lx, a[201000];
char s[201000];
int main(){
	cin>>n>>t;
	scanf("%s", s);
	for (int i=1;i<n;i++)
		if (s[i]=='.'){
			lx=i;
			for (int j=i+1;j<n;j++)
				s[j-1]=s[j];
			break;
		}
	n--;
	for (int i=0;i<n;i++) a[i]=s[i]-'0';
	int j=n-1;
	for (int i=lx;i<n;i++)
		if (a[i]>4) {j=i;break;}
	while ((a[j]>4) && (t) && (j>=lx)){
		if (a[j]==10){
			a[--j]++;
			continue;
		}
		t--;
		a[j-1]=a[j-1]+1;
		j--;
	}
	int k=j;
	while (a[k]==10 && k){
		a[k]=0;
		a[--k]++;
	}
	for (int i=0;i<lx;i++) printf("%d",a[i]);
	if (j>=lx)cout<<'.';
	for (int i=lx;i<=j;i++) printf("%d", a[i]);
	return 0;
}
