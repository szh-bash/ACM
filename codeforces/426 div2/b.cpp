#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define la 65
#define lz 90
using namespace std;
int n, k, f[2000000], mi[200], ma[200];
char s[2000000];
int read(){
	int p=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
int main(){
	n=read();k=read();
	scanf("%s", s);
	for (int i=la;i<=lz;i++)
		mi[i]=n+1, ma[i]=-1;
	for (int i=0;i<n;i++)
		mi[s[i]]=min(mi[s[i]],i),
		ma[s[i]]=max(ma[s[i]],i);
	for (int i=la;i<=lz;i++)
	if (ma[i]>=0){
		f[mi[i]]++;
		f[ma[i]+1]--;
	}
	int t=0;
	for (int i=0;i<n;i++){
		t+=f[i];
		if (t>k){
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}

